
require "lfs"

local data = dofile("_locations.lua");

local function ConvertFile(fullpathname)
	local command = {};
	command[#command + 1] = "java"
	command[#command + 1] = "-cp"
	command[#command + 1] = "\"" .. table.concat({data.saxonFilepath}, ";") .. "\""
	command[#command + 1] = "com.icl.saxon.StyleSheet"
	command[#command + 1] = "-o"
	command[#command + 1] = "\"" .. fullpathname .. "\""
	command[#command + 1] = "\"" .. fullpathname .. "\""
	command[#command + 1] = "\"FixupFields.xsl\"";

	local finalCmd = table.concat(command, " ");
	print(finalCmd);
	print("");

	os.execute(finalCmd);
end

local filelist = {...};

if(#filelist ~= 0) then
	for i, file in ipairs(filelist) do
		ConvertFile(file);
	end
else
	local dirs = {"man2", "man3", "man4"}

	for i, directory in ipairs(dirs) do
		for path in lfs.dir(directory) do
			local fullpathname = directory .. "\\" .. path;
			if(lfs.attributes(fullpathname, "mode") == "file") then
				ConvertFile(fullpathname);
			end
		end
	end
end


