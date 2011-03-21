
project "Test"
	kind "WindowedApp"
	language "c++"
	flags { }
	includedirs { "../include" }
	targetdir "lib"
	links {"GL", "glload"}

	files {
		"linux.cpp",
	};
	
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

