

local function RepSep(str, count, sep)
	local value = "";
	for i = 1, count do
		if(i ~= 1) then value = value .. sep; end
		value = value .. str;
	end
	
	return value;
end

local function WritePreamble(hFile)
	hFile:write(
[[
#include <exception>
#include <stdio.h>
#include <glload/gll.h>
#include <glload/gl_all.h>

void ShowCaps()
{
	int integers[32];
	float floats[32];

]]
	);
end

local function WritePostscript(hFile)
	hFile:write(
[[

}
]]
	);
end

local function WriteBasicData(hFile)
	local strings =
	{
		"GL_VENDOR",
		"GL_RENDERER",
		"GL_VERSION",
		"GL_SHADING_LANGUAGE_VERSION",
	}
	
	hFile:write("printf(\"== Implementation Information ==\\n\\n\");\n");
	
	for i, theString in ipairs(strings) do
		hFile:write("printf(\"* ", theString);
		hFile:write([[: %s\n", (const char *)glGetString(]]);
		hFile:write(theString, "));\n");
	end
end

--Components:
-- 1: The printf format
-- 2: The OpenGL base call to get this type.
-- 3: The variable, defined above, to fill with this call.
-- 4: The base C++ type for this value.
local typeData =
{
	int = {"%i", "glGetIntegerv", "integers", "GLint"},
	hex = {"%08x", "glGetIntegerv", "integers", "GLint"},
	float = {"%f", "glGetFloatv", "floats", "GLfloat"},
}

local function WriteNumericLimits(hFile)
	hFile:write("printf(\"== Numeric Limits ==\\n\\n\");\n");
	
	local limits =
	{
		{
			cat = "Image Limits",
			{"GL_MAX_TEXTURE_SIZE", "Texture Size", "int"},
			{"GL_MAX_3D_TEXTURE_SIZE", "3D Texture Size", "int"},
			{"GL_MAX_CUBE_MAP_TEXTURE_SIZE", "Cubemap Texture Size", "int"},
			{"GL_MAX_RENDERBUFFER_SIZE", "Renderbuffer Size", "int"},
			{"GL_MAX_RECTANGLE_TEXTURE_SIZE", "Rectangle Texture Size", "int"},
			{"GL_MAX_ARRAY_TEXTURE_LAYERS", "Texture Layers", "int"},
			{"GL_MAX_TEXTURE_BUFFER_SIZE", "Texture Buffer Size", "int"},
		},
		{
			cat = "Viewport Limits",
			{"GL_MAX_VIEWPORT_DIMS", "Viewport Dimensions", "float", 2},
			{"GL_MAX_VIEWPORTS", "Num Viewports", "int"},
			{"GL_VIEWPORT_BOUNDS_RANGE", "Largest Viewport Size", "float", 2},
			{"GL_VIEWPORT_SUBPIXEL_BITS", "Viewport Range Subpixel Bits", "int"},
		},
		{
			cat = "Binary Programs",
			{"GL_NUM_PROGRAM_BINARY_FORMATS", "Number of Binary Formats", "int"},
			{"GL_PROGRAM_BINARY_FORMATS", "Binary Formats", "hex", "GL_NUM_PROGRAM_BINARY_FORMATS"},
			{"GL_NUM_SHADER_BINARY_FORMATS", "Number of Shader Formats", "int"},
--			{"GL_SHADER_BINARY_FORMATS", "Shader Formats", "hex", "GL_NUM_SHADER_BINARY_FORMATS"},
		},
		{
			cat = "Vertex Shader Limits",
			{"GL_MAX_VERTEX_ATTRIBS", "Vertex Attributes", "int"},
			{"GL_MAX_VERTEX_UNIFORM_COMPONENTS", "Uniform Components", "int"},
			{"GL_MAX_VERTEX_UNIFORM_VECTORS", "Uniform Vectors", "int"},
			{"GL_MAX_VERTEX_UNIFORM_BLOCKS", "Uniform Blocks", "int"},
			{"GL_MAX_VERTEX_OUTPUT_COMPONENTS", "Output Components", "int"},
			{"GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS", "Texture Units", "int"},
		},
		{
			cat = "Tessellation Shader Limits",
			{"GL_MAX_TESS_GEN_LEVEL", "Number of tessellation levels", "int"},
			{"GL_MAX_PATCH_VERTICES", "Vertices per patch", "int"},
		},
		{
			cat = "Tessellation Control Shader Limits",
			{"GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS", "Uniform Components", "int"},
			{"GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS", "Texture Units", "int"},
			{"GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS", "Per vertex output components", "int"},
			{"GL_MAX_TESS_PATCH_COMPONENTS", "Components output per patch", "int"},
			{"GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS", "Output Components", "int"},
			{"GL_MAX_TESS_CONTROL_INPUT_COMPONENTS", "Input Components", "int"},
			{"GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS", "Uniform Blocks", "int"},
		},
		{
			cat = "Tessellation Evaluation Shader Limits",
			{"GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS", "Uniform Components", "int"},
			{"GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS", "Texture Units", "int"},
			{"GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS", "Output Components", "int"},
			{"GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS", "Input Components", "int"},
			{"GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS", "Uniform Blocks", "int"},
		},
		{
			cat = "Geometry Shader Limits",
			{"GL_MAX_GEOMETRY_UNIFORM_COMPONENTS", "Uniform Components", "int"},
			{"GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS", "Texture Units", "int"},
			{"GL_MAX_GEOMETRY_OUTPUT_COMPONENTS", "Per vertex output components", "int"},
			{"GL_MAX_GEOMETRY_OUTPUT_VERTICES", "Output Vertices", "int"},
			{"GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS", "Total component output", "int"},
			{"GL_MAX_GEOMETRY_INPUT_COMPONENTS", "Input Components", "int"},
			{"GL_MAX_GEOMETRY_UNIFORM_BLOCKS", "Uniform Blocks", "int"},
			{"GL_MAX_VERTEX_STREAMS", "Vertex Streams", "int"},
		},
		{
			cat = "Fragment Shader Limits",
			{"GL_MAX_FRAGMENT_UNIFORM_COMPONENTS", "Uniform Components", "int"},
			{"GL_MAX_FRAGMENT_UNIFORM_VECTORS", "Uniform Vectors", "int"},
			{"GL_MAX_TEXTURE_IMAGE_UNITS", "Texture Units", "int"},
			{"GL_MAX_FRAGMENT_INPUT_COMPONENTS", "Input Components", "int"},
			{"GL_MAX_FRAGMENT_UNIFORM_BLOCKS", "Uniform Blocks", "int"},
		},
		{
			cat = "Combined Shader Limits",
			{"GL_MAX_UNIFORM_BUFFER_BINDINGS", "Total number of uniform buffer binding points", "int"},
			{"GL_MAX_UNIFORM_BLOCK_SIZE", "Size in bytes of a block", "int"},
			{"GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT", "Minimum alignment for uniform buffer sizes/offsets", "int"},
			{"GL_MAX_COMBINED_UNIFORM_BLOCKS", "Number of uniform buffers per program", "int"},
			{"GL_MAX_VARYING_COMPONENTS", "Number of varying components per program.", "int"},
			{"GL_MAX_VARYING_VECTORS", "Number of varying vectors per program", "int"},
			{"GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS", "Total number of texture image units", "int"},
			{"GL_MAX_SUBROUTINES", "Number of Subroutines", "int"},
			{"GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS", "Maximum subroutines per stage.", "int"},

			{"GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS", "Total vertex stage uniforms", "int"},
			{"GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS", "Total tess control stage uniforms", "int"},
			{"GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS", "Total tex eval stage uniforms", "int"},
			{"GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS", "Total geometry stage uniforms", "int"},
			{"GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS", "Total fragment stage uniforms", "int"},
		},
		{
			cat = "Texture Access Limits",
			{"GL_MAX_TEXTURE_LOD_BIAS", "LOD Bias", "float"},
			{"GL_MIN_PROGRAM_TEXEL_OFFSET", "Minimum texel offset", "int"},
			{"GL_MAX_PROGRAM_TEXEL_OFFSET", "Maximum texel offset", "int"},
			{"GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET", "Minimum texture gather offset", "int"},
			{"GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET", "Maximum texture gather offset", "int"},
		},
		{
			cat = "Transform Feeback Limits",
			{"GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS", "Components written while interleaved", "int"},
			{"GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS", "Num separate attributes", "int"},
			{"GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS", "Num components per attribute while separate", "int"},
			{"GL_MAX_TRANSFORM_FEEDBACK_BUFFERS", "Num buffers written to", "int"},
		},
		{
			cat = "Framebuffer Limits",
			{"GL_MAX_DRAW_BUFFERS", "Num active FBO color attachments", "int"},
			{"GL_MAX_DUAL_SOURCE_DRAW_BUFFERS", "Num active FBO color attachments when dual source", "int"},
		},
		{
			cat = "Multisample Limits",
			{"GL_MAX_COLOR_TEXTURE_SAMPLES", "Samples per color texture", "int"},
			{"GL_MAX_DEPTH_TEXTURE_SAMPLES", "Samples per depth/stencil texture", "int"},
			{"GL_MAX_INTEGER_SAMPLES", "Samples per integer buffer", "int"},
		},
		{
			cat = "Drawing Limits",
			{"GL_MAX_ELEMENTS_INDICES", "Recommended max index count for glDrawRange*", "int"},
			{"GL_MAX_ELEMENTS_VERTICES", "Recommended max vertex count for glDrawRange*", "int"},
		},
	}
	
	for i, cat in ipairs(limits) do
		hFile:write("printf(\"=== ");
		hFile:write(cat.cat);
		hFile:write(" ===\\n\\n\");\n");
		
		for j, limit in ipairs(cat) do
			local numComponents = limit[4] or 1;
			local typeInfo = typeData[limit[3]];
			
			if(type(numComponents) == "string") then
				hFile:write("{\n", "\tint iCount = 0;\n");
				hFile:write("\tglGetIntegerv(", numComponents, ", &iCount);\n");
				hFile:write("\tif(iCount)\n\t{\n")
				
				hFile:write("\t\t", typeInfo[4],  "*pData = new ", typeInfo[4], "[iCount];\n")
				hFile:write("\t\t", typeInfo[2]);
				hFile:write(string.format("(%s, pData);\n", limit[1]));
				hFile:write("\t\tif(glGetError() == GL_NO_ERROR)\n");
				hFile:write("\t\t{\n");

				hFile:write("\t\t\tprintf(\"* ", limit[2], "(%i): \", iCount);\n");
				hFile:write("\t\t\tfor(int iLoop = 0; iLoop < iCount; iLoop++)\n");
				hFile:write("\t\t\t{\n");
				hFile:write("\t\t\t\tprintf(\"", typeInfo[1], "\", pData[iLoop]);\n");
				hFile:write("\t\t\t\tif(iLoop != iCount - 1)\n\t\t\t\t\tprintf(\", \");\n")
				hFile:write("\t\t\t}\n", "\t\t\tprintf(\"\\n\");\n");

				hFile:write("\t\t}\n");
				hFile:write("\t\tdelete[] pData;\n")
				
				hFile:write("\t}\n}\n");
			else
				hFile:write(typeInfo[2]);
				hFile:write(string.format("(%s, %s);\n", limit[1], typeInfo[3]));

				hFile:write("if(glGetError() == GL_NO_ERROR)\n");

				hFile:write("\tprintf(\"* ", limit[2], ": ");
				hFile:write(RepSep(typeInfo[1], numComponents, ", "));
				hFile:write("\\n\", ");
				for k = 1, numComponents do
					hFile:write(typeInfo[3], "[", k - 1, "]");
					if(k ~= numComponents) then hFile:write(", "); end
				end
				hFile:write(");\n");
			end
		end
		
		hFile:write([[printf("\n\n");]], "\n\n");
	end
	
end

local hFile = assert(io.open("caps.cpp", "w"), "Could not open file.");

WritePreamble(hFile);

WriteBasicData(hFile);
hFile:write("\n\n");

WriteNumericLimits(hFile);
hFile:write("\n\n");

WritePostscript(hFile);

hFile:close();


