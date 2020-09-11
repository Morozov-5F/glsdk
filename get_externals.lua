--[[
This script downloads all of the external dependencies and unzips them to the proper directory. You will need to have 7z in your path to run this, as well as the LuaSocket, UFS, and EX Lua modules.
]]

local io = require("io")
local http = require("socket.http")
local ltn12 = require("ltn12")
local lfs = require("lfs")

local externals =
{
	{
		"FreeGLUT 2.6.0",	--The name of the component.
		"freeglut",	--The output directory to copy the component's data.
		"freeglut.tar.gz",	--The filename that will be created in the download director.
		"freeglut-2.6.0",	--If the zip file has a base directory, then name it here. If it doesn't, then just use ""
		"https://downloads.sourceforge.net/project/freeglut/freeglut/2.6.0/freeglut-2.6.0.tar.gz?r=&ts=1369510584&use_mirror=superb-dca2" --URL to download.
	},
	{
		"GLFW 2.7.2",	--The name of the component.
		"glfw",			--The output directory to copy the component's data.
		"glfw.zip",		--The filename that will be created in the download director.
		"glfw-2.7.2",	--If the zip file has a base directory, then name it here. If it doesn't, then just use ""
		"https://downloads.sourceforge.net/project/glfw/glfw/2.7.2/glfw-2.7.2.zip?r=&ts=1354407512&use_mirror=iweb"
	},
	
	{
		"GLM 0.9.4.3",	--The name of the component.
		"glm",			--The output directory to copy the component's data.
		"glm.7z",		--The filename that will be created in the download director.
		"glm-0.9.4.3",	--If the zip file has a base directory, then name it here. If it doesn't, then just use ""
		[[https://downloads.sourceforge.net/project/ogl-math/glm-0.9.4.3/glm-0.9.4.3.zip?r=http%3A%2F%2Fglm.g-truc.net%2F&ts=1375100142&use_mirror=iweb]]
	},

	{
		"glLoadGen 2.0",	--The name of the component.
		"glloadgen",		--The output directory to copy the component's data.
		"glloadgen.7z",		--The filename that will be created in the download director.
		"glLoadGen_2_0_2",	--If the zip file has a base directory, then name it here. If it doesn't, then just use ""
		[[https://downloads.sourceforge.net/project/glsdk/glLoadGen/glLoadGen_2_0_2.7z?r=&ts=1375308771&use_mirror=master]]
	},
}

local zipFullName = "7za"

local function RecursiveDelete(file)
	print("deleting: ", file);
	local attr = lfs.attributes(file);
	if attr == nil then
		print("warning: file doesn't exist; skipping");
		return
	end
	if attr.mode == "file" then
		os.remove(file);
	end
	if attr.mode == "directory" then
		for entry in lfs.dir(file) do
			if entry ~= "." and entry ~= ".." then
				RecursiveDelete(file..'/'..entry);
			end
		end
		lfs.rmdir(file);
	end
end

local function RecursiveCopy(fromDir, toDir)
	print(tostring(fromDir), tostring(toDir));
	for entry in lfs.dir(fromDir) do
		if entry ~= "." and entry ~= ".." then
			local f = fromDir..'/'..entry;
			local es = lfs.attributes(f)

			local pathDestName = toDir..'/'..entry;
			if (es.mode == "file") then
				local i = io.open(f, "rb");
				local o = io.open(pathDestName, "w+b");
				o:write(i:read("*a"));
				o:close();
				i:close();
			end

			if (es.mode == "directory") then
				lfs.mkdir(pathDestName);
				RecursiveCopy(f, pathDestName);
			end
		end
	end
end

local decompressDir = "./extract";
lfs.mkdir(decompressDir);

for i, ext in ipairs(externals) do
	print("Downloading: " .. ext[1]);
	
	local compressFile = decompressDir .. "/" .. ext[3];
	
	local hFile = assert(io.open(compressFile, "wb"));
	http.request {url = ext[5], sink = ltn12.sink.file(hFile)}
	
	local unzipDir = decompressDir .. "/dir" .. i;
	lfs.mkdir(unzipDir);
	
	print("Extracting: " .. ext[1]);
	if(ext[3]:match("%.tar%.gz$")) then
		os.execute(zipFullName .. " x -y -o" .. decompressDir .. " " .. compressFile)
			
		local tarFile = compressFile:match("(.+)%.gz$");
		os.execute(zipFullName .. " x -y -o" .. unzipDir .. " " .. tarFile);
	else
		local s = zipFullName.." x -y -o" .. unzipDir .. " " .. compressFile;
		print(s)
		proc = os.execute(s);
	end
	
	print("Copying: " .. ext[1]);
	local pathSrc = unzipDir;
	if(#ext[4] ~= 0) then
		pathSrc = pathSrc..'/'..ext[4]
	end

	--Copy to final directory.
	local pathOut = "./" .. ext[2];
	lfs.mkdir(pathOut);
	RecursiveCopy(pathSrc, pathOut);
	
	--Remove extraneous files/directories
	if(ext[6]) then
		for i, filename in ipairs(ext[6]) do
			local pathFile = pathOut..'/'..filename;
			print("deleting:", pathFile);
			RecursiveDelete(pathFile);
		end
	end
end

RecursiveDelete(decompressDir);