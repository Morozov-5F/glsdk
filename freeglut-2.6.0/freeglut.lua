
project "freeglut"
	kind "StaticLib"
	language "c"
	includedirs {"include"}
	targetdir "lib"
	files {"src/*.c"};
	
	defines {"FREEGLUT_STATIC", "_LIB", "FREEGLUT_LIB_PRAGMAS=0"}
	
	configuration "windows"
		defines "WIN32"
		
	configuration "Debug"
		targetsuffix "D"
		defines "_DEBUG"
		flags "Symbols"

	configuration "Release"
		defines "NDEBUG"
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
