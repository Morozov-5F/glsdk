local thisDirectory = os.getcwd();

function LinkToGLLoad()
	local prevDir = os.getcwd();
	os.chdir(thisDirectory);
	configuration {}

	includedirs "glload/include"
	libdirs "glload/lib"
	
	configuration "Debug"
		links {"glloadD"}
	
	configuration "Release"
		links {"glload"}
	
	configuration {}
	os.chdir(prevDir)
end

function LinkToGLImage()
	local prevDir = os.getcwd();
	os.chdir(thisDirectory);
	configuration {}

	includedirs "glimg/include"
	libdirs "glimg/lib"
	
	configuration "Debug"
		links {"glimgD"}
	
	configuration "Release"
		links {"glimg"}
	
	configuration {}
	os.chdir(prevDir)
end

function LinkToFreeGLUT()
	local prevDir = os.getcwd();
	os.chdir(thisDirectory);
	configuration {}

	includedirs "freeglut/include"
	libdirs "freeglut/lib"
	defines {"FREEGLUT_STATIC", "_LIB", "FREEGLUT_LIB_PRAGMAS=0"}
	
	configuration "Debug"
		links {"freeglutD"}
	
	configuration "Release"
		links {"freeglut"}
	
	configuration {}
	os.chdir(prevDir)
end
