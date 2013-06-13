local lfs = require "lfs"

local pull =
{
	"LICENSE_1_0.txt", 
	"any.hpp",
	"array.hpp",
	"assign.hpp",
	"bind.hpp",
	"men_fn.hpp",
	"boost/container",
	"foreach.hpp",
	"format.hpp",
	"function.hpp",
	"lexical_cast.hpp",
	"optional.hpp",
	"random.hpp",
	"ref.hpp",
	"dynamic_bitset.hpp",
	"bimap.hpp",

	"range.hpp",
	"boost/range/adaptors.hpp",
	"boost/range/algorithm.hpp",
	"scoped_ptr.hpp",
	"smart_ptr.hpp",
	"weak_ptr.hpp",
	"static_assert.hpp",
	"algorithm/string.hpp",

	"tuple/tuple.hpp",
	"tuple/tuple_comparison.hpp",
	"type_traits.hpp",
	"unordered_set.hpp",
	"unordered_map.hpp",
	"utility.hpp",
	"boost/utility",
	"boost/logic/tribool.hpp",
	"variant.hpp",
	"typeof/typeof.hpp",
	"boost/variant",
	"boost/algorithm/cxx11",
	"boost/property_tree",
	"boost/pool",

	"boost/fusion",
	"phoenix.hpp",
	"boost/phoenix",
	"spirit.hpp",
	"boost/spirit",
}

local srcDir, dstDir, version = ...

assert(srcDir and dstDir and version, "You must provide the root path to Boost as the first argument\nand the output directory path in the second, and a version number for Boost\nas the 3rd")

if(not srcDir:match("[\\/]$")) then srcDir = srcDir .. "/" end
if(not dstDir:match("[\\/]$")) then dstDir = dstDir .. "/" end

print(srcDir, dstDir)
lfs.mkdir(dstDir)

local versionFilename = dstDir .. "Version.txt"
local hFile = assert(io.open(versionFilename, "w"))
hFile:write("Boost version: ", version, "\n")
hFile:close();

--Use BCP to copy Boost.
local bcpLoc = srcDir .. "bin/bcp.exe"

assert(lfs.attributes(bcpLoc, "mode") == "file", "Could not find the BCP file " .. bcpLoc)

function flip(str)
	return str:gsub("%/", "\\")
end

local bcpCmdFmt = flip(bcpLoc) .. " --boost=" .. srcDir .. " %s " .. dstDir

local cmd = bcpCmdFmt:format(table.concat(pull, " "));
os.execute(cmd)

--Delete unnecessary things
local dels =
{
	"Jamroot",
}

for _, deleteThis in ipairs(dels) do
	local test = dstDir .. deleteThis
	local mode = lfs.attributes(test, "mode")
	print(test, mode)
	if(mode == "file") then
		os.remove(test)
	end
end