
solution "glload"
configurations {"Debug", "Release"}
defines {"_CRT_SECURE_NO_WARNINGS"}
defines {"_SCL_SECURE_NO_WARNINGS"}

project("glload")
	kind "StaticLib"
	language "c++"
	includedirs {"include", "source"}
	targetdir "lib"
	defines {"WIN32"}

	files {
		"include/glload/*.h",
		"source/*.c",
		"source/*.cpp",
		"source/*.h",
	};

	configuration "Debug"
		flags "Unicode";
		defines {"DEBUG", "_DEBUG", "MEMORY_DEBUGGING"};
		objdir "Debug";
		flags "Symbols";
		targetname "glloadD";

	configuration "Release"
		defines {"NDEBUG", "RELEASE"};
		flags "Unicode";
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
		objdir "Release";
		targetname "glload"


dofile("test/Test4.lua");
