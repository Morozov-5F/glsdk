dofile "../../links.lua"

project "Test"
	kind "WindowedApp"
	language "c++"
	includedirs { "../include", "../../glload/include" }
	links {"glgraph"}
	
	UseLibs {"freeglut", "boost", "glutil", "glload", "glimg", "glmesh"}

	files {"main.cpp"}

	configuration "windows"
		defines {"WIN32"}
		links {"glu32", "opengl32", "gdi32", "winmm", "user32"}

	configuration "linux"
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
