dofile("../boost_include.lua")

solution "glload"
configurations {"Debug", "Release"}
defines(dofile("../common_defines.lua"))

dofile("glload.lua");

dofile("Test/Test4.lua");
