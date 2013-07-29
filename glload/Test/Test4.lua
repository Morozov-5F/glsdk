
dofile "../../links.lua"

project "Test"
	kind "WindowedApp"
	language "c++"
	includedirs { "../include" }
	links {"glload"}
	
	UseLibs "freeglut"

	files { "test.cpp", }

	configuration "windows"
		defines {"WIN32"}
		links {"glu32", "opengl32", "gdi32", "winmm", "user32"}

	configuration "linux"
		links { "GL", "X11", "Xrandr", "pthread" }
	
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

project "TestPP"
	kind "WindowedApp"
	language "c++"
	includedirs { "../../boost" }
	includedirs { "../include" }
	links {"glload"}

	UseLibs "freeglut"

	files { "testpp.cpp", }

	configuration "windows"
		defines {"WIN32"}
		links {"glu32", "opengl32", "gdi32", "winmm", "user32"}

	configuration "linux"
		links { "GL", "X11", "Xrandr", "pthread" }
	
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

