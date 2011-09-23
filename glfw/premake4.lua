solution "glfw"
	configurations {"Debug", "Release"}
	defines {"_CRT_SECURE_NO_WARNINGS", "_SCL_SECURE_NO_WARNINGS"}

dofile("glfw.lua");	

local scanDir = "examples"

local filelist = os.matchfiles(scanDir .. "/*.c")
for i, file in ipairs(filelist) do

	local basename = path.getbasename(file)
	
	if(basename ~= "getopt") then
		project(basename)
			location(scanDir)
			kind "ConsoleApp"
			language "c"
			includedirs {"include"}
			targetdir(scanDir)
			objdir(scanDir .. "/obj")
			files {file, scanDir .. "/getopt.c"};
			
--			defines {}
			links {"glfw"}
			
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
	end
end


