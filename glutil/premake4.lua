
solution "glutil"
configurations {"Debug", "Release"}
defines {"_CRT_SECURE_NO_WARNINGS"}
defines {"_SCL_SECURE_NO_WARNINGS"}

dofile("glutil.lua");

dofile("Test/Test4.lua");
