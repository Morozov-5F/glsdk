
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
		
	configuration "linux"
	    defines {"_GLFW_USE_LINUX_JOYSTICKS", "_GLFW_HAS_XRANDR",
	        "_GLFW_HAS_PTHREAD", "_GLFW_HAS_SYSCONF", "_GLFW_HAS_SYSCTL",
	        "_GLFW_HAS_GLXGETPROCADDRESS"}
	    includedirs { "/usr/X11/include" }
		files {"lib/x11/*.c"};
		includedirs {"lib/x11"}
		
	configuration "Debug"
		targetsuffix "D"
		defines "_DEBUG"
		flags "Symbols"

	configuration "Release"
		defines "NDEBUG"
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
