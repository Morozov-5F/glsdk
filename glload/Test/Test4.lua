
project "Test"
	kind "WindowedApp"
	language "c++"
	includedirs { "../include" }
	links {"glload"}

	configuration "windows"
		flags { "WinMain" }
		defines {"WIN32"}
		files { "windows.cpp", }
		links { "OpenGL32" }

	configuration "linux"
		files { "linux.cpp", }
		links { "GL" }
	
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
	includedirs { "../include" }
	links {"glload"}

	configuration "windows"
		flags { "WinMain" }
		defines {"WIN32"}
		files { "windowspp.cpp", }
		links { "OpenGL32" }

	configuration "linux"
		files { "linuxpp.cpp", }
		links { "GL" }
	
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

