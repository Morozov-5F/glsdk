#ifndef WINDOWSGL_GEN_EXTENSIONS_HPP
#define WINDOWSGL_GEN_EXTENSIONS_HPP


#include "_int_load_test.hpp"
namespace wgl
{
	namespace exts
	{
		extern glload::LoadTest var_3DFX_multisample;
		extern glload::LoadTest var_3DL_stereo_control;
		extern glload::LoadTest var_AMD_gpu_association;
		extern glload::LoadTest var_ARB_buffer_region;
		extern glload::LoadTest var_ARB_create_context;
		extern glload::LoadTest var_ARB_create_context_profile;
		extern glload::LoadTest var_ARB_create_context_robustness;
		extern glload::LoadTest var_ARB_extensions_string;
		extern glload::LoadTest var_ARB_framebuffer_sRGB;
		extern glload::LoadTest var_ARB_make_current_read;
		extern glload::LoadTest var_ARB_multisample;
		extern glload::LoadTest var_ARB_pbuffer;
		extern glload::LoadTest var_ARB_pixel_format;
		extern glload::LoadTest var_ARB_pixel_format_float;
		extern glload::LoadTest var_ARB_render_texture;
		extern glload::LoadTest var_ATI_pixel_format_float;
		extern glload::LoadTest var_EXT_create_context_es2_profile;
		extern glload::LoadTest var_EXT_depth_float;
		extern glload::LoadTest var_EXT_framebuffer_sRGB;
		extern glload::LoadTest var_EXT_make_current_read;
		extern glload::LoadTest var_EXT_multisample;
		extern glload::LoadTest var_EXT_pbuffer;
		extern glload::LoadTest var_EXT_pixel_format;
		extern glload::LoadTest var_EXT_pixel_format_packed_float;
		extern glload::LoadTest var_EXT_swap_control;
		extern glload::LoadTest var_EXT_swap_control_tear;
		extern glload::LoadTest var_I3D_digital_video_control;
		extern glload::LoadTest var_I3D_gamma;
		extern glload::LoadTest var_I3D_genlock;
		extern glload::LoadTest var_I3D_image_buffer;
		extern glload::LoadTest var_I3D_swap_frame_lock;
		extern glload::LoadTest var_NV_DX_interop;
		extern glload::LoadTest var_NV_DX_interop2;
		extern glload::LoadTest var_NV_copy_image;
		extern glload::LoadTest var_NV_float_buffer;
		extern glload::LoadTest var_NV_gpu_affinity;
		extern glload::LoadTest var_NV_multisample_coverage;
		extern glload::LoadTest var_NV_present_video;
		extern glload::LoadTest var_NV_render_depth_texture;
		extern glload::LoadTest var_NV_render_texture_rectangle;
		extern glload::LoadTest var_NV_swap_group;
		extern glload::LoadTest var_NV_video_capture;
		extern glload::LoadTest var_NV_video_output;
	}
	
	enum
	{
		SAMPLE_BUFFERS_3DFX              = 0x2060,
		SAMPLES_3DFX                     = 0x2061,
		STEREO_EMITTER_ENABLE_3DL        = 0x2055,
		STEREO_EMITTER_DISABLE_3DL       = 0x2056,
		STEREO_POLARITY_NORMAL_3DL       = 0x2057,
		STEREO_POLARITY_INVERT_3DL       = 0x2058,
		GPU_VENDOR_AMD                   = 0x1F00,
		GPU_RENDERER_STRING_AMD          = 0x1F01,
		GPU_OPENGL_VERSION_STRING_AMD    = 0x1F02,
		GPU_FASTEST_TARGET_GPUS_AMD      = 0x21A2,
		GPU_RAM_AMD                      = 0x21A3,
		GPU_CLOCK_AMD                    = 0x21A4,
		GPU_NUM_PIPES_AMD                = 0x21A5,
		GPU_NUM_SIMD_AMD                 = 0x21A6,
		GPU_NUM_RB_AMD                   = 0x21A7,
		GPU_NUM_SPI_AMD                  = 0x21A8,
		FRONT_COLOR_BUFFER_BIT_ARB       = 0x00000001,
		BACK_COLOR_BUFFER_BIT_ARB        = 0x00000002,
		DEPTH_BUFFER_BIT_ARB             = 0x00000004,
		STENCIL_BUFFER_BIT_ARB           = 0x00000008,
		CONTEXT_DEBUG_BIT_ARB            = 0x00000001,
		CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = 0x00000002,
		CONTEXT_MAJOR_VERSION_ARB        = 0x2091,
		CONTEXT_MINOR_VERSION_ARB        = 0x2092,
		CONTEXT_LAYER_PLANE_ARB          = 0x2093,
		CONTEXT_FLAGS_ARB                = 0x2094,
		ERROR_INVALID_VERSION_ARB        = 0x2095,
		CONTEXT_PROFILE_MASK_ARB         = 0x9126,
		CONTEXT_CORE_PROFILE_BIT_ARB     = 0x00000001,
		CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002,
		ERROR_INVALID_PROFILE_ARB        = 0x2096,
		CONTEXT_ROBUST_ACCESS_BIT_ARB    = 0x00000004,
		LOSE_CONTEXT_ON_RESET_ARB        = 0x8252,
		CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB = 0x8256,
		NO_RESET_NOTIFICATION_ARB        = 0x8261,
		FRAMEBUFFER_SRGB_CAPABLE_ARB     = 0x20A9,
		ERROR_INVALID_PIXEL_TYPE_ARB     = 0x2043,
		ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB = 0x2054,
		SAMPLE_BUFFERS_ARB               = 0x2041,
		SAMPLES_ARB                      = 0x2042,
		TRANSPARENT_RED_VALUE_ARB        = 0x2037,
		TRANSPARENT_GREEN_VALUE_ARB      = 0x2038,
		TRANSPARENT_BLUE_VALUE_ARB       = 0x2039,
		TRANSPARENT_ALPHA_VALUE_ARB      = 0x203A,
		TRANSPARENT_INDEX_VALUE_ARB      = 0x203B,
		DRAW_TO_PBUFFER_ARB              = 0x202D,
		MAX_PBUFFER_PIXELS_ARB           = 0x202E,
		MAX_PBUFFER_WIDTH_ARB            = 0x202F,
		MAX_PBUFFER_HEIGHT_ARB           = 0x2030,
		PBUFFER_LARGEST_ARB              = 0x2033,
		PBUFFER_WIDTH_ARB                = 0x2034,
		PBUFFER_HEIGHT_ARB               = 0x2035,
		PBUFFER_LOST_ARB                 = 0x2036,
		NUMBER_PIXEL_FORMATS_ARB         = 0x2000,
		DRAW_TO_WINDOW_ARB               = 0x2001,
		DRAW_TO_BITMAP_ARB               = 0x2002,
		ACCELERATION_ARB                 = 0x2003,
		NEED_PALETTE_ARB                 = 0x2004,
		NEED_SYSTEM_PALETTE_ARB          = 0x2005,
		SWAP_LAYER_BUFFERS_ARB           = 0x2006,
		SWAP_METHOD_ARB                  = 0x2007,
		NUMBER_OVERLAYS_ARB              = 0x2008,
		NUMBER_UNDERLAYS_ARB             = 0x2009,
		TRANSPARENT_ARB                  = 0x200A,
		//TRANSPARENT_RED_VALUE_ARB taken from ARB_pbuffer
		//TRANSPARENT_GREEN_VALUE_ARB taken from ARB_pbuffer
		//TRANSPARENT_BLUE_VALUE_ARB taken from ARB_pbuffer
		//TRANSPARENT_ALPHA_VALUE_ARB taken from ARB_pbuffer
		//TRANSPARENT_INDEX_VALUE_ARB taken from ARB_pbuffer
		SHARE_DEPTH_ARB                  = 0x200C,
		SHARE_STENCIL_ARB                = 0x200D,
		SHARE_ACCUM_ARB                  = 0x200E,
		SUPPORT_GDI_ARB                  = 0x200F,
		SUPPORT_OPENGL_ARB               = 0x2010,
		DOUBLE_BUFFER_ARB                = 0x2011,
		STEREO_ARB                       = 0x2012,
		PIXEL_TYPE_ARB                   = 0x2013,
		COLOR_BITS_ARB                   = 0x2014,
		RED_BITS_ARB                     = 0x2015,
		RED_SHIFT_ARB                    = 0x2016,
		GREEN_BITS_ARB                   = 0x2017,
		GREEN_SHIFT_ARB                  = 0x2018,
		BLUE_BITS_ARB                    = 0x2019,
		BLUE_SHIFT_ARB                   = 0x201A,
		ALPHA_BITS_ARB                   = 0x201B,
		ALPHA_SHIFT_ARB                  = 0x201C,
		ACCUM_BITS_ARB                   = 0x201D,
		ACCUM_RED_BITS_ARB               = 0x201E,
		ACCUM_GREEN_BITS_ARB             = 0x201F,
		ACCUM_BLUE_BITS_ARB              = 0x2020,
		ACCUM_ALPHA_BITS_ARB             = 0x2021,
		DEPTH_BITS_ARB                   = 0x2022,
		STENCIL_BITS_ARB                 = 0x2023,
		AUX_BUFFERS_ARB                  = 0x2024,
		NO_ACCELERATION_ARB              = 0x2025,
		GENERIC_ACCELERATION_ARB         = 0x2026,
		FULL_ACCELERATION_ARB            = 0x2027,
		SWAP_EXCHANGE_ARB                = 0x2028,
		SWAP_COPY_ARB                    = 0x2029,
		SWAP_UNDEFINED_ARB               = 0x202A,
		TYPE_RGBA_ARB                    = 0x202B,
		TYPE_COLORINDEX_ARB              = 0x202C,
		TYPE_RGBA_FLOAT_ARB              = 0x21A0,
		BIND_TO_TEXTURE_RGB_ARB          = 0x2070,
		BIND_TO_TEXTURE_RGBA_ARB         = 0x2071,
		TEXTURE_FORMAT_ARB               = 0x2072,
		TEXTURE_TARGET_ARB               = 0x2073,
		MIPMAP_TEXTURE_ARB               = 0x2074,
		TEXTURE_RGB_ARB                  = 0x2075,
		TEXTURE_RGBA_ARB                 = 0x2076,
		NO_TEXTURE_ARB                   = 0x2077,
		TEXTURE_CUBE_MAP_ARB             = 0x2078,
		TEXTURE_1D_ARB                   = 0x2079,
		TEXTURE_2D_ARB                   = 0x207A,
		MIPMAP_LEVEL_ARB                 = 0x207B,
		CUBE_MAP_FACE_ARB                = 0x207C,
		TEXTURE_CUBE_MAP_POSITIVE_X_ARB  = 0x207D,
		TEXTURE_CUBE_MAP_NEGATIVE_X_ARB  = 0x207E,
		TEXTURE_CUBE_MAP_POSITIVE_Y_ARB  = 0x207F,
		TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB  = 0x2080,
		TEXTURE_CUBE_MAP_POSITIVE_Z_ARB  = 0x2081,
		TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB  = 0x2082,
		FRONT_LEFT_ARB                   = 0x2083,
		FRONT_RIGHT_ARB                  = 0x2084,
		BACK_LEFT_ARB                    = 0x2085,
		BACK_RIGHT_ARB                   = 0x2086,
		AUX0_ARB                         = 0x2087,
		AUX1_ARB                         = 0x2088,
		AUX2_ARB                         = 0x2089,
		AUX3_ARB                         = 0x208A,
		AUX4_ARB                         = 0x208B,
		AUX5_ARB                         = 0x208C,
		AUX6_ARB                         = 0x208D,
		AUX7_ARB                         = 0x208E,
		AUX8_ARB                         = 0x208F,
		AUX9_ARB                         = 0x2090,
		TYPE_RGBA_FLOAT_ATI              = 0x21A0,
		CONTEXT_ES2_PROFILE_BIT_EXT      = 0x00000004,
		DEPTH_FLOAT_EXT                  = 0x2040,
		FRAMEBUFFER_SRGB_CAPABLE_EXT     = 0x20A9,
		ERROR_INVALID_PIXEL_TYPE_EXT     = 0x2043,
		SAMPLE_BUFFERS_EXT               = 0x2041,
		SAMPLES_EXT                      = 0x2042,
		DRAW_TO_PBUFFER_EXT              = 0x202D,
		MAX_PBUFFER_PIXELS_EXT           = 0x202E,
		MAX_PBUFFER_WIDTH_EXT            = 0x202F,
		MAX_PBUFFER_HEIGHT_EXT           = 0x2030,
		OPTIMAL_PBUFFER_WIDTH_EXT        = 0x2031,
		OPTIMAL_PBUFFER_HEIGHT_EXT       = 0x2032,
		PBUFFER_LARGEST_EXT              = 0x2033,
		PBUFFER_WIDTH_EXT                = 0x2034,
		PBUFFER_HEIGHT_EXT               = 0x2035,
		NUMBER_PIXEL_FORMATS_EXT         = 0x2000,
		DRAW_TO_WINDOW_EXT               = 0x2001,
		DRAW_TO_BITMAP_EXT               = 0x2002,
		ACCELERATION_EXT                 = 0x2003,
		NEED_PALETTE_EXT                 = 0x2004,
		NEED_SYSTEM_PALETTE_EXT          = 0x2005,
		SWAP_LAYER_BUFFERS_EXT           = 0x2006,
		SWAP_METHOD_EXT                  = 0x2007,
		NUMBER_OVERLAYS_EXT              = 0x2008,
		NUMBER_UNDERLAYS_EXT             = 0x2009,
		TRANSPARENT_EXT                  = 0x200A,
		TRANSPARENT_VALUE_EXT            = 0x200B,
		SHARE_DEPTH_EXT                  = 0x200C,
		SHARE_STENCIL_EXT                = 0x200D,
		SHARE_ACCUM_EXT                  = 0x200E,
		SUPPORT_GDI_EXT                  = 0x200F,
		SUPPORT_OPENGL_EXT               = 0x2010,
		DOUBLE_BUFFER_EXT                = 0x2011,
		STEREO_EXT                       = 0x2012,
		PIXEL_TYPE_EXT                   = 0x2013,
		COLOR_BITS_EXT                   = 0x2014,
		RED_BITS_EXT                     = 0x2015,
		RED_SHIFT_EXT                    = 0x2016,
		GREEN_BITS_EXT                   = 0x2017,
		GREEN_SHIFT_EXT                  = 0x2018,
		BLUE_BITS_EXT                    = 0x2019,
		BLUE_SHIFT_EXT                   = 0x201A,
		ALPHA_BITS_EXT                   = 0x201B,
		ALPHA_SHIFT_EXT                  = 0x201C,
		ACCUM_BITS_EXT                   = 0x201D,
		ACCUM_RED_BITS_EXT               = 0x201E,
		ACCUM_GREEN_BITS_EXT             = 0x201F,
		ACCUM_BLUE_BITS_EXT              = 0x2020,
		ACCUM_ALPHA_BITS_EXT             = 0x2021,
		DEPTH_BITS_EXT                   = 0x2022,
		STENCIL_BITS_EXT                 = 0x2023,
		AUX_BUFFERS_EXT                  = 0x2024,
		NO_ACCELERATION_EXT              = 0x2025,
		GENERIC_ACCELERATION_EXT         = 0x2026,
		FULL_ACCELERATION_EXT            = 0x2027,
		SWAP_EXCHANGE_EXT                = 0x2028,
		SWAP_COPY_EXT                    = 0x2029,
		SWAP_UNDEFINED_EXT               = 0x202A,
		TYPE_RGBA_EXT                    = 0x202B,
		TYPE_COLORINDEX_EXT              = 0x202C,
		TYPE_RGBA_UNSIGNED_FLOAT_EXT     = 0x20A8,
		DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D = 0x2050,
		DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D = 0x2051,
		DIGITAL_VIDEO_CURSOR_INCLUDED_I3D = 0x2052,
		DIGITAL_VIDEO_GAMMA_CORRECTED_I3D = 0x2053,
		GAMMA_TABLE_SIZE_I3D             = 0x204E,
		GAMMA_EXCLUDE_DESKTOP_I3D        = 0x204F,
		GENLOCK_SOURCE_MULTIVIEW_I3D     = 0x2044,
		GENLOCK_SOURCE_EXTERNAL_SYNC_I3D = 0x2045,
		GENLOCK_SOURCE_EXTERNAL_FIELD_I3D = 0x2046,
		GENLOCK_SOURCE_EXTERNAL_TTL_I3D  = 0x2047,
		GENLOCK_SOURCE_DIGITAL_SYNC_I3D  = 0x2048,
		GENLOCK_SOURCE_DIGITAL_FIELD_I3D = 0x2049,
		GENLOCK_SOURCE_EDGE_FALLING_I3D  = 0x204A,
		GENLOCK_SOURCE_EDGE_RISING_I3D   = 0x204B,
		GENLOCK_SOURCE_EDGE_BOTH_I3D     = 0x204C,
		IMAGE_BUFFER_MIN_ACCESS_I3D      = 0x00000001,
		IMAGE_BUFFER_LOCK_I3D            = 0x00000002,
		ACCESS_READ_ONLY_NV              = 0x00000000,
		ACCESS_READ_WRITE_NV             = 0x00000001,
		ACCESS_WRITE_DISCARD_NV          = 0x00000002,
		FLOAT_COMPONENTS_NV              = 0x20B0,
		BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV = 0x20B1,
		BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV = 0x20B2,
		BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV = 0x20B3,
		BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV = 0x20B4,
		TEXTURE_FLOAT_R_NV               = 0x20B5,
		TEXTURE_FLOAT_RG_NV              = 0x20B6,
		TEXTURE_FLOAT_RGB_NV             = 0x20B7,
		TEXTURE_FLOAT_RGBA_NV            = 0x20B8,
		ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV = 0x20D0,
		ERROR_MISSING_AFFINITY_MASK_NV   = 0x20D1,
		COVERAGE_SAMPLES_NV              = 0x2042,
		COLOR_SAMPLES_NV                 = 0x20B9,
		NUM_VIDEO_SLOTS_NV               = 0x20F0,
		BIND_TO_TEXTURE_DEPTH_NV         = 0x20A3,
		BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV = 0x20A4,
		DEPTH_TEXTURE_FORMAT_NV          = 0x20A5,
		TEXTURE_DEPTH_COMPONENT_NV       = 0x20A6,
		DEPTH_COMPONENT_NV               = 0x20A7,
		BIND_TO_TEXTURE_RECTANGLE_RGB_NV = 0x20A0,
		BIND_TO_TEXTURE_RECTANGLE_RGBA_NV = 0x20A1,
		TEXTURE_RECTANGLE_NV             = 0x20A2,
		UNIQUE_ID_NV                     = 0x20CE,
		NUM_VIDEO_CAPTURE_SLOTS_NV       = 0x20CF,
		BIND_TO_VIDEO_RGB_NV             = 0x20C0,
		BIND_TO_VIDEO_RGBA_NV            = 0x20C1,
		BIND_TO_VIDEO_RGB_AND_DEPTH_NV   = 0x20C2,
		VIDEO_OUT_COLOR_NV               = 0x20C3,
		VIDEO_OUT_ALPHA_NV               = 0x20C4,
		VIDEO_OUT_DEPTH_NV               = 0x20C5,
		VIDEO_OUT_COLOR_AND_ALPHA_NV     = 0x20C6,
		VIDEO_OUT_COLOR_AND_DEPTH_NV     = 0x20C7,
		VIDEO_OUT_FRAME                  = 0x20C8,
		VIDEO_OUT_FIELD_1                = 0x20C9,
		VIDEO_OUT_FIELD_2                = 0x20CA,
		VIDEO_OUT_STACKED_FIELDS_1_2     = 0x20CB,
		VIDEO_OUT_STACKED_FIELDS_2_1     = 0x20CC,
	};
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglSetStereoEmitterState3DL)(HDC hDC, UINT uState);
	}
	
	extern _detail::Proc_wglSetStereoEmitterState3DL SetStereoEmitterState3DL;
	
	namespace _detail
	{
		typedef UINT (CODEGEN_FUNCPTR * Proc_wglGetGPUIDsAMD)(UINT maxCount, UINT *ids);
		typedef INT (CODEGEN_FUNCPTR * Proc_wglGetGPUInfoAMD)(UINT id, int property, GLenum dataType, UINT size, void *data);
		typedef UINT (CODEGEN_FUNCPTR * Proc_wglGetContextGPUIDAMD)(HGLRC hglrc);
		typedef HGLRC (CODEGEN_FUNCPTR * Proc_wglCreateAssociatedContextAMD)(UINT id);
		typedef HGLRC (CODEGEN_FUNCPTR * Proc_wglCreateAssociatedContextAttribsAMD)(UINT id, HGLRC hShareContext, const int *attribList);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDeleteAssociatedContextAMD)(HGLRC hglrc);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglMakeAssociatedContextCurrentAMD)(HGLRC hglrc);
		typedef HGLRC (CODEGEN_FUNCPTR * Proc_wglGetCurrentAssociatedContextAMD)();
		typedef VOID (CODEGEN_FUNCPTR * Proc_wglBlitContextFramebufferAMD)(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	}
	
	extern _detail::Proc_wglGetGPUIDsAMD GetGPUIDsAMD;
	extern _detail::Proc_wglGetGPUInfoAMD GetGPUInfoAMD;
	extern _detail::Proc_wglGetContextGPUIDAMD GetContextGPUIDAMD;
	extern _detail::Proc_wglCreateAssociatedContextAMD CreateAssociatedContextAMD;
	extern _detail::Proc_wglCreateAssociatedContextAttribsAMD CreateAssociatedContextAttribsAMD;
	extern _detail::Proc_wglDeleteAssociatedContextAMD DeleteAssociatedContextAMD;
	extern _detail::Proc_wglMakeAssociatedContextCurrentAMD MakeAssociatedContextCurrentAMD;
	extern _detail::Proc_wglGetCurrentAssociatedContextAMD GetCurrentAssociatedContextAMD;
	extern _detail::Proc_wglBlitContextFramebufferAMD BlitContextFramebufferAMD;
	
	namespace _detail
	{
		typedef HANDLE (CODEGEN_FUNCPTR * Proc_wglCreateBufferRegionARB)(HDC hDC, int iLayerPlane, UINT uType);
		typedef VOID (CODEGEN_FUNCPTR * Proc_wglDeleteBufferRegionARB)(HANDLE hRegion);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglSaveBufferRegionARB)(HANDLE hRegion, int x, int y, int width, int height);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglRestoreBufferRegionARB)(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
	}
	
	extern _detail::Proc_wglCreateBufferRegionARB CreateBufferRegionARB;
	extern _detail::Proc_wglDeleteBufferRegionARB DeleteBufferRegionARB;
	extern _detail::Proc_wglSaveBufferRegionARB SaveBufferRegionARB;
	extern _detail::Proc_wglRestoreBufferRegionARB RestoreBufferRegionARB;
	
	namespace _detail
	{
		typedef HGLRC (CODEGEN_FUNCPTR * Proc_wglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int *attribList);
	}
	
	extern _detail::Proc_wglCreateContextAttribsARB CreateContextAttribsARB;
	
	namespace _detail
	{
		typedef const char * (CODEGEN_FUNCPTR * Proc_wglGetExtensionsStringARB)(HDC hdc);
	}
	
	extern _detail::Proc_wglGetExtensionsStringARB GetExtensionsStringARB;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglMakeContextCurrentARB)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
		typedef HDC (CODEGEN_FUNCPTR * Proc_wglGetCurrentReadDCARB)();
	}
	
	extern _detail::Proc_wglMakeContextCurrentARB MakeContextCurrentARB;
	extern _detail::Proc_wglGetCurrentReadDCARB GetCurrentReadDCARB;
	
	namespace _detail
	{
		typedef HPBUFFERARB (CODEGEN_FUNCPTR * Proc_wglCreatePbufferARB)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
		typedef HDC (CODEGEN_FUNCPTR * Proc_wglGetPbufferDCARB)(HPBUFFERARB hPbuffer);
		typedef int (CODEGEN_FUNCPTR * Proc_wglReleasePbufferDCARB)(HPBUFFERARB hPbuffer, HDC hDC);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDestroyPbufferARB)(HPBUFFERARB hPbuffer);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglQueryPbufferARB)(HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
	}
	
	extern _detail::Proc_wglCreatePbufferARB CreatePbufferARB;
	extern _detail::Proc_wglGetPbufferDCARB GetPbufferDCARB;
	extern _detail::Proc_wglReleasePbufferDCARB ReleasePbufferDCARB;
	extern _detail::Proc_wglDestroyPbufferARB DestroyPbufferARB;
	extern _detail::Proc_wglQueryPbufferARB QueryPbufferARB;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetPixelFormatAttribivARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetPixelFormatAttribfvARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglChoosePixelFormatARB)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	}
	
	extern _detail::Proc_wglGetPixelFormatAttribivARB GetPixelFormatAttribivARB;
	extern _detail::Proc_wglGetPixelFormatAttribfvARB GetPixelFormatAttribfvARB;
	extern _detail::Proc_wglChoosePixelFormatARB ChoosePixelFormatARB;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglBindTexImageARB)(HPBUFFERARB hPbuffer, int iBuffer);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglReleaseTexImageARB)(HPBUFFERARB hPbuffer, int iBuffer);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglSetPbufferAttribARB)(HPBUFFERARB hPbuffer, const int *piAttribList);
	}
	
	extern _detail::Proc_wglBindTexImageARB BindTexImageARB;
	extern _detail::Proc_wglReleaseTexImageARB ReleaseTexImageARB;
	extern _detail::Proc_wglSetPbufferAttribARB SetPbufferAttribARB;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglMakeContextCurrentEXT)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
		typedef HDC (CODEGEN_FUNCPTR * Proc_wglGetCurrentReadDCEXT)();
	}
	
	extern _detail::Proc_wglMakeContextCurrentEXT MakeContextCurrentEXT;
	extern _detail::Proc_wglGetCurrentReadDCEXT GetCurrentReadDCEXT;
	
	namespace _detail
	{
		typedef HPBUFFEREXT (CODEGEN_FUNCPTR * Proc_wglCreatePbufferEXT)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
		typedef HDC (CODEGEN_FUNCPTR * Proc_wglGetPbufferDCEXT)(HPBUFFEREXT hPbuffer);
		typedef int (CODEGEN_FUNCPTR * Proc_wglReleasePbufferDCEXT)(HPBUFFEREXT hPbuffer, HDC hDC);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDestroyPbufferEXT)(HPBUFFEREXT hPbuffer);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglQueryPbufferEXT)(HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
	}
	
	extern _detail::Proc_wglCreatePbufferEXT CreatePbufferEXT;
	extern _detail::Proc_wglGetPbufferDCEXT GetPbufferDCEXT;
	extern _detail::Proc_wglReleasePbufferDCEXT ReleasePbufferDCEXT;
	extern _detail::Proc_wglDestroyPbufferEXT DestroyPbufferEXT;
	extern _detail::Proc_wglQueryPbufferEXT QueryPbufferEXT;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetPixelFormatAttribivEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetPixelFormatAttribfvEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglChoosePixelFormatEXT)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	}
	
	extern _detail::Proc_wglGetPixelFormatAttribivEXT GetPixelFormatAttribivEXT;
	extern _detail::Proc_wglGetPixelFormatAttribfvEXT GetPixelFormatAttribfvEXT;
	extern _detail::Proc_wglChoosePixelFormatEXT ChoosePixelFormatEXT;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglSwapIntervalEXT)(int interval);
		typedef int (CODEGEN_FUNCPTR * Proc_wglGetSwapIntervalEXT)();
	}
	
	extern _detail::Proc_wglSwapIntervalEXT SwapIntervalEXT;
	extern _detail::Proc_wglGetSwapIntervalEXT GetSwapIntervalEXT;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, int *piValue);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglSetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, const int *piValue);
	}
	
	extern _detail::Proc_wglGetDigitalVideoParametersI3D GetDigitalVideoParametersI3D;
	extern _detail::Proc_wglSetDigitalVideoParametersI3D SetDigitalVideoParametersI3D;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetGammaTableParametersI3D)(HDC hDC, int iAttribute, int *piValue);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglSetGammaTableParametersI3D)(HDC hDC, int iAttribute, const int *piValue);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetGammaTableI3D)(HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglSetGammaTableI3D)(HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
	}
	
	extern _detail::Proc_wglGetGammaTableParametersI3D GetGammaTableParametersI3D;
	extern _detail::Proc_wglSetGammaTableParametersI3D SetGammaTableParametersI3D;
	extern _detail::Proc_wglGetGammaTableI3D GetGammaTableI3D;
	extern _detail::Proc_wglSetGammaTableI3D SetGammaTableI3D;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglEnableGenlockI3D)(HDC hDC);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDisableGenlockI3D)(HDC hDC);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglIsEnabledGenlockI3D)(HDC hDC, BOOL *pFlag);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGenlockSourceI3D)(HDC hDC, UINT uSource);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetGenlockSourceI3D)(HDC hDC, UINT *uSource);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGenlockSourceEdgeI3D)(HDC hDC, UINT uEdge);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetGenlockSourceEdgeI3D)(HDC hDC, UINT *uEdge);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGenlockSampleRateI3D)(HDC hDC, UINT uRate);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetGenlockSampleRateI3D)(HDC hDC, UINT *uRate);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGenlockSourceDelayI3D)(HDC hDC, UINT uDelay);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetGenlockSourceDelayI3D)(HDC hDC, UINT *uDelay);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglQueryGenlockMaxSourceDelayI3D)(HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
	}
	
	extern _detail::Proc_wglEnableGenlockI3D EnableGenlockI3D;
	extern _detail::Proc_wglDisableGenlockI3D DisableGenlockI3D;
	extern _detail::Proc_wglIsEnabledGenlockI3D IsEnabledGenlockI3D;
	extern _detail::Proc_wglGenlockSourceI3D GenlockSourceI3D;
	extern _detail::Proc_wglGetGenlockSourceI3D GetGenlockSourceI3D;
	extern _detail::Proc_wglGenlockSourceEdgeI3D GenlockSourceEdgeI3D;
	extern _detail::Proc_wglGetGenlockSourceEdgeI3D GetGenlockSourceEdgeI3D;
	extern _detail::Proc_wglGenlockSampleRateI3D GenlockSampleRateI3D;
	extern _detail::Proc_wglGetGenlockSampleRateI3D GetGenlockSampleRateI3D;
	extern _detail::Proc_wglGenlockSourceDelayI3D GenlockSourceDelayI3D;
	extern _detail::Proc_wglGetGenlockSourceDelayI3D GetGenlockSourceDelayI3D;
	extern _detail::Proc_wglQueryGenlockMaxSourceDelayI3D QueryGenlockMaxSourceDelayI3D;
	
	namespace _detail
	{
		typedef LPVOID (CODEGEN_FUNCPTR * Proc_wglCreateImageBufferI3D)(HDC hDC, DWORD dwSize, UINT uFlags);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDestroyImageBufferI3D)(HDC hDC, LPVOID pAddress);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglAssociateImageBufferEventsI3D)(HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglReleaseImageBufferEventsI3D)(HDC hDC, const LPVOID *pAddress, UINT count);
	}
	
	extern _detail::Proc_wglCreateImageBufferI3D CreateImageBufferI3D;
	extern _detail::Proc_wglDestroyImageBufferI3D DestroyImageBufferI3D;
	extern _detail::Proc_wglAssociateImageBufferEventsI3D AssociateImageBufferEventsI3D;
	extern _detail::Proc_wglReleaseImageBufferEventsI3D ReleaseImageBufferEventsI3D;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglEnableFrameLockI3D)();
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDisableFrameLockI3D)();
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglIsEnabledFrameLockI3D)(BOOL *pFlag);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglQueryFrameLockMasterI3D)(BOOL *pFlag);
	}
	
	extern _detail::Proc_wglEnableFrameLockI3D EnableFrameLockI3D;
	extern _detail::Proc_wglDisableFrameLockI3D DisableFrameLockI3D;
	extern _detail::Proc_wglIsEnabledFrameLockI3D IsEnabledFrameLockI3D;
	extern _detail::Proc_wglQueryFrameLockMasterI3D QueryFrameLockMasterI3D;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDXSetResourceShareHandleNV)(void *dxObject, HANDLE shareHandle);
		typedef HANDLE (CODEGEN_FUNCPTR * Proc_wglDXOpenDeviceNV)(void *dxDevice);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDXCloseDeviceNV)(HANDLE hDevice);
		typedef HANDLE (CODEGEN_FUNCPTR * Proc_wglDXRegisterObjectNV)(HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDXUnregisterObjectNV)(HANDLE hDevice, HANDLE hObject);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDXObjectAccessNV)(HANDLE hObject, GLenum access);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDXLockObjectsNV)(HANDLE hDevice, GLint count, HANDLE *hObjects);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDXUnlockObjectsNV)(HANDLE hDevice, GLint count, HANDLE *hObjects);
	}
	
	extern _detail::Proc_wglDXSetResourceShareHandleNV DXSetResourceShareHandleNV;
	extern _detail::Proc_wglDXOpenDeviceNV DXOpenDeviceNV;
	extern _detail::Proc_wglDXCloseDeviceNV DXCloseDeviceNV;
	extern _detail::Proc_wglDXRegisterObjectNV DXRegisterObjectNV;
	extern _detail::Proc_wglDXUnregisterObjectNV DXUnregisterObjectNV;
	extern _detail::Proc_wglDXObjectAccessNV DXObjectAccessNV;
	extern _detail::Proc_wglDXLockObjectsNV DXLockObjectsNV;
	extern _detail::Proc_wglDXUnlockObjectsNV DXUnlockObjectsNV;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglCopyImageSubDataNV)(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
	}
	
	extern _detail::Proc_wglCopyImageSubDataNV CopyImageSubDataNV;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglEnumGpusNV)(UINT iGpuIndex, HGPUNV *phGpu);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglEnumGpuDevicesNV)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
		typedef HDC (CODEGEN_FUNCPTR * Proc_wglCreateAffinityDCNV)(const HGPUNV *phGpuList);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglEnumGpusFromAffinityDCNV)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglDeleteDCNV)(HDC hdc);
	}
	
	extern _detail::Proc_wglEnumGpusNV EnumGpusNV;
	extern _detail::Proc_wglEnumGpuDevicesNV EnumGpuDevicesNV;
	extern _detail::Proc_wglCreateAffinityDCNV CreateAffinityDCNV;
	extern _detail::Proc_wglEnumGpusFromAffinityDCNV EnumGpusFromAffinityDCNV;
	extern _detail::Proc_wglDeleteDCNV DeleteDCNV;
	
	namespace _detail
	{
		typedef int (CODEGEN_FUNCPTR * Proc_wglEnumerateVideoDevicesNV)(HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglBindVideoDeviceNV)(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglQueryCurrentContextNV)(int iAttribute, int *piValue);
	}
	
	extern _detail::Proc_wglEnumerateVideoDevicesNV EnumerateVideoDevicesNV;
	extern _detail::Proc_wglBindVideoDeviceNV BindVideoDeviceNV;
	extern _detail::Proc_wglQueryCurrentContextNV QueryCurrentContextNV;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglJoinSwapGroupNV)(HDC hDC, GLuint group);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglBindSwapBarrierNV)(GLuint group, GLuint barrier);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglQuerySwapGroupNV)(HDC hDC, GLuint *group, GLuint *barrier);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglQueryMaxSwapGroupsNV)(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglQueryFrameCountNV)(HDC hDC, GLuint *count);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglResetFrameCountNV)(HDC hDC);
	}
	
	extern _detail::Proc_wglJoinSwapGroupNV JoinSwapGroupNV;
	extern _detail::Proc_wglBindSwapBarrierNV BindSwapBarrierNV;
	extern _detail::Proc_wglQuerySwapGroupNV QuerySwapGroupNV;
	extern _detail::Proc_wglQueryMaxSwapGroupsNV QueryMaxSwapGroupsNV;
	extern _detail::Proc_wglQueryFrameCountNV QueryFrameCountNV;
	extern _detail::Proc_wglResetFrameCountNV ResetFrameCountNV;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglBindVideoCaptureDeviceNV)(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
		typedef UINT (CODEGEN_FUNCPTR * Proc_wglEnumerateVideoCaptureDevicesNV)(HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglLockVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglQueryVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglReleaseVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	}
	
	extern _detail::Proc_wglBindVideoCaptureDeviceNV BindVideoCaptureDeviceNV;
	extern _detail::Proc_wglEnumerateVideoCaptureDevicesNV EnumerateVideoCaptureDevicesNV;
	extern _detail::Proc_wglLockVideoCaptureDeviceNV LockVideoCaptureDeviceNV;
	extern _detail::Proc_wglQueryVideoCaptureDeviceNV QueryVideoCaptureDeviceNV;
	extern _detail::Proc_wglReleaseVideoCaptureDeviceNV ReleaseVideoCaptureDeviceNV;
	
	namespace _detail
	{
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetVideoDeviceNV)(HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglReleaseVideoDeviceNV)(HPVIDEODEV hVideoDevice);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglBindVideoImageNV)(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglReleaseVideoImageNV)(HPBUFFERARB hPbuffer, int iVideoBuffer);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglSendPbufferToVideoNV)(HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
		typedef BOOL (CODEGEN_FUNCPTR * Proc_wglGetVideoInfoNV)(HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
	}
	
	extern _detail::Proc_wglGetVideoDeviceNV GetVideoDeviceNV;
	extern _detail::Proc_wglReleaseVideoDeviceNV ReleaseVideoDeviceNV;
	extern _detail::Proc_wglBindVideoImageNV BindVideoImageNV;
	extern _detail::Proc_wglReleaseVideoImageNV ReleaseVideoImageNV;
	extern _detail::Proc_wglSendPbufferToVideoNV SendPbufferToVideoNV;
	extern _detail::Proc_wglGetVideoInfoNV GetVideoInfoNV;
	
}
#endif /*WINDOWSGL_GEN_EXTENSIONS_HPP*/
