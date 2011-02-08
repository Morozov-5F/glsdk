#include <exception>
#include <stdio.h>
#include <glload/gll.h>
#include <glload/gl_all.h>

void ShowCaps()
{
	int integers[32];
	float floats[32];

printf("== Implementation Information ==\n\n");
printf("* GL_VENDOR: %s\n", (const char *)glGetString(GL_VENDOR));
printf("* GL_RENDERER: %s\n", (const char *)glGetString(GL_RENDERER));
printf("* GL_VERSION: %s\n", (const char *)glGetString(GL_VERSION));
printf("* GL_SHADING_LANGUAGE_VERSION: %s\n", (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION));


printf("== Numeric Limits ==\n\n");
printf("=== Image Limits ===\n\n");
glGetIntegerv(GL_MAX_TEXTURE_SIZE, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Texture Size: %i\n", integers[0]);
glGetIntegerv(GL_MAX_3D_TEXTURE_SIZE, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* 3D Texture Size: %i\n", integers[0]);
glGetIntegerv(GL_MAX_CUBE_MAP_TEXTURE_SIZE, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Cubemap Texture Size: %i\n", integers[0]);
glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Renderbuffer Size: %i\n", integers[0]);
glGetIntegerv(GL_MAX_RECTANGLE_TEXTURE_SIZE, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Rectangle Texture Size: %i\n", integers[0]);
glGetIntegerv(GL_MAX_ARRAY_TEXTURE_LAYERS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Texture Layers: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TEXTURE_BUFFER_SIZE, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Texture Buffer Size: %i\n", integers[0]);
printf("\n\n");

printf("=== Viewport Limits ===\n\n");
glGetFloatv(GL_MAX_VIEWPORT_DIMS, floats);
if(glGetError() == GL_NO_ERROR)
	printf("* Viewport Dimensions: %f, %f\n", floats[0], floats[1]);
glGetIntegerv(GL_MAX_VIEWPORTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Num Viewports: %i\n", integers[0]);
glGetFloatv(GL_VIEWPORT_BOUNDS_RANGE, floats);
if(glGetError() == GL_NO_ERROR)
	printf("* Largest Viewport Size: %f, %f\n", floats[0], floats[1]);
glGetIntegerv(GL_VIEWPORT_SUBPIXEL_BITS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Viewport Range Subpixel Bits: %i\n", integers[0]);
printf("\n\n");

printf("=== Binary Programs ===\n\n");
glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Number of Binary Formats: %i\n", integers[0]);
{
	int iCount = 0;
	glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &iCount);
	if(iCount)
	{
		GLint*pData = new GLint[iCount];
		glGetIntegerv(GL_PROGRAM_BINARY_FORMATS, pData);
		if(glGetError() == GL_NO_ERROR)
		{
			printf("* Binary Formats(%i): ", iCount);
			for(int iLoop = 0; iLoop < iCount; iLoop++)
			{
				printf("%08x", pData[iLoop]);
				if(iLoop != iCount - 1)
					printf(", ");
			}
			printf("\n");
		}
		delete[] pData;
	}
}
glGetIntegerv(GL_NUM_SHADER_BINARY_FORMATS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Number of Shader Formats: %i\n", integers[0]);
printf("\n\n");

printf("=== Vertex Shader Limits ===\n\n");
glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Vertex Attributes: %i\n", integers[0]);
glGetIntegerv(GL_MAX_VERTEX_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_VERTEX_UNIFORM_VECTORS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Vectors: %i\n", integers[0]);
glGetIntegerv(GL_MAX_VERTEX_UNIFORM_BLOCKS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Blocks: %i\n", integers[0]);
glGetIntegerv(GL_MAX_VERTEX_OUTPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Output Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Texture Units: %i\n", integers[0]);
printf("\n\n");

printf("=== Tessellation Shader Limits ===\n\n");
glGetIntegerv(GL_MAX_TESS_GEN_LEVEL, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Number of tessellation levels: %i\n", integers[0]);
glGetIntegerv(GL_MAX_PATCH_VERTICES, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Vertices per patch: %i\n", integers[0]);
printf("\n\n");

printf("=== Tessellation Control Shader Limits ===\n\n");
glGetIntegerv(GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Texture Units: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Per vertex output components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_PATCH_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Components output per patch: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Output Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_CONTROL_INPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Input Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Blocks: %i\n", integers[0]);
printf("\n\n");

printf("=== Tessellation Evaluation Shader Limits ===\n\n");
glGetIntegerv(GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Texture Units: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Output Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Input Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Blocks: %i\n", integers[0]);
printf("\n\n");

printf("=== Geometry Shader Limits ===\n\n");
glGetIntegerv(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Texture Units: %i\n", integers[0]);
glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Per vertex output components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_VERTICES, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Output Vertices: %i\n", integers[0]);
glGetIntegerv(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Total component output: %i\n", integers[0]);
glGetIntegerv(GL_MAX_GEOMETRY_INPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Input Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_GEOMETRY_UNIFORM_BLOCKS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Blocks: %i\n", integers[0]);
glGetIntegerv(GL_MAX_VERTEX_STREAMS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Vertex Streams: %i\n", integers[0]);
printf("\n\n");

printf("=== Fragment Shader Limits ===\n\n");
glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_VECTORS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Vectors: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Texture Units: %i\n", integers[0]);
glGetIntegerv(GL_MAX_FRAGMENT_INPUT_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Input Components: %i\n", integers[0]);
glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_BLOCKS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Uniform Blocks: %i\n", integers[0]);
printf("\n\n");

printf("=== Combined Shader Limits ===\n\n");
glGetIntegerv(GL_MAX_UNIFORM_BUFFER_BINDINGS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Total number of uniform buffer binding points: %i\n", integers[0]);
glGetIntegerv(GL_MAX_UNIFORM_BLOCK_SIZE, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Size in bytes of a block: %i\n", integers[0]);
glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Minimum alignment for uniform buffer sizes/offsets: %i\n", integers[0]);
glGetIntegerv(GL_MAX_COMBINED_UNIFORM_BLOCKS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Number of uniform buffers per program: %i\n", integers[0]);
glGetIntegerv(GL_MAX_VARYING_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Number of varying components per program.: %i\n", integers[0]);
glGetIntegerv(GL_MAX_VARYING_VECTORS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Number of varying vectors per program: %i\n", integers[0]);
glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Total number of texture image units: %i\n", integers[0]);
glGetIntegerv(GL_MAX_SUBROUTINES, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Number of Subroutines: %i\n", integers[0]);
glGetIntegerv(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Maximum subroutines per stage.: %i\n", integers[0]);
glGetIntegerv(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Total vertex stage uniforms: %i\n", integers[0]);
glGetIntegerv(GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Total tess control stage uniforms: %i\n", integers[0]);
glGetIntegerv(GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Total tex eval stage uniforms: %i\n", integers[0]);
glGetIntegerv(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Total geometry stage uniforms: %i\n", integers[0]);
glGetIntegerv(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Total fragment stage uniforms: %i\n", integers[0]);
printf("\n\n");

printf("=== Texture Access Limits ===\n\n");
glGetFloatv(GL_MAX_TEXTURE_LOD_BIAS, floats);
if(glGetError() == GL_NO_ERROR)
	printf("* LOD Bias: %f\n", floats[0]);
glGetIntegerv(GL_MIN_PROGRAM_TEXEL_OFFSET, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Minimum texel offset: %i\n", integers[0]);
glGetIntegerv(GL_MAX_PROGRAM_TEXEL_OFFSET, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Maximum texel offset: %i\n", integers[0]);
glGetIntegerv(GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Minimum texture gather offset: %i\n", integers[0]);
glGetIntegerv(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Maximum texture gather offset: %i\n", integers[0]);
printf("\n\n");

printf("=== Transform Feeback Limits ===\n\n");
glGetIntegerv(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Components written while interleaved: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Num separate attributes: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Num components per attribute while separate: %i\n", integers[0]);
glGetIntegerv(GL_MAX_TRANSFORM_FEEDBACK_BUFFERS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Num buffers written to: %i\n", integers[0]);
printf("\n\n");

printf("=== Framebuffer Limits ===\n\n");
glGetIntegerv(GL_MAX_DRAW_BUFFERS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Num active FBO color attachments: %i\n", integers[0]);
glGetIntegerv(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Num active FBO color attachments when dual source: %i\n", integers[0]);
printf("\n\n");

printf("=== Multisample Limits ===\n\n");
glGetIntegerv(GL_MAX_COLOR_TEXTURE_SAMPLES, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Samples per color texture: %i\n", integers[0]);
glGetIntegerv(GL_MAX_DEPTH_TEXTURE_SAMPLES, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Samples per depth/stencil texture: %i\n", integers[0]);
glGetIntegerv(GL_MAX_INTEGER_SAMPLES, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Samples per integer buffer: %i\n", integers[0]);
printf("\n\n");

printf("=== Drawing Limits ===\n\n");
glGetIntegerv(GL_MAX_ELEMENTS_INDICES, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Recommended max index count for glDrawRange*: %i\n", integers[0]);
glGetIntegerv(GL_MAX_ELEMENTS_VERTICES, integers);
if(glGetError() == GL_NO_ERROR)
	printf("* Recommended max vertex count for glDrawRange*: %i\n", integers[0]);
printf("\n\n");




}
