--[[
This script downloads all of the external dependencies and unzips them to the proper directory. You will need to have 7z in your path to run this, as well as the LuaSocket, UFS, and EX Lua modules.
]]

local io = require("io")
local http = require("socket.http")
local ltn12 = require("ltn12")
require("ex")
require "ufs"
require "_FindFileInPath"


local externals =
{
	{
		"FreeGLUT 2.6.0",	--The name of the component.
		"freeglut",	--The output directory to copy the component's data.
		"freeglut.tar.gz",	--The filename that will be created in the download director.
		"freeglut-2.6.0",	--If the zip file has a base directory, then name it here. If it doesn't, then just use ""
		"https://downloads.sourceforge.net/project/freeglut/freeglut/freeglut-2.6.0.tar.gz?r=&ts=1315279369&use_mirror=cdnetworks-us-2" --URL to download.
	},
	{
		"GLFW 2.7.2",	--The name of the component.
		"glfw",			--The output directory to copy the component's data.
		"glfw.zip",		--The filename that will be created in the download director.
		"glfw-2.7.2",	--If the zip file has a base directory, then name it here. If it doesn't, then just use ""
		"https://downloads.sourceforge.net/project/glfw/glfw/2.7.2/glfw-2.7.2.zip?r=&ts=1354407512&use_mirror=iweb"
	},
	
	{
		"GLM 0.9.4.0",	--The name of the component.
		"glm",			--The output directory to copy the component's data.
		"glm.7z",		--The filename that will be created in the download director.
		"",	--If the zip file has a base directory, then name it here. If it doesn't, then just use ""
		[[https://downloads.sourceforge.net/project/ogl-math/glm-0.9.4.0/glm-0.9.4.0.7z?r=&ts=1354407389&use_mirror=iweb]]
	},

	{
		"glLoadGen 1.0.3",	--The name of the component.
		"glloadgen",		--The output directory to copy the component's data.
		"glloadgen.7z",		--The filename that will be created in the download director.
		"glLoadGen_1_0_3",	--If the zip file has a base directory, then name it here. If it doesn't, then just use ""
		[[https://sourceforge.net/projects/glsdk/files/glLoadGen/glLoadGen_1_0_3.7z/download?use_mirror=superb-dca2]]
	},
}

local zipFullName = FindFileInPath("7z.exe");

if(zipFullName == nil) then
	return
end

local function RecursiveCopy(fromDir, toDir)
	for entry in ufs.directory_iterator(fromDir) do
		local es = entry:status();
		local srcPath = entry:path();
		
		local pathDestName = toDir / srcPath:filename();
		if(ufs.is_regular_file(es)) then
			ufs.copy_file(srcPath, pathDestName, ufs.copy_option_overwrite_if_exists);
		end
		
		if(ufs.is_directory(es)) then
			local bDidCreate, ec = ufs.create_directory(pathDestName);
			RecursiveCopy(srcPath, pathDestName);
		end
	end
end

local decompressDir = ".\\extract";
ufs.create_directory(ufs.path(decompressDir));

for i, ext in ipairs(externals) do
	print("Downloading: " .. ext[1]);
	
	local compressFile = decompressDir .. "\\" .. ext[3];
	
	local hFile = assert(io.open(compressFile, "wb"));
	http.request {url = ext[5], sink = ltn12.sink.file(hFile)}
	
	local unzipDir = decompressDir .. "\\dir" .. i;
	ufs.create_directory(ufs.path(unzipDir));
	
	print("Extracting: " .. ext[1]);
	if(ext[3]:match("%.tar%.gz$")) then
		local proc = ex.spawn(zipFullName, {
			args={"x", "-y", "-o" .. decompressDir, compressFile},
			});
			
		local tarFile = compressFile:match("(.+)%.gz$");
		proc:wait(proc);

		proc = ex.spawn(zipFullName, {
			args={"x", "-y", "-o" .. unzipDir, tarFile},
			});
		proc:wait(proc);
	else
		proc = ex.spawn(zipFullName, {
			args={"x", "-y", "-o" .. unzipDir, compressFile},
			});
		proc:wait(proc);
	end
	
	print("Copying: " .. ext[1]);
	local pathSrc = ufs.path(unzipDir);
	if(#ext[4] ~= 0) then
		pathSrc = pathSrc / ext[4]
	end

	local pathOut = ufs.path(".\\" .. ext[2]);
	ufs.create_directory(pathOut);
	if(not ufs.exists(pathSrc)) then
		error("Unknown source directory: " .. tostring(pathSrc))
	end
	RecursiveCopy(pathSrc, pathOut);
end

ufs.remove_all(ufs.path(decompressDir));


