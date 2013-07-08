#ifndef GLSDK_GLSCENE_PARSER_ENUMS_H
#define GLSDK_GLSCENE_PARSER_ENUMS_H

#include <boost/utility/string_ref.hpp>
#include "ResourceData.h"
#include <glutil/MousePoles.h>


namespace
{
	using boost::string_ref;

	boost::string_ref g_uniformTypeList[] =
	{
		"uint",
		"uvec2",
		"uvec3",
		"uvec4",
		"int",
		"ivec2",
		"ivec3",
		"ivec4",
		"float",
		"vec2",
		"vec3",
		"vec4",
		"mat2",
		"mat3",
		"mat4",
	};

	const int NUM_UNSIGNED_INDICES = 4;
	const int NUM_INTEGER_INDICES = 8;

	inline bool IsUnifTypeUnsigned(int typeIx) {return typeIx < NUM_UNSIGNED_INDICES;}
	inline bool IsUnifTypeInteger(int typeIx) {return typeIx < NUM_INTEGER_INDICES;}

	inline glscene::UniformData CreateDefaultUniform(int typeIx)
	{
		switch(typeIx)
		{
		case 0: return glscene::UIntVectorTypes((unsigned int)0);
		case 1: return glscene::UIntVectorTypes(glm::uvec2(0));
		case 2: return glscene::UIntVectorTypes(glm::uvec3(0));
		case 3: return glscene::UIntVectorTypes(glm::uvec4(0));

		case 4: return glscene::IntVectorTypes(int());
		case 5: return glscene::IntVectorTypes(glm::ivec2(0));
		case 6: return glscene::IntVectorTypes(glm::ivec3(0));
		case 7: return glscene::IntVectorTypes(glm::ivec4(0));

		case 8: return glscene::VectorTypes(float());
		case 9: return glscene::VectorTypes(glm::vec2(0.0f));
		case 10: return glscene::VectorTypes(glm::vec3(0.0f));
		case 11: return glscene::VectorTypes(glm::vec4(0.0f));

		case 12: return glscene::MatrixTypes(glm::mat2(1.0f));
		case 13: return glscene::MatrixTypes(glm::mat3(1.0f));
		case 14: return glscene::MatrixTypes(glm::mat4(1.0f));
		}

		return glscene::UniformData();
	}

	template<typename T>
	glscene::UniformData ConstructFromSingleValue(T val, int typeIx)
	{
		switch(typeIx)
		{
		case 0: return glscene::UIntVectorTypes((unsigned int)(val));
		case 1: return glscene::UIntVectorTypes(glm::uvec2(val));
		case 2: return glscene::UIntVectorTypes(glm::uvec3(val));
		case 3: return glscene::UIntVectorTypes(glm::uvec4(val));

		case 4: return glscene::IntVectorTypes(int(val));
		case 5: return glscene::IntVectorTypes(glm::ivec2(val));
		case 6: return glscene::IntVectorTypes(glm::ivec3(val));
		case 7: return glscene::IntVectorTypes(glm::ivec4(val));

		case 8: return glscene::VectorTypes(float(val));
		case 9: return glscene::VectorTypes(glm::vec2(val));
		case 10: return glscene::VectorTypes(glm::vec3(val));
		case 11: return glscene::VectorTypes(glm::vec4(val));

		case 12: return glscene::MatrixTypes(glm::mat2(val));
		case 13: return glscene::MatrixTypes(glm::mat3(val));
		case 14: return glscene::MatrixTypes(glm::mat4(val));
		}

		return glscene::UniformData();
	}

	inline int GetUniformTypeLength(int typeIx)
	{
		switch(typeIx)
		{
		case 0:
		case 4:
		case 8:
			return 1;
		case 1:
		case 5:
		case 9:
			return 2;
		case 2:
		case 6:
		case 10:
			return 3;
		case 3:
		case 7:
		case 11:
			return 4;
		case 12:
			return 4;
		case 13:
			return 9;
		case 14:
			return 16;
		}
		return 0;
	}

	template<typename Mapped>
	struct EnumData
	{
		boost::string_ref enumName;
		refs::array_ref<boost::string_ref> enumerators;
		refs::array_ref<Mapped> mapping;
	};

	template<> struct EnumData<void>
	{
		boost::string_ref enumName;
		refs::array_ref<boost::string_ref> enumerators;
	};

	const EnumData<void> g_uniformTypeEnumeration = {"uniform type", refs::array_ref<string_ref>(g_uniformTypeList)};

	string_ref g_magFilterEnumNames[] =
	{
		"nearest",
		"linear",
	};

	GLenum g_magFilterEnumerators[] =
	{
		gl::NEAREST,
		gl::LINEAR,
	};

	string_ref g_minFilterEnumNames[] =
	{
		"nearest",
		"linear",
		"nearest_mip_nearest",
		"nearest_mip_linear",
		"linear_mip_nearest",
		"linear_mip_linear",
	};

	GLenum g_minFilterEnumerators[] =
	{
		gl::NEAREST,
		gl::LINEAR,
		gl::NEAREST_MIPMAP_NEAREST,
		gl::NEAREST_MIPMAP_LINEAR,
		gl::LINEAR_MIPMAP_NEAREST,
		gl::LINEAR_MIPMAP_LINEAR,
	};

	string_ref g_wrapModeEnumNames[] =
	{
		"edge_clamp",
		"border_clamp",
		"repeat",
		"mirror_repeat",
	};

	GLenum g_wrapModeEnumerators[] =
	{
		gl::CLAMP_TO_EDGE,
		gl::CLAMP_TO_BORDER,
		gl::REPEAT,
		gl::MIRRORED_REPEAT,
	};

	string_ref g_compareModeEnumNames[] =
	{
		"less",
		"less_equal",
		"greater",
		"greater_equal",
		"equal",
		"not_equal",
		"pass",
		"fail",
	};

	GLenum g_compareModeEnumerators[] =
	{
		gl::LESS,
		gl::LEQUAL,
		gl::GREATER,
		gl::GEQUAL,
		gl::EQUAL,
		gl::NOTEQUAL,
		gl::ALWAYS,
		gl::NEVER,
	};

	const EnumData<GLenum> g_magFilterEnumeration =
	{
		"mag",
		refs::array_ref<string_ref>(g_magFilterEnumNames),
		refs::array_ref<GLenum>(g_magFilterEnumerators)
	};
	const EnumData<GLenum> g_minFilterEnumeration =
	{
		"min",
		refs::array_ref<string_ref>(g_minFilterEnumNames),
		refs::array_ref<GLenum>(g_minFilterEnumerators),
	};
	const EnumData<GLenum> g_wrapModeEnumeration =
	{
		"wrap",
		refs::array_ref<string_ref>(g_wrapModeEnumNames),
		refs::array_ref<GLenum>(g_wrapModeEnumerators),
	};
	const EnumData<GLenum> g_compareModeEnumeration =
	{
		"compare",
		refs::array_ref<string_ref>(g_compareModeEnumNames),
		refs::array_ref<GLenum>(g_compareModeEnumerators),
	};

	string_ref g_cameraMouseButtonEnumNames[] =
	{
		"left_btn",
		"right_btn",
	};

	glutil::MouseButtons g_cameraMouseButtonEnumerators[] =
	{
		glutil::MB_LEFT_BTN,
		glutil::MB_RIGHT_BTN,
	};

	string_ref g_cameraKeyboardSideEnumNames[] =
	{
		"left_kbd",
		"right_kbd",
	};

	bool g_cameraKeyboardSideEnumerators[] =
	{
		false,
		true,
	};

	const EnumData<glutil::MouseButtons> g_cameraMouseButtonEnumeration =
	{
		"camera button",
		refs::array_ref<string_ref>(g_cameraMouseButtonEnumNames),
		refs::array_ref<glutil::MouseButtons>(g_cameraMouseButtonEnumerators)
	};

	const EnumData<bool> g_cameraKeyboardSideEnumeration =
	{
		"camera keyboard",
		refs::array_ref<string_ref>(g_cameraKeyboardSideEnumNames),
		refs::array_ref<bool>(g_cameraKeyboardSideEnumerators)
	};

	string_ref g_bufferUsageEnumNames[] =
	{
		"static_draw",
		"static_read",
		"static_copy",
		"dynamic_draw",
		"dynamic_read",
		"dynamic_copy",
		"stream_draw",
		"stream_read",
		"stream_copy",
	};

	GLenum g_bufferUsageEnumerators[] =
	{
		gl::STATIC_DRAW,
		gl::STATIC_READ,
		gl::STATIC_COPY,
		gl::DYNAMIC_DRAW,
		gl::DYNAMIC_READ,
		gl::DYNAMIC_COPY,
		gl::STREAM_DRAW,
		gl::STREAM_READ,
		gl::STREAM_COPY,
	};

	const EnumData<GLenum> g_bufferUsageEnumeration =
	{
		"buffer create",
		refs::array_ref<string_ref>(g_bufferUsageEnumNames),
		refs::array_ref<GLenum>(g_bufferUsageEnumerators)
	};

	string_ref g_meshCreateEnumNames[] =
	{
		"ground_plane",
		"unit_axes",
		"cube_block",
		"cube_pyramid",
		"tetrahedron",
		"cube",
		"octahedron",
		"dodecahedron",
		"icosahedron",
		"unit_sphere",
	};

	const int g_meshCreateNumParameters[] =
	{
		2,	//"ground_plane",
		0,	//"unit_axes",
		1,	//"cube_block",
		1,	//"cube_pyramid",
		0,	//"tetrahedron",
		0,	//"cube",
		0,	//"octahedron",
		0,	//"dodecahedron",
		0,	//"icosahedron",
		2,	//"unit_sphere",
	};

	const EnumData<void> g_meshCreateEnumeration =
	{
		"mesh create",
		refs::array_ref<string_ref>(g_meshCreateEnumNames),
	};


}

#endif //GLSDK_GLSCENE_PARSER_ENUMS_H
