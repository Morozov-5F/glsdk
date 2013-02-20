dofile("../boost_include.lua")

solution "glimg"
configurations {"Debug", "Release"}
defines(dofile("../common_defines.lua"))

dofile("glimg.lua")
dofile("../glload/glload.lua");
dofile("Test/Test4.lua");
