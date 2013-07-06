dofile "../../links.lua"

project "Test"
	kind "ConsoleApp"
	language "c++"
	includedirs { "../include", "../../glload/include" }
	links {"glscene"}
	
	UseLibs {"glfw", "boost", "glm", "glutil", "glload", "glimage", "glmesh"}

	files {"main.cpp"}

	configuration "windows"
		defines {"WIN32"}
		links {"glu32", "opengl32", "gdi32", "winmm", "user32"}

	configuration "linux"
		links {"GL", "GLU", "Xrandr"}
	
	configuration "Debug"
		flags "Unicode";
		defines {"DEBUG", "_DEBUG", "MEMORY_DEBUGGING"};
		objdir "Debug";
		flags "Symbols";
	
	configuration "Release"
		defines {"NDEBUG", "RELEASE"};
		flags "Unicode";
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
		objdir "Release";

project "ParseTest"
	kind "ConsoleApp"
	language "c++"
	includedirs { "../include", "../../glload/include" }
	links {"glscene"}
	
	UseLibs {"glfw", "boost", "glm", "glutil", "glload", "glimage", "glmesh"}

	files {"parseTest.cpp"}

	configuration "windows"
		defines {"WIN32"}
		links {"glu32", "opengl32", "gdi32", "winmm", "user32"}

	configuration "linux"
		links {"GL", "GLU", "Xrandr"}
	
	configuration "Debug"
		flags "Unicode";
		defines {"DEBUG", "_DEBUG", "MEMORY_DEBUGGING"};
		objdir "Debug";
		flags "Symbols";
	
	configuration "Release"
		defines {"NDEBUG", "RELEASE"};
		flags "Unicode";
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
		objdir "Release";
