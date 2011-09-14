dofile ("../links.lua")

solution "examples"
	configurations {"Debug", "Release"}
	defines {"_CRT_SECURE_NO_WARNINGS", "_SCL_SECURE_NO_WARNINGS"}

local dirs = os.matchdirs("*")
local cwd = os.getcwd();
for i, currDir in ipairs(dirs) do
	local basename = path.getname(currDir)
	
	local filelist = os.matchfiles(currDir .. "/*.cpp");
	
	if(#filelist ~= 0) then
		os.chdir(currDir);
		project(basename)
			kind "ConsoleApp"
			language "c++"
			objdir("obj")
			files {"*.cpp"}
			files {"*.hpp"}
			files {"*.h"}

			UseLibs {"glload", "glimage", "freeglut", "glfw"}
			
			configuration "windows"
				defines "WIN32"
				links {"glu32", "opengl32", "gdi32", "winmm", "user32"}
				
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
