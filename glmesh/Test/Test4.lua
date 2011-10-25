
dofile "../../links.lua"

function MakeDrawTest(filename)

	local name = filename:match("draw%_(.+)%.cpp")

	project(name)
		kind "ConsoleApp"
		language "c++"
		includedirs { "../include" }
		links {"glmesh"}
		
		UseLibs {"glfw", "glm", "glload", "glutil"}

		files {filename, "framework_draw.h", "framework_draw.cpp"}

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
end

local matches = os.matchfiles("draw_*.cpp");

for i, match in ipairs(matches) do
	MakeDrawTest(match);
end
