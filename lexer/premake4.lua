dofile("../boost_include.lua")

solution "lexer"
	configurations {"Debug", "Release"}
	defines(dofile("../common_defines.lua"))

dofile("../links.lua")


project "Lex"
	kind "ConsoleApp"
	language "c++"
	includedirs { "../include" }
	
	UseLibs {"boost", "glm"}

	files {"lex.cpp", "pch.h", "pch.cpp"}
	
	pchheader "pch.h"
	pchsource "pch.cpp"

	configuration "windows"
		buildoptions {"-Zm256"};


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
