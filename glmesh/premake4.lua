
solution "glmesh"
configurations {"Debug", "Release"}
defines {"_CRT_SECURE_NO_WARNINGS"}
defines {"_SCL_SECURE_NO_WARNINGS"}

dofile("glmesh.lua");

dofile("Test/Test4.lua");
