--[[ The function, MakeExtCppHeaderFile, will create a C++ header file containing the enums, extension test values, and the list of function pointers.

It takes these parameters:
- the name of the output file. Without the path.
- the specData, as formatted by LoadLuaSpec.
- a string representing the target GL version to export. If nil, gets everything.
- a boolean. If true, means that this should output only the core stuff.
- an array of strings to write to the front of the header file.
]]

require "_util"
require "_makeHelpers"

local function WriteCoreCFunctions(hFile, core, specData,
									version, targetVersion, bIsCore)
	--Collate the functions we want to write.
	local funcs = {};
	for i, func in ipairs(core.funcs) do
		local bShouldWrite = true;
		if(bIsCore) then
			if(func.deprecated and
					(tonumber(func.deprecated) <= tonumber(targetVersion))) then
				bShouldWrite = false;
			end
		end
		
		--Exts don't start with "VERSION"; don't write extension
		--functions here. Write them in the extension
		if(func.category and not string.match(func.category, "^VERSION")) then
			bShouldWrite = false;
		end
		
		if(bShouldWrite) then
			table.insert(funcs, func);
		end
	end
	
	--Write the typedefs.
	for i, func in ipairs(funcs) do
		hFile:write(Make.GetCoreFuncPtrDecl(func, "gl", specData.typemap));
		hFile:write("\n");
	end
end

local function WriteExtCFunctions(hFile, ext, extName, specData)
	--Write the typedefs.
	for i, func in ipairs(ext.funcs) do
		if(specData.coreexts[extName]) then
			hFile:write(Make.GetCoreFuncPtrDecl(func, "gl", specData.typemap));
		else
			hFile:write(Make.GetFuncPtrDecl(func, "gl", specData.typemap));
		end
		hFile:write("\n");
	end
end

local function WriteCoreEnums(hFile, core, specData, version, targetVersion,
							bIsCore, writtenEnum)
	WriteFormatted(hFile, GetSectionHeading(string.format("Version: %s", version)));
	
	local bDidWrite = false;
	for i, enum in ipairs(core.enums) do
		local bShouldWrite = true;
		if(bIsCore) then
			if(enum.removed and (tonumber(enum.removed) <= tonumber(targetVersion))) then
				bShouldWrite = false;
			end
		end
		
		--We'll write it as an extension
		if(enum.extensions) then
			bShouldWrite = false;
			--TODO: Make this write something saying that it comes from the extension.
		end
		
		--Was previously written
		if(writtenEnum[enum.name]) then
			bShouldWrite = false;
			hFile:write("\t\t//", 
				Make.GetEnumeratorCpp(enum, specData.enumtable, "GL_"),
				" From: ",
				writtenEnum[enum.name],
				"\n");
			bDidWrite = true;
		end
		
		if(bShouldWrite) then
			hFile:write("\t\t",
				Make.GetEnumeratorCpp(enum, specData.enumtable, "GL_"),
				"\n");
			writtenEnum[enum.name] = version;
			bDidWrite = true;
		end
	end
	
	if(bDidWrite) then hFile:write("\n") end
end

local function WriteExtEnums(hFile, ext, extName, specData, writtenEnum)
	if(#ext.enums ~= 0) then
		WriteFormatted(hFile, GetSectionHeading(string.format("Extension: %s_%s",
			"GL_", extName)));
	end
		
	for i, enum in ipairs(ext.enums) do
		--Was previously written
		if(writtenEnum[enum.name]) then
			hFile:write("\t\t//",
				Make.GetEnumeratorCpp(enum, specData.enumtable, "GL_"),
				" From: ",
				writtenEnum[enum.name],
				"\n");
		else
			hFile:write("\t\t",
				Make.GetEnumeratorCpp(enum, specData.enumtable, "GL_"),
				"\n");
			writtenEnum[enum.name] = extName;
		end
	end
	
	if(#ext.enums ~= 0) then
		hFile:write("\n");
	end
end

local function WriteCoreFunctions(hFile, core, specData,
									version, targetVersion, bIsCore)
	--Collate the functions we want to write.
	local funcs = {};
	for i, func in ipairs(core.funcs) do
		local bShouldWrite = true;
		if(bIsCore) then
			if(func.deprecated and
					(tonumber(func.deprecated) <= tonumber(targetVersion))) then
				bShouldWrite = false;
			end
		end
		
		--Exts don't start with "VERSION"; don't write extension
		--functions here. Write them in the extension
		if(func.category and not string.match(func.category, "^VERSION")) then
			bShouldWrite = false;
		end
		
		if(bShouldWrite) then
			table.insert(funcs, func);
		end
	end
	
	--Write the inline functions.
	if(#funcs ~= 0) then
		WriteFormatted(hFile, GetSectionHeading(string.format("Version: %s", version)));
	end

	for i, func in ipairs(funcs) do
		hFile:write("\t",
			Make.GetFuncDefCpp(func, "gl", specData.typemap, true),
			"\n");
	end
	
	if(#funcs ~= 0) then
		hFile:write("\n");
	end
end

local function WriteExtFunctions(hFile, ext, extName, specData)
	if(#ext.funcs ~= 0) then
		WriteFormatted(hFile, GetSectionHeading(string.format("Extension: %s_%s",
			"GL_", extName)));
	end
	
	for i, func in ipairs(ext.funcs) do
		if(specData.coreexts[extName]) then
			hFile:write("\t",
				Make.GetFuncDefCpp(func, "gl", specData.typemap, true),
				"\n");
		else
			hFile:write("\t",
				Make.GetFuncDefCpp(func, "gl", specData.typemap, false),
				"\n");
		end
	end
	
	if(#ext.funcs ~= 0) then hFile:write("\n") end
end

function MakeExtCppHeaderFile(outFilename, specData,
							targetVersion, bIsCore, preceedData)
	local hFile = io.open(GetIncludePath() .. outFilename .. ".hpp", "w");
	if(not hFile) then
		print("Could not open the output file\"" .. GetIncludePath() .. outFilename .. "\".\n");
		return;
	end
	
	local defineName = string.upper(outFilename) .. "_HPP";
	
	hFile:write(GetFileIncludeGuardStart(defineName));
	hFile:write("\n");
	
	if(preceedData) then
		for i, preceed in ipairs(preceedData) do
			hFile:write(preceed);
			hFile:write("\n");
		end
	end
	
	--Write the passthru data.
	for i, passthru in ipairs(specData.funcData.passthru) do
		hFile:write(passthru);
		hFile:write("\n");
	end
	hFile:write("\n");

	hFile:write(GetExternCStart(), "\n");
	
	--Write all of the extension query variables.
	for i, extName in ipairs(specData.extensions) do
		hFile:write(Make.GetExtensionVarExtern(extName, "gl"));
		hFile:write("\n");
	end

	hFile:write("\n\n");

	--Process all of the cores, creating all of the function pointer varaibles for them.
	local coreVersions = dofile(GetDataFilePath() .. "listOfCoreVersions.lua");
	if(not targetVersion) then targetVersion = coreVersions[#coreVersions]; end;
	
	for i, version in ipairs(coreVersions) do
		if(tonumber(version) > tonumber(targetVersion)) then
			break;
		end

		if(specData.coredefs[version]) then
			WriteCoreCFunctions(hFile, specData.coredefs[version], specData,
				version, targetVersion, bIsCore);
		end
	end
	
	--Process all of the extensions, creating all of the function pointer varaibles for them.
	for extName, ext in sortPairs(specData.extdefs, CompLess) do
		WriteExtCFunctions(hFile, ext, extName, specData);
	end

	hFile:write(GetExternCEnd());
	
	hFile:write("\nnamespace gl\n{\n");

	hFile:write("\tenum\n\t{\n");
	--Now, generate the enumerators.
	local writtenEnum = {}
	
	for i, version in ipairs(coreVersions) do
		if(tonumber(version) > tonumber(targetVersion)) then
			break;
		end

		if(specData.coredefs[version]) then
			WriteCoreEnums(hFile, specData.coredefs[version], specData,
				version, targetVersion, bIsCore, writtenEnum);
		end
	end
	
	for extName, ext in sortPairs(specData.extdefs, CompLess) do
		WriteExtEnums(hFile, ext, extName, specData, writtenEnum);
	end
	
	hFile:write("\t};\n");
	
	--Write the C++ inline functions that call the C-functions.
	for i, version in ipairs(coreVersions) do
		if(tonumber(version) > tonumber(targetVersion)) then
			break;
		end

		if(specData.coredefs[version]) then
			WriteCoreFunctions(hFile, specData.coredefs[version], specData,
				version, targetVersion, bIsCore);
		end
	end
	
	for extName, ext in sortPairs(specData.extdefs, CompLess) do
		WriteExtFunctions(hFile, ext, extName, specData);
	end

	hFile:write("}\n\n");
	
	if(preceedData and preceedData.footer) then
		for i, footer in ipairs(preceedData.footer) do
			hFile:write(footer);
			hFile:write("\n");
		end
	end
	
	hFile:write(GetFileIncludeGuardEnd(defineName));
		hFile:close();
end

