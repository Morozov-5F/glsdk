--The current directory should be the base SDK directory.

require "lfs"
require "ufs"

local copywriteText = "Copyright (C) 2011 by Jason L. McKesson";
local licenseText = "This file is licensed by the MIT License."

local alwaysIgnorePattern =
{
	"stb_image%.c$",
	"stb_image%.h$",
}

local function CopywriteFile(filename)

	for i, ignore in ipairs(alwaysIgnorePattern) do
		if(filename:match(ignore)) then
			return
		end
	end

	local hInFile = io.open(filename, "rt");
	local fileData = hInFile:read("*a");
	hInFile:close();

	local hOutFile = io.open(filename, "wt");
	if(filename:match("%.c$") or filename:match("%.h$")) then
		hOutFile:write("/** ", copywriteText, " **/\n");
		hOutFile:write("/** ", licenseText, " **/\n");
	elseif(filename:match("%.cpp$") or filename:match("%.hpp$")) then
		hOutFile:write("//", copywriteText, "\n");
		hOutFile:write("//", licenseText, "\n");
	else
		--???
	end
	hOutFile:write("\n\n", fileData);
	hOutFile:close();
end

local searchPathsToMarkup =
{
	"glimg/include/glimg",
	"glimg/source",
	"glload/include/glload/gll.h",
	"glload/include/glload/gl_core.h",
	"glload/include/glload/gl_all.h",
	"glload/include/glload/gll.hpp",
	"glload/include/glload/gl_core.hpp",
	"glload/include/glload/gl_all.hpp",
	"glload/source/gll_cpp.cpp",
	"glload/source/gll_c.c",
}

local acceptedExtensions = {"cpp", "c", "h", "hpp"}

for i, testPath in ipairs(searchPathsToMarkup) do
	local mode = lfs.attributes(testPath, "mode");
	if(mode == "directory") then
		local pathBase = ufs.path(testPath);
		for file in lfs.dir(testPath) do
			for i, testExt in ipairs(acceptedExtensions) do
				if(file:match("%." .. testExt .. "$")) then
					CopywriteFile(tostring(pathBase / file));
					break;
				end
			end
		end
	elseif(mode == "file") then
		CopywriteFile(testPath);
	else
		print(testPath, "Is a:", mode);
	end
end




--Write the main license file.

local MitLicenseText = 
[====[
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
]====]

--[[
local hFile = io.open("MIT License.txt", "wt");
hFile:write(copywriteText,
	"\n\n",
	MitLicenseText);
hFile:close();
]]