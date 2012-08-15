dofile ("../links.lua")

solution "examples"
	configurations {"Debug", "Release"}
	defines {"_CRT_SECURE_NO_WARNINGS", "_SCL_SECURE_NO_WARNINGS"}

local function MergeTables(tbl1, tbl2)
	for i, val in ipairs(tbl2) do
		tbl1[#tbl1 + 1] = val
	end
end
	
local dirs = os.matchdirs("*")
local cwd = os.getcwd();
for i, currDir in ipairs(dirs) do
	local basename = path.getname(currDir)
	
	local filelist = {}
	MergeTables(filelist, os.matchfiles(currDir .. "/*.cpp"))
	MergeTables(filelist, os.matchfiles(currDir .. "/*.c"))
	
	if(#filelist ~= 0) then
		os.chdir(currDir);
		project(basename)
			kind "ConsoleApp"
			language "c++"
			objdir("obj")
			files {"*.cpp"}
			files {"*.c"}
			files {"*.hpp"}
			files {"*.h"}

			UseLibs {"glload", "glimage", "glutil", "glmesh",
				"glm", "freeglut", "glfw"}
			
			configuration "windows"
				defines "WIN32"
				links {"glu32", "opengl32", "gdi32", "winmm", "user32"}
				
		    configuration "linux"
		        links {"GL", "GLU", "Xrandr"}
				
			configuration "Debug"
				targetsuffix "D"
				defines "_DEBUG"
				flags "Symbols"

			configuration "Release"
				defines "NDEBUG"
				flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
				
		os.chdir(cwd);
	end
end
