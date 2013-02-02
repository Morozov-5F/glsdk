
solution "glutil"
configurations {"Debug", "Release"}
defines(dofile("../common_defines.lua"))

dofile("glutil.lua");

dofile("Test/Test4.lua");
