
project "glfw"
	kind "StaticLib"
	language "c"
	includedirs {"include", "lib"}
	targetdir "library"
	files {"lib/*.c"};
	
	defines {"_LIB"}
	
	configuration "windows"
		defines "WIN32"
		files {"lib/win32/*.c"};
		includedirs {"lib/win32"}
		
	configuration "Debug"
		targetsuffix "D"
		defines "_DEBUG"
		flags "Symbols"

	configuration "Release"
		defines "NDEBUG"
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
