solution "glsdk"
	configurations {"Debug", "Release"}
	defines {"_CRT_SECURE_NO_WARNINGS", "_SCL_SECURE_NO_WARNINGS"}

dofile("glload/glload.lua");
dofile("glimg/glimg.lua");
dofile("glfw/glfw.lua");
dofile("freeglut/freeglut.lua");
