dofile("../boost_include.lua")

solution "glmesh"
configurations {"Debug", "Release"}
defines(dofile("../common_defines.lua"))

dofile("glmesh.lua");

dofile("Test/Test4.lua");
