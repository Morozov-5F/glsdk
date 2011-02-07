
project "Test"
	kind "WindowedApp"
	language "c++"
	flags { "WinMain" }
	defines {"WIN32"}
	targetdir "lib"
	links "opengl"

	files {
		"windows.cpp",
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

