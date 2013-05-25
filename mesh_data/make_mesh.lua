
local function TransformVector(vector)
	return {vector[1], vector[3], -vector[2]}
end

local function NumToShort(number)
	number = math.min(1.0, number)
	number = math.max(-1.0, number)
	number = (number + 1.0) / 2.0
	
	return math.ceil(number * 65535) - 32768
end

local function NumToByte(number)
	number = math.min(1.0, number)
	number = math.max(-1.0, number)
	number = (number + 1.0) / 2.0
	
	return math.ceil(number * 255) - 128
end

local function WritePosition(hFile, vector)
	hFile:write(string.format("\t%i, %i, %i,\n",
		NumToShort(vector[1]), NumToShort(vector[2]), NumToShort(vector[3])))
end

local function WriteNormal(hFile, vector)
	hFile:write(string.format("\t%i, %i, %i,\n",
		NumToByte(vector[1]), NumToByte(vector[2]), NumToByte(vector[3])))
end

local filename = ...
filename = filename or "dodecahedron.lua"

local data = dofile(filename)

local hFile = io.stdout

hFile:write("const GLshort dodec_positions[] = \n")
hFile:write("{\n")

for _, triangle in ipairs(data.index) do
	WritePosition(hFile, TransformVector(data.pos[triangle[1] + 1]))
	WritePosition(hFile, TransformVector(data.pos[triangle[3] + 1]))
	WritePosition(hFile, TransformVector(data.pos[triangle[2] + 1]))
end

hFile:write("};\n")
hFile:write("\n")

hFile:write("const GLbyte dodec_normals[] = \n")
hFile:write("{\n")

for _, triangle in ipairs(data.index) do
	WriteNormal(hFile, TransformVector(data.norm[triangle[1] + 1]))
	WriteNormal(hFile, TransformVector(data.norm[triangle[3] + 1]))
	WriteNormal(hFile, TransformVector(data.norm[triangle[2] + 1]))
end

hFile:write("};\n")


