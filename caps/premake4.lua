
solution "caps"

configurations {"Debug", "Release"}
defines {"_CRT_SECURE_NO_WARNINGS"}
defines {"_SCL_SECURE_NO_WARNINGS"}


project "caps"
	kind "ConsoleApp"
	language "c++"
	defines {"WIN32"}
	links {"opengl32"}
	includedirs {"../glload/include"}
	libdirs {"../glload/lib"}

	files "plat_windows.cpp";
	files "plat_windows.h";
	
	files {"main.cpp", "caps.cpp"};
	
	configuration "Debug"
		flags "Unicode";
		defines {"DEBUG", "_DEBUG", "MEMORY_DEBUGGING"};
		objdir "Debug";
		flags "Symbols";
		links {"glloadD"}

	
	configuration "Release"
		defines {"NDEBUG", "RELEASE"};
		flags "Unicode";
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
		objdir "Release";
		links {"glload"}

