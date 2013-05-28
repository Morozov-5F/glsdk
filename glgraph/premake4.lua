dofile("../boost_include.lua")

solution "glscene"
configurations {"Debug", "Release"}
defines(dofile("../common_defines.lua"))

dofile("glscene.lua");

dofile("Test/Test4.lua");
