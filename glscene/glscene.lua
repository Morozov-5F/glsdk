
local function UsePch()
	files {"pch.cpp"}
	pchheader "source/pch.h"
	pchsource "source/pch.cpp"
	buildoptions {"-Zm384"};
end

project("glscene")
	kind "StaticLib"
	language "c++"
	includedirs {
		"include",
		"source",
		"../glload/include",
		"../glutil/include",
		"../glmesh/include",
		"../glm",
		BoostDir()}

	targetdir "lib"

	files {
		"include/glscene/*.h",
		"source/*.h",
		"source/*.cpp",
	}

	configuration "vs2008"
		UsePch()
	configuration "vs2010"
		UsePch()
	configuration "vs2012"
		UsePch()

	configuration "windows"
		defines {"WIN32"}
	
	configuration "linux"
	    defines {"LOAD_X11"}

	configuration "Debug"
		flags "Unicode"
		defines {"DEBUG", "_DEBUG", "MEMORY_DEBUGGING"}
		objdir "Debug"
		flags "Symbols"
		targetname "glsceneD"

	configuration "Release"
		defines {"NDEBUG", "RELEASE"}
		flags "Unicode"
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"}
		objdir "Release"
		targetname "glscene"
