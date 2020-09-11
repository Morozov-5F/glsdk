--[[
Will automatically generate all files from the current sources.
Takes three parameters:
- The destination directory, as a relative directory. This will create that directory and put the distro in that directory
- The Mercurial revision number to archive to the destination directory.
- The version number of the SDK.
]]--

require "lfs"

local baseDir, hgChangelist, versionNum = ...

if(#({...}) ~= 3) then
	print("Not enough commandline parameters. You provided: " .. #({...}));
	print("Paramters:")
	print("\tDestination dir, relative to this path.")
	print("\tMercurial revision to archive.")
	print("\tVersion number of the SDK.")
	return
end

local buildDirname = "glsdk_" .. versionNum:gsub("%.", "_")

lfs.mkdir(baseDir);
local pathDestDir = baseDir .. "/" .. buildDirname;
local destDir = tostring(pathDestDir);
lfs.mkdir(destDir);

local pathCurrent = lfs.currentdir()
local pathDest = pathCurrent .. "/" .. destDir;
local pathBase = pathCurrent .. "/" .. baseDir;

-----------------------------------------------------------
-- Step 1: Copy the Mercurial repo number to the location.

local clone = [[git archive --prefix "%s/" -o "%s.zip" HEAD]];
clone = clone:format(buildDirname, destDir);

print(clone);
os.execute(clone);

lfs.chdir(baseDir);
local archiveName = buildDirname .. ".zip";
os.execute("7za x " .. archiveName);
os.remove(archiveName)

--------------------------------------------------------------
-- Step 2: Build the Doxygen documentation.
local pathDoxygen = pathDest .. "/docs";
local doxygenFilename = "doxygen"
local doxygenCfgName = "glsdk_web.cfg"

print(pathDoxygen);
lfs.chdir(pathDoxygen);

do
	local hDoxyVersion = io.open("glsdk_version.cfg", "w+")
	hDoxyVersion:write("PROJECT_NUMBER = ", versionNum, "\n")
	hDoxyVersion:close()
end

os.execute(doxygenFilename .. " " .. doxygenCfgName);

---------------------------------------------------------------
-- Step 3: Apply Copyright Info
local luaFilename = "lua"
local luaCopyScriptName = "make_copyright.lua"

lfs.chdir(pathDest);

os.execute(luaFilename .. " " .. luaCopyScriptName);

---------------------------------------------------------------
-- Step 4: Install the dependencies.
local luaDepScriptName = "get_externals.lua"

lfs.chdir(pathDest);

os.execute(luaFilename .. " " .. luaDepScriptName);

------------------------------------------------------------
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

-- Step 5: Delete select files from the destination location.
local toDelete =
{
	--files
	"make_distro.lua", "get_externals.lua", ".hgignore", ".hgtags",
	"_FindFileInPath.lua", "make_copyright.lua", "extract_boost.lua",
	".hg_archival.txt",
	"glimg/premake4.lua", "glload/premake4.lua",
	"glutil/premake4.lua", "glmesh/premake4.lua",
	"freeglut/premake4.lua", "glfw/premake4.lua", 
	--directories
	"glimg/Test", "glload/Test",
	"glutil/Test", "glmesh/Test",
	"glm/doc/build",
	"glloadgen/docs", "glloadgen/test",
	"caps", "mesh_data"
}


for i, filename in ipairs(toDelete) do
	local pathFile = pathDest .. "/" .. filename;
	print("deleting:", pathFile);
	RecursiveDelete(pathFile);
end

------------------------------------------------------------
-- Step 6: Create Zip archive of the distro.
local szFilename = "7za"
local archiveName = buildDirname .. ".7z"

lfs.chdir(pathBase);

local depProc = os.execute(szFilename .. " a -r " .. archiveName .. " " .. buildDirname);

------------------------------------------------------------
-- Step 7: Destroy the directory.
RecursiveDelete(pathDest);
