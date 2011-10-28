--[[
Will automatically generate all files from the current sources.
Takes three parameters:
- The destination directory, as a relative directory. This will create that directory and put the distro in that directory
- The Mercurial revision number to archive to the destination directory.
- The version number of the SDK.
]]--

require "lfs"
require "_FindFileInPath"

local baseDir, hgChangelist, versionNum = ...

if(#({...}) ~= 3) then
	print("Not enough commandline parameters. You provided: " .. #({...}));
	print("Paramters:")
	print("\tDestination dir, relative to this path.")
	print("\tMercurial revision to archive.")
	print("\tVersion number of the SDK.")
	return
end

local buildDirname = "glsdk_" .. versionNum

lfs.mkdir(baseDir);
local pathDestDir = ufs.path(baseDir) / buildDirname;
local destDir = tostring(pathDestDir);
lfs.mkdir(destDir);

local pathCurrent = ufs.current_path()
local pathDest = pathCurrent / destDir;
local pathBase = pathCurrent / baseDir;

-----------------------------------------------------------
-- Step 1: Copy the Mercurial repo number to the location.

local clone = [[hg archive -r "%s" "%s"]];
clone = clone:format(hgChangelist, destDir);

print(clone);
os.execute(clone);

--------------------------------------------------------------
-- Step 2: Build the Doxygen documentation.
local pathDoxygen = pathDest / "docs";
local doxygenFilename = "doxygen174.exe"
local doxygenCfgName = "glsdk.cfg"

ufs.current_path(pathDoxygen);

local pathDoxygen = ufs.path(FindFileInPath(doxygenFilename));
if(pathDoxygen:empty()) then
	print("Could not find Doxygen.");
	return;
end

local doxProc = ex.spawn(tostring(pathDoxygen),
	{args={doxygenCfgName}});
doxProc:wait(doxProc);

---------------------------------------------------------------
-- Step 3: Apply Copyright Info
local luaFilename = "lua.exe"
local pathLua = ufs.path(FindFileInPath(luaFilename))
local luaCopyScriptName = "make_copyright.lua"

ufs.current_path(pathDest);

if(pathLua:empty()) then
	print("Could not find Lua. Since this is a Lua script, that's kinda confusing...");
	return;
end

local copyProc = ex.spawn(tostring(pathLua),
	{args={luaCopyScriptName}});
copyProc:wait(copyProc);

---------------------------------------------------------------
-- Step 4: Install the dependencies.
local luaDepScriptName = "get_externals.lua"

ufs.current_path(pathDest);

local depProc = ex.spawn(tostring(pathLua),
	{args={luaDepScriptName}});
depProc:wait(depProc);

------------------------------------------------------------
-- Step 5: Delete select files from the destination location.
local toDelete =
{
	--files
	"make_distro.lua", "get_externals.lua", ".hgignore", ".hgtags",
	"_FindFileInPath.lua", "make_copyright.lua",
	".hg_archival.txt",
	"glimg/premake4.lua", "glload/premake4.lua",
	"glutil/premake4.lua", "glmesh/premake4.lua",
	--directories
	"glimg/Test", "glload/Test",
	"glutil/Test", "glmesh/Test",
	"glm/doc/build",
	"caps",
}


for i, filename in ipairs(toDelete) do
	local pathFile = pathDest / filename;
	print("deleting:", pathFile);
	ufs.remove_all(pathFile);
end

------------------------------------------------------------
-- Step 6: Create Zip archive of the distro.
local szFilename = "7z.exe"
local archiveName = buildDirname .. ".7z"
local pathSZ = ufs.path(FindFileInPath(szFilename))

if(pathSZ:empty()) then
	print("Could not find 7zip.");
	return;
end

ufs.current_path(pathBase);

local depProc = ex.spawn(tostring(pathSZ),
	{args={"a", "-r", archiveName, buildDirname}});
depProc:wait(depProc);

------------------------------------------------------------
-- Step 7: Destroy the directory.
ufs.remove_all(pathDest);
