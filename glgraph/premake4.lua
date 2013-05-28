dofile("../boost_include.lua")

solution "glgraph"
configurations {"Debug", "Release"}
defines(dofile("../common_defines.lua"))

dofile("glgraph.lua");

dofile("Test/Test4.lua");
