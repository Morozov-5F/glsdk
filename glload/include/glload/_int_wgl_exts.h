#ifndef WINDOWSGL_GEN_EXTENSIONS_H
#define WINDOWSGL_GEN_EXTENSIONS_H


#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
extern int wglext_3DFX_multisample;
extern int wglext_3DL_stereo_control;
extern int wglext_AMD_gpu_association;
extern int wglext_ARB_buffer_region;
extern int wglext_ARB_create_context;
extern int wglext_ARB_create_context_profile;
extern int wglext_ARB_create_context_robustness;
extern int wglext_ARB_extensions_string;
extern int wglext_ARB_framebuffer_sRGB;
extern int wglext_ARB_make_current_read;
extern int wglext_ARB_multisample;
extern int wglext_ARB_pbuffer;
extern int wglext_ARB_pixel_format;
extern int wglext_ARB_pixel_format_float;
extern int wglext_ARB_render_texture;
extern int wglext_ATI_pixel_format_float;
extern int wglext_EXT_create_context_es2_profile;
extern int wglext_EXT_depth_float;
extern int wglext_EXT_framebuffer_sRGB;
extern int wglext_EXT_make_current_read;
extern int wglext_EXT_multisample;
extern int wglext_EXT_pbuffer;
extern int wglext_EXT_pixel_format;
extern int wglext_EXT_pixel_format_packed_float;
extern int wglext_EXT_swap_control;
extern int wglext_EXT_swap_control_tear;
extern int wglext_I3D_digital_video_control;
extern int wglext_I3D_gamma;
extern int wglext_I3D_genlock;
extern int wglext_I3D_image_buffer;
extern int wglext_I3D_swap_frame_lock;
extern int wglext_NV_DX_interop;
extern int wglext_NV_DX_interop2;
extern int wglext_NV_copy_image;
extern int wglext_NV_float_buffer;
extern int wglext_NV_gpu_affinity;
extern int wglext_NV_multisample_coverage;
extern int wglext_NV_present_video;
extern int wglext_NV_render_depth_texture;
extern int wglext_NV_render_texture_rectangle;
extern int wglext_NV_swap_group;
extern int wglext_NV_video_capture;
extern int wglext_NV_video_output;

#define WGL_SAMPLE_BUFFERS_3DFX 0x2060
#define WGL_SAMPLES_3DFX 0x2061

#define WGL_STEREO_EMITTER_ENABLE_3DL 0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL 0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL 0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL 0x2058

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLSETSTEREOEMITTERSTATE3DLPROC)(HDC , UINT );

extern PFNWGLSETSTEREOEMITTERSTATE3DLPROC _funcptr_wglSetStereoEmitterState3DL;
#define wglSetStereoEmitterState3DL _funcptr_wglSetStereoEmitterState3DL

#define WGL_GPU_VENDOR_AMD 0x1F00
#define WGL_GPU_RENDERER_STRING_AMD 0x1F01
#define WGL_GPU_OPENGL_VERSION_STRING_AMD 0x1F02
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD 0x21A2
#define WGL_GPU_RAM_AMD 0x21A3
#define WGL_GPU_CLOCK_AMD 0x21A4
#define WGL_GPU_NUM_PIPES_AMD 0x21A5
#define WGL_GPU_NUM_SIMD_AMD 0x21A6
#define WGL_GPU_NUM_RB_AMD 0x21A7
#define WGL_GPU_NUM_SPI_AMD 0x21A8

typedef UINT (CODEGEN_FUNCPTR * PFNWGLGETGPUIDSAMDPROC)(UINT , UINT *);
typedef INT (CODEGEN_FUNCPTR * PFNWGLGETGPUINFOAMDPROC)(UINT , int , GLenum , UINT , void *);
typedef UINT (CODEGEN_FUNCPTR * PFNWGLGETCONTEXTGPUIDAMDPROC)(HGLRC );
typedef HGLRC (CODEGEN_FUNCPTR * PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)(UINT );
typedef HGLRC (CODEGEN_FUNCPTR * PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)(UINT , HGLRC , const int *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)(HGLRC );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)(HGLRC );
typedef HGLRC (CODEGEN_FUNCPTR * PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)();
typedef VOID (CODEGEN_FUNCPTR * PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)(HGLRC , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLbitfield , GLenum );

extern PFNWGLGETGPUIDSAMDPROC _funcptr_wglGetGPUIDsAMD;
#define wglGetGPUIDsAMD _funcptr_wglGetGPUIDsAMD
extern PFNWGLGETGPUINFOAMDPROC _funcptr_wglGetGPUInfoAMD;
#define wglGetGPUInfoAMD _funcptr_wglGetGPUInfoAMD
extern PFNWGLGETCONTEXTGPUIDAMDPROC _funcptr_wglGetContextGPUIDAMD;
#define wglGetContextGPUIDAMD _funcptr_wglGetContextGPUIDAMD
extern PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC _funcptr_wglCreateAssociatedContextAMD;
#define wglCreateAssociatedContextAMD _funcptr_wglCreateAssociatedContextAMD
extern PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC _funcptr_wglCreateAssociatedContextAttribsAMD;
#define wglCreateAssociatedContextAttribsAMD _funcptr_wglCreateAssociatedContextAttribsAMD
extern PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC _funcptr_wglDeleteAssociatedContextAMD;
#define wglDeleteAssociatedContextAMD _funcptr_wglDeleteAssociatedContextAMD
extern PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC _funcptr_wglMakeAssociatedContextCurrentAMD;
#define wglMakeAssociatedContextCurrentAMD _funcptr_wglMakeAssociatedContextCurrentAMD
extern PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC _funcptr_wglGetCurrentAssociatedContextAMD;
#define wglGetCurrentAssociatedContextAMD _funcptr_wglGetCurrentAssociatedContextAMD
extern PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC _funcptr_wglBlitContextFramebufferAMD;
#define wglBlitContextFramebufferAMD _funcptr_wglBlitContextFramebufferAMD

#define WGL_FRONT_COLOR_BUFFER_BIT_ARB 0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB 0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB 0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB 0x00000008

typedef HANDLE (CODEGEN_FUNCPTR * PFNWGLCREATEBUFFERREGIONARBPROC)(HDC , int , UINT );
typedef VOID (CODEGEN_FUNCPTR * PFNWGLDELETEBUFFERREGIONARBPROC)(HANDLE );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLSAVEBUFFERREGIONARBPROC)(HANDLE , int , int , int , int );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLRESTOREBUFFERREGIONARBPROC)(HANDLE , int , int , int , int , int , int );

extern PFNWGLCREATEBUFFERREGIONARBPROC _funcptr_wglCreateBufferRegionARB;
#define wglCreateBufferRegionARB _funcptr_wglCreateBufferRegionARB
extern PFNWGLDELETEBUFFERREGIONARBPROC _funcptr_wglDeleteBufferRegionARB;
#define wglDeleteBufferRegionARB _funcptr_wglDeleteBufferRegionARB
extern PFNWGLSAVEBUFFERREGIONARBPROC _funcptr_wglSaveBufferRegionARB;
#define wglSaveBufferRegionARB _funcptr_wglSaveBufferRegionARB
extern PFNWGLRESTOREBUFFERREGIONARBPROC _funcptr_wglRestoreBufferRegionARB;
#define wglRestoreBufferRegionARB _funcptr_wglRestoreBufferRegionARB

#define WGL_CONTEXT_DEBUG_BIT_ARB 0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002
#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB 0x2093
#define WGL_CONTEXT_FLAGS_ARB 0x2094
#define WGL_ERROR_INVALID_VERSION_ARB 0x2095

typedef HGLRC (CODEGEN_FUNCPTR * PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC , HGLRC , const int *);

extern PFNWGLCREATECONTEXTATTRIBSARBPROC _funcptr_wglCreateContextAttribsARB;
#define wglCreateContextAttribsARB _funcptr_wglCreateContextAttribsARB

#define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define WGL_ERROR_INVALID_PROFILE_ARB 0x2096

#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB 0x00000004
#define WGL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define WGL_NO_RESET_NOTIFICATION_ARB 0x8261

typedef const char * (CODEGEN_FUNCPTR * PFNWGLGETEXTENSIONSSTRINGARBPROC)(HDC );

extern PFNWGLGETEXTENSIONSSTRINGARBPROC _funcptr_wglGetExtensionsStringARB;
#define wglGetExtensionsStringARB _funcptr_wglGetExtensionsStringARB

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB 0x20A9

#define WGL_ERROR_INVALID_PIXEL_TYPE_ARB 0x2043
#define WGL_ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB 0x2054

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLMAKECONTEXTCURRENTARBPROC)(HDC , HDC , HGLRC );
typedef HDC (CODEGEN_FUNCPTR * PFNWGLGETCURRENTREADDCARBPROC)();

extern PFNWGLMAKECONTEXTCURRENTARBPROC _funcptr_wglMakeContextCurrentARB;
#define wglMakeContextCurrentARB _funcptr_wglMakeContextCurrentARB
extern PFNWGLGETCURRENTREADDCARBPROC _funcptr_wglGetCurrentReadDCARB;
#define wglGetCurrentReadDCARB _funcptr_wglGetCurrentReadDCARB

#define WGL_SAMPLE_BUFFERS_ARB 0x2041
#define WGL_SAMPLES_ARB 0x2042

#define WGL_TRANSPARENT_RED_VALUE_ARB 0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB 0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB 0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB 0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB 0x203B
#define WGL_DRAW_TO_PBUFFER_ARB 0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB 0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB 0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB 0x2030
#define WGL_PBUFFER_LARGEST_ARB 0x2033
#define WGL_PBUFFER_WIDTH_ARB 0x2034
#define WGL_PBUFFER_HEIGHT_ARB 0x2035
#define WGL_PBUFFER_LOST_ARB 0x2036

typedef HPBUFFERARB (CODEGEN_FUNCPTR * PFNWGLCREATEPBUFFERARBPROC)(HDC , int , int , int , const int *);
typedef HDC (CODEGEN_FUNCPTR * PFNWGLGETPBUFFERDCARBPROC)(HPBUFFERARB );
typedef int (CODEGEN_FUNCPTR * PFNWGLRELEASEPBUFFERDCARBPROC)(HPBUFFERARB , HDC );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDESTROYPBUFFERARBPROC)(HPBUFFERARB );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLQUERYPBUFFERARBPROC)(HPBUFFERARB , int , int *);

extern PFNWGLCREATEPBUFFERARBPROC _funcptr_wglCreatePbufferARB;
#define wglCreatePbufferARB _funcptr_wglCreatePbufferARB
extern PFNWGLGETPBUFFERDCARBPROC _funcptr_wglGetPbufferDCARB;
#define wglGetPbufferDCARB _funcptr_wglGetPbufferDCARB
extern PFNWGLRELEASEPBUFFERDCARBPROC _funcptr_wglReleasePbufferDCARB;
#define wglReleasePbufferDCARB _funcptr_wglReleasePbufferDCARB
extern PFNWGLDESTROYPBUFFERARBPROC _funcptr_wglDestroyPbufferARB;
#define wglDestroyPbufferARB _funcptr_wglDestroyPbufferARB
extern PFNWGLQUERYPBUFFERARBPROC _funcptr_wglQueryPbufferARB;
#define wglQueryPbufferARB _funcptr_wglQueryPbufferARB

#define WGL_NUMBER_PIXEL_FORMATS_ARB 0x2000
#define WGL_DRAW_TO_WINDOW_ARB 0x2001
#define WGL_DRAW_TO_BITMAP_ARB 0x2002
#define WGL_ACCELERATION_ARB 0x2003
#define WGL_NEED_PALETTE_ARB 0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB 0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB 0x2006
#define WGL_SWAP_METHOD_ARB 0x2007
#define WGL_NUMBER_OVERLAYS_ARB 0x2008
#define WGL_NUMBER_UNDERLAYS_ARB 0x2009
#define WGL_TRANSPARENT_ARB 0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB 0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB 0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB 0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB 0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB 0x203B
#define WGL_SHARE_DEPTH_ARB 0x200C
#define WGL_SHARE_STENCIL_ARB 0x200D
#define WGL_SHARE_ACCUM_ARB 0x200E
#define WGL_SUPPORT_GDI_ARB 0x200F
#define WGL_SUPPORT_OPENGL_ARB 0x2010
#define WGL_DOUBLE_BUFFER_ARB 0x2011
#define WGL_STEREO_ARB 0x2012
#define WGL_PIXEL_TYPE_ARB 0x2013
#define WGL_COLOR_BITS_ARB 0x2014
#define WGL_RED_BITS_ARB 0x2015
#define WGL_RED_SHIFT_ARB 0x2016
#define WGL_GREEN_BITS_ARB 0x2017
#define WGL_GREEN_SHIFT_ARB 0x2018
#define WGL_BLUE_BITS_ARB 0x2019
#define WGL_BLUE_SHIFT_ARB 0x201A
#define WGL_ALPHA_BITS_ARB 0x201B
#define WGL_ALPHA_SHIFT_ARB 0x201C
#define WGL_ACCUM_BITS_ARB 0x201D
#define WGL_ACCUM_RED_BITS_ARB 0x201E
#define WGL_ACCUM_GREEN_BITS_ARB 0x201F
#define WGL_ACCUM_BLUE_BITS_ARB 0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB 0x2021
#define WGL_DEPTH_BITS_ARB 0x2022
#define WGL_STENCIL_BITS_ARB 0x2023
#define WGL_AUX_BUFFERS_ARB 0x2024
#define WGL_NO_ACCELERATION_ARB 0x2025
#define WGL_GENERIC_ACCELERATION_ARB 0x2026
#define WGL_FULL_ACCELERATION_ARB 0x2027
#define WGL_SWAP_EXCHANGE_ARB 0x2028
#define WGL_SWAP_COPY_ARB 0x2029
#define WGL_SWAP_UNDEFINED_ARB 0x202A
#define WGL_TYPE_RGBA_ARB 0x202B
#define WGL_TYPE_COLORINDEX_ARB 0x202C

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBIVARBPROC)(HDC , int , int , UINT , const int *, int *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBFVARBPROC)(HDC , int , int , UINT , const int *, FLOAT *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC , const int *, const FLOAT *, UINT , int *, UINT *);

extern PFNWGLGETPIXELFORMATATTRIBIVARBPROC _funcptr_wglGetPixelFormatAttribivARB;
#define wglGetPixelFormatAttribivARB _funcptr_wglGetPixelFormatAttribivARB
extern PFNWGLGETPIXELFORMATATTRIBFVARBPROC _funcptr_wglGetPixelFormatAttribfvARB;
#define wglGetPixelFormatAttribfvARB _funcptr_wglGetPixelFormatAttribfvARB
extern PFNWGLCHOOSEPIXELFORMATARBPROC _funcptr_wglChoosePixelFormatARB;
#define wglChoosePixelFormatARB _funcptr_wglChoosePixelFormatARB

#define WGL_TYPE_RGBA_FLOAT_ARB 0x21A0

#define WGL_BIND_TO_TEXTURE_RGB_ARB 0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB 0x2071
#define WGL_TEXTURE_FORMAT_ARB 0x2072
#define WGL_TEXTURE_TARGET_ARB 0x2073
#define WGL_MIPMAP_TEXTURE_ARB 0x2074
#define WGL_TEXTURE_RGB_ARB 0x2075
#define WGL_TEXTURE_RGBA_ARB 0x2076
#define WGL_NO_TEXTURE_ARB 0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB 0x2078
#define WGL_TEXTURE_1D_ARB 0x2079
#define WGL_TEXTURE_2D_ARB 0x207A
#define WGL_MIPMAP_LEVEL_ARB 0x207B
#define WGL_CUBE_MAP_FACE_ARB 0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x2082
#define WGL_FRONT_LEFT_ARB 0x2083
#define WGL_FRONT_RIGHT_ARB 0x2084
#define WGL_BACK_LEFT_ARB 0x2085
#define WGL_BACK_RIGHT_ARB 0x2086
#define WGL_AUX0_ARB 0x2087
#define WGL_AUX1_ARB 0x2088
#define WGL_AUX2_ARB 0x2089
#define WGL_AUX3_ARB 0x208A
#define WGL_AUX4_ARB 0x208B
#define WGL_AUX5_ARB 0x208C
#define WGL_AUX6_ARB 0x208D
#define WGL_AUX7_ARB 0x208E
#define WGL_AUX8_ARB 0x208F
#define WGL_AUX9_ARB 0x2090

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLBINDTEXIMAGEARBPROC)(HPBUFFERARB , int );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLRELEASETEXIMAGEARBPROC)(HPBUFFERARB , int );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLSETPBUFFERATTRIBARBPROC)(HPBUFFERARB , const int *);

extern PFNWGLBINDTEXIMAGEARBPROC _funcptr_wglBindTexImageARB;
#define wglBindTexImageARB _funcptr_wglBindTexImageARB
extern PFNWGLRELEASETEXIMAGEARBPROC _funcptr_wglReleaseTexImageARB;
#define wglReleaseTexImageARB _funcptr_wglReleaseTexImageARB
extern PFNWGLSETPBUFFERATTRIBARBPROC _funcptr_wglSetPbufferAttribARB;
#define wglSetPbufferAttribARB _funcptr_wglSetPbufferAttribARB

#define WGL_TYPE_RGBA_FLOAT_ATI 0x21A0

#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT 0x00000004

#define WGL_DEPTH_FLOAT_EXT 0x2040

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x20A9

#define WGL_ERROR_INVALID_PIXEL_TYPE_EXT 0x2043

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLMAKECONTEXTCURRENTEXTPROC)(HDC , HDC , HGLRC );
typedef HDC (CODEGEN_FUNCPTR * PFNWGLGETCURRENTREADDCEXTPROC)();

extern PFNWGLMAKECONTEXTCURRENTEXTPROC _funcptr_wglMakeContextCurrentEXT;
#define wglMakeContextCurrentEXT _funcptr_wglMakeContextCurrentEXT
extern PFNWGLGETCURRENTREADDCEXTPROC _funcptr_wglGetCurrentReadDCEXT;
#define wglGetCurrentReadDCEXT _funcptr_wglGetCurrentReadDCEXT

#define WGL_SAMPLE_BUFFERS_EXT 0x2041
#define WGL_SAMPLES_EXT 0x2042

#define WGL_DRAW_TO_PBUFFER_EXT 0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT 0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT 0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT 0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT 0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT 0x2032
#define WGL_PBUFFER_LARGEST_EXT 0x2033
#define WGL_PBUFFER_WIDTH_EXT 0x2034
#define WGL_PBUFFER_HEIGHT_EXT 0x2035

typedef HPBUFFEREXT (CODEGEN_FUNCPTR * PFNWGLCREATEPBUFFEREXTPROC)(HDC , int , int , int , const int *);
typedef HDC (CODEGEN_FUNCPTR * PFNWGLGETPBUFFERDCEXTPROC)(HPBUFFEREXT );
typedef int (CODEGEN_FUNCPTR * PFNWGLRELEASEPBUFFERDCEXTPROC)(HPBUFFEREXT , HDC );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDESTROYPBUFFEREXTPROC)(HPBUFFEREXT );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLQUERYPBUFFEREXTPROC)(HPBUFFEREXT , int , int *);

extern PFNWGLCREATEPBUFFEREXTPROC _funcptr_wglCreatePbufferEXT;
#define wglCreatePbufferEXT _funcptr_wglCreatePbufferEXT
extern PFNWGLGETPBUFFERDCEXTPROC _funcptr_wglGetPbufferDCEXT;
#define wglGetPbufferDCEXT _funcptr_wglGetPbufferDCEXT
extern PFNWGLRELEASEPBUFFERDCEXTPROC _funcptr_wglReleasePbufferDCEXT;
#define wglReleasePbufferDCEXT _funcptr_wglReleasePbufferDCEXT
extern PFNWGLDESTROYPBUFFEREXTPROC _funcptr_wglDestroyPbufferEXT;
#define wglDestroyPbufferEXT _funcptr_wglDestroyPbufferEXT
extern PFNWGLQUERYPBUFFEREXTPROC _funcptr_wglQueryPbufferEXT;
#define wglQueryPbufferEXT _funcptr_wglQueryPbufferEXT

#define WGL_NUMBER_PIXEL_FORMATS_EXT 0x2000
#define WGL_DRAW_TO_WINDOW_EXT 0x2001
#define WGL_DRAW_TO_BITMAP_EXT 0x2002
#define WGL_ACCELERATION_EXT 0x2003
#define WGL_NEED_PALETTE_EXT 0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT 0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT 0x2006
#define WGL_SWAP_METHOD_EXT 0x2007
#define WGL_NUMBER_OVERLAYS_EXT 0x2008
#define WGL_NUMBER_UNDERLAYS_EXT 0x2009
#define WGL_TRANSPARENT_EXT 0x200A
#define WGL_TRANSPARENT_VALUE_EXT 0x200B
#define WGL_SHARE_DEPTH_EXT 0x200C
#define WGL_SHARE_STENCIL_EXT 0x200D
#define WGL_SHARE_ACCUM_EXT 0x200E
#define WGL_SUPPORT_GDI_EXT 0x200F
#define WGL_SUPPORT_OPENGL_EXT 0x2010
#define WGL_DOUBLE_BUFFER_EXT 0x2011
#define WGL_STEREO_EXT 0x2012
#define WGL_PIXEL_TYPE_EXT 0x2013
#define WGL_COLOR_BITS_EXT 0x2014
#define WGL_RED_BITS_EXT 0x2015
#define WGL_RED_SHIFT_EXT 0x2016
#define WGL_GREEN_BITS_EXT 0x2017
#define WGL_GREEN_SHIFT_EXT 0x2018
#define WGL_BLUE_BITS_EXT 0x2019
#define WGL_BLUE_SHIFT_EXT 0x201A
#define WGL_ALPHA_BITS_EXT 0x201B
#define WGL_ALPHA_SHIFT_EXT 0x201C
#define WGL_ACCUM_BITS_EXT 0x201D
#define WGL_ACCUM_RED_BITS_EXT 0x201E
#define WGL_ACCUM_GREEN_BITS_EXT 0x201F
#define WGL_ACCUM_BLUE_BITS_EXT 0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT 0x2021
#define WGL_DEPTH_BITS_EXT 0x2022
#define WGL_STENCIL_BITS_EXT 0x2023
#define WGL_AUX_BUFFERS_EXT 0x2024
#define WGL_NO_ACCELERATION_EXT 0x2025
#define WGL_GENERIC_ACCELERATION_EXT 0x2026
#define WGL_FULL_ACCELERATION_EXT 0x2027
#define WGL_SWAP_EXCHANGE_EXT 0x2028
#define WGL_SWAP_COPY_EXT 0x2029
#define WGL_SWAP_UNDEFINED_EXT 0x202A
#define WGL_TYPE_RGBA_EXT 0x202B
#define WGL_TYPE_COLORINDEX_EXT 0x202C

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)(HDC , int , int , UINT , int *, int *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)(HDC , int , int , UINT , int *, FLOAT *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLCHOOSEPIXELFORMATEXTPROC)(HDC , const int *, const FLOAT *, UINT , int *, UINT *);

extern PFNWGLGETPIXELFORMATATTRIBIVEXTPROC _funcptr_wglGetPixelFormatAttribivEXT;
#define wglGetPixelFormatAttribivEXT _funcptr_wglGetPixelFormatAttribivEXT
extern PFNWGLGETPIXELFORMATATTRIBFVEXTPROC _funcptr_wglGetPixelFormatAttribfvEXT;
#define wglGetPixelFormatAttribfvEXT _funcptr_wglGetPixelFormatAttribfvEXT
extern PFNWGLCHOOSEPIXELFORMATEXTPROC _funcptr_wglChoosePixelFormatEXT;
#define wglChoosePixelFormatEXT _funcptr_wglChoosePixelFormatEXT

#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT 0x20A8

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLSWAPINTERVALEXTPROC)(int );
typedef int (CODEGEN_FUNCPTR * PFNWGLGETSWAPINTERVALEXTPROC)();

extern PFNWGLSWAPINTERVALEXTPROC _funcptr_wglSwapIntervalEXT;
#define wglSwapIntervalEXT _funcptr_wglSwapIntervalEXT
extern PFNWGLGETSWAPINTERVALEXTPROC _funcptr_wglGetSwapIntervalEXT;
#define wglGetSwapIntervalEXT _funcptr_wglGetSwapIntervalEXT

#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D 0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D 0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D 0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D 0x2053

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)(HDC , int , int *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)(HDC , int , const int *);

extern PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC _funcptr_wglGetDigitalVideoParametersI3D;
#define wglGetDigitalVideoParametersI3D _funcptr_wglGetDigitalVideoParametersI3D
extern PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC _funcptr_wglSetDigitalVideoParametersI3D;
#define wglSetDigitalVideoParametersI3D _funcptr_wglSetDigitalVideoParametersI3D

#define WGL_GAMMA_TABLE_SIZE_I3D 0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D 0x204F

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)(HDC , int , int *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)(HDC , int , const int *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETGAMMATABLEI3DPROC)(HDC , int , USHORT *, USHORT *, USHORT *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLSETGAMMATABLEI3DPROC)(HDC , int , const USHORT *, const USHORT *, const USHORT *);

extern PFNWGLGETGAMMATABLEPARAMETERSI3DPROC _funcptr_wglGetGammaTableParametersI3D;
#define wglGetGammaTableParametersI3D _funcptr_wglGetGammaTableParametersI3D
extern PFNWGLSETGAMMATABLEPARAMETERSI3DPROC _funcptr_wglSetGammaTableParametersI3D;
#define wglSetGammaTableParametersI3D _funcptr_wglSetGammaTableParametersI3D
extern PFNWGLGETGAMMATABLEI3DPROC _funcptr_wglGetGammaTableI3D;
#define wglGetGammaTableI3D _funcptr_wglGetGammaTableI3D
extern PFNWGLSETGAMMATABLEI3DPROC _funcptr_wglSetGammaTableI3D;
#define wglSetGammaTableI3D _funcptr_wglSetGammaTableI3D

#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D 0x2044
#define WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D 0x2045
#define WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D 0x2046
#define WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D 0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D 0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D 0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D 0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D 0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D 0x204C

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLENABLEGENLOCKI3DPROC)(HDC );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDISABLEGENLOCKI3DPROC)(HDC );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLISENABLEDGENLOCKI3DPROC)(HDC , BOOL *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGENLOCKSOURCEI3DPROC)(HDC , UINT );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETGENLOCKSOURCEI3DPROC)(HDC , UINT *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGENLOCKSOURCEEDGEI3DPROC)(HDC , UINT );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)(HDC , UINT *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGENLOCKSAMPLERATEI3DPROC)(HDC , UINT );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETGENLOCKSAMPLERATEI3DPROC)(HDC , UINT *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGENLOCKSOURCEDELAYI3DPROC)(HDC , UINT );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)(HDC , UINT *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)(HDC , UINT *, UINT *);

extern PFNWGLENABLEGENLOCKI3DPROC _funcptr_wglEnableGenlockI3D;
#define wglEnableGenlockI3D _funcptr_wglEnableGenlockI3D
extern PFNWGLDISABLEGENLOCKI3DPROC _funcptr_wglDisableGenlockI3D;
#define wglDisableGenlockI3D _funcptr_wglDisableGenlockI3D
extern PFNWGLISENABLEDGENLOCKI3DPROC _funcptr_wglIsEnabledGenlockI3D;
#define wglIsEnabledGenlockI3D _funcptr_wglIsEnabledGenlockI3D
extern PFNWGLGENLOCKSOURCEI3DPROC _funcptr_wglGenlockSourceI3D;
#define wglGenlockSourceI3D _funcptr_wglGenlockSourceI3D
extern PFNWGLGETGENLOCKSOURCEI3DPROC _funcptr_wglGetGenlockSourceI3D;
#define wglGetGenlockSourceI3D _funcptr_wglGetGenlockSourceI3D
extern PFNWGLGENLOCKSOURCEEDGEI3DPROC _funcptr_wglGenlockSourceEdgeI3D;
#define wglGenlockSourceEdgeI3D _funcptr_wglGenlockSourceEdgeI3D
extern PFNWGLGETGENLOCKSOURCEEDGEI3DPROC _funcptr_wglGetGenlockSourceEdgeI3D;
#define wglGetGenlockSourceEdgeI3D _funcptr_wglGetGenlockSourceEdgeI3D
extern PFNWGLGENLOCKSAMPLERATEI3DPROC _funcptr_wglGenlockSampleRateI3D;
#define wglGenlockSampleRateI3D _funcptr_wglGenlockSampleRateI3D
extern PFNWGLGETGENLOCKSAMPLERATEI3DPROC _funcptr_wglGetGenlockSampleRateI3D;
#define wglGetGenlockSampleRateI3D _funcptr_wglGetGenlockSampleRateI3D
extern PFNWGLGENLOCKSOURCEDELAYI3DPROC _funcptr_wglGenlockSourceDelayI3D;
#define wglGenlockSourceDelayI3D _funcptr_wglGenlockSourceDelayI3D
extern PFNWGLGETGENLOCKSOURCEDELAYI3DPROC _funcptr_wglGetGenlockSourceDelayI3D;
#define wglGetGenlockSourceDelayI3D _funcptr_wglGetGenlockSourceDelayI3D
extern PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC _funcptr_wglQueryGenlockMaxSourceDelayI3D;
#define wglQueryGenlockMaxSourceDelayI3D _funcptr_wglQueryGenlockMaxSourceDelayI3D

#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D 0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D 0x00000002

typedef LPVOID (CODEGEN_FUNCPTR * PFNWGLCREATEIMAGEBUFFERI3DPROC)(HDC , DWORD , UINT );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDESTROYIMAGEBUFFERI3DPROC)(HDC , LPVOID );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)(HDC , const HANDLE *, const LPVOID *, const DWORD *, UINT );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)(HDC , const LPVOID *, UINT );

extern PFNWGLCREATEIMAGEBUFFERI3DPROC _funcptr_wglCreateImageBufferI3D;
#define wglCreateImageBufferI3D _funcptr_wglCreateImageBufferI3D
extern PFNWGLDESTROYIMAGEBUFFERI3DPROC _funcptr_wglDestroyImageBufferI3D;
#define wglDestroyImageBufferI3D _funcptr_wglDestroyImageBufferI3D
extern PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC _funcptr_wglAssociateImageBufferEventsI3D;
#define wglAssociateImageBufferEventsI3D _funcptr_wglAssociateImageBufferEventsI3D
extern PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC _funcptr_wglReleaseImageBufferEventsI3D;
#define wglReleaseImageBufferEventsI3D _funcptr_wglReleaseImageBufferEventsI3D

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLENABLEFRAMELOCKI3DPROC)();
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDISABLEFRAMELOCKI3DPROC)();
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLISENABLEDFRAMELOCKI3DPROC)(BOOL *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLQUERYFRAMELOCKMASTERI3DPROC)(BOOL *);

extern PFNWGLENABLEFRAMELOCKI3DPROC _funcptr_wglEnableFrameLockI3D;
#define wglEnableFrameLockI3D _funcptr_wglEnableFrameLockI3D
extern PFNWGLDISABLEFRAMELOCKI3DPROC _funcptr_wglDisableFrameLockI3D;
#define wglDisableFrameLockI3D _funcptr_wglDisableFrameLockI3D
extern PFNWGLISENABLEDFRAMELOCKI3DPROC _funcptr_wglIsEnabledFrameLockI3D;
#define wglIsEnabledFrameLockI3D _funcptr_wglIsEnabledFrameLockI3D
extern PFNWGLQUERYFRAMELOCKMASTERI3DPROC _funcptr_wglQueryFrameLockMasterI3D;
#define wglQueryFrameLockMasterI3D _funcptr_wglQueryFrameLockMasterI3D

#define WGL_ACCESS_READ_ONLY_NV 0x00000000
#define WGL_ACCESS_READ_WRITE_NV 0x00000001
#define WGL_ACCESS_WRITE_DISCARD_NV 0x00000002

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDXSETRESOURCESHAREHANDLENVPROC)(void *, HANDLE );
typedef HANDLE (CODEGEN_FUNCPTR * PFNWGLDXOPENDEVICENVPROC)(void *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDXCLOSEDEVICENVPROC)(HANDLE );
typedef HANDLE (CODEGEN_FUNCPTR * PFNWGLDXREGISTEROBJECTNVPROC)(HANDLE , void *, GLuint , GLenum , GLenum );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDXUNREGISTEROBJECTNVPROC)(HANDLE , HANDLE );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDXOBJECTACCESSNVPROC)(HANDLE , GLenum );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDXLOCKOBJECTSNVPROC)(HANDLE , GLint , HANDLE *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDXUNLOCKOBJECTSNVPROC)(HANDLE , GLint , HANDLE *);

extern PFNWGLDXSETRESOURCESHAREHANDLENVPROC _funcptr_wglDXSetResourceShareHandleNV;
#define wglDXSetResourceShareHandleNV _funcptr_wglDXSetResourceShareHandleNV
extern PFNWGLDXOPENDEVICENVPROC _funcptr_wglDXOpenDeviceNV;
#define wglDXOpenDeviceNV _funcptr_wglDXOpenDeviceNV
extern PFNWGLDXCLOSEDEVICENVPROC _funcptr_wglDXCloseDeviceNV;
#define wglDXCloseDeviceNV _funcptr_wglDXCloseDeviceNV
extern PFNWGLDXREGISTEROBJECTNVPROC _funcptr_wglDXRegisterObjectNV;
#define wglDXRegisterObjectNV _funcptr_wglDXRegisterObjectNV
extern PFNWGLDXUNREGISTEROBJECTNVPROC _funcptr_wglDXUnregisterObjectNV;
#define wglDXUnregisterObjectNV _funcptr_wglDXUnregisterObjectNV
extern PFNWGLDXOBJECTACCESSNVPROC _funcptr_wglDXObjectAccessNV;
#define wglDXObjectAccessNV _funcptr_wglDXObjectAccessNV
extern PFNWGLDXLOCKOBJECTSNVPROC _funcptr_wglDXLockObjectsNV;
#define wglDXLockObjectsNV _funcptr_wglDXLockObjectsNV
extern PFNWGLDXUNLOCKOBJECTSNVPROC _funcptr_wglDXUnlockObjectsNV;
#define wglDXUnlockObjectsNV _funcptr_wglDXUnlockObjectsNV

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLCOPYIMAGESUBDATANVPROC)(HGLRC , GLuint , GLenum , GLint , GLint , GLint , GLint , HGLRC , GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );

extern PFNWGLCOPYIMAGESUBDATANVPROC _funcptr_wglCopyImageSubDataNV;
#define wglCopyImageSubDataNV _funcptr_wglCopyImageSubDataNV

#define WGL_FLOAT_COMPONENTS_NV 0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV 0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV 0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV 0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV 0x20B4
#define WGL_TEXTURE_FLOAT_R_NV 0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV 0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV 0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV 0x20B8

#define WGL_ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV 0x20D0
#define WGL_ERROR_MISSING_AFFINITY_MASK_NV 0x20D1

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLENUMGPUSNVPROC)(UINT , HGPUNV *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLENUMGPUDEVICESNVPROC)(HGPUNV , UINT , PGPU_DEVICE );
typedef HDC (CODEGEN_FUNCPTR * PFNWGLCREATEAFFINITYDCNVPROC)(const HGPUNV *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)(HDC , UINT , HGPUNV *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLDELETEDCNVPROC)(HDC );

extern PFNWGLENUMGPUSNVPROC _funcptr_wglEnumGpusNV;
#define wglEnumGpusNV _funcptr_wglEnumGpusNV
extern PFNWGLENUMGPUDEVICESNVPROC _funcptr_wglEnumGpuDevicesNV;
#define wglEnumGpuDevicesNV _funcptr_wglEnumGpuDevicesNV
extern PFNWGLCREATEAFFINITYDCNVPROC _funcptr_wglCreateAffinityDCNV;
#define wglCreateAffinityDCNV _funcptr_wglCreateAffinityDCNV
extern PFNWGLENUMGPUSFROMAFFINITYDCNVPROC _funcptr_wglEnumGpusFromAffinityDCNV;
#define wglEnumGpusFromAffinityDCNV _funcptr_wglEnumGpusFromAffinityDCNV
extern PFNWGLDELETEDCNVPROC _funcptr_wglDeleteDCNV;
#define wglDeleteDCNV _funcptr_wglDeleteDCNV

#define WGL_COVERAGE_SAMPLES_NV 0x2042
#define WGL_COLOR_SAMPLES_NV 0x20B9

#define WGL_NUM_VIDEO_SLOTS_NV 0x20F0

typedef int (CODEGEN_FUNCPTR * PFNWGLENUMERATEVIDEODEVICESNVPROC)(HDC , HVIDEOOUTPUTDEVICENV *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLBINDVIDEODEVICENVPROC)(HDC , unsigned int , HVIDEOOUTPUTDEVICENV , const int *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLQUERYCURRENTCONTEXTNVPROC)(int , int *);

extern PFNWGLENUMERATEVIDEODEVICESNVPROC _funcptr_wglEnumerateVideoDevicesNV;
#define wglEnumerateVideoDevicesNV _funcptr_wglEnumerateVideoDevicesNV
extern PFNWGLBINDVIDEODEVICENVPROC _funcptr_wglBindVideoDeviceNV;
#define wglBindVideoDeviceNV _funcptr_wglBindVideoDeviceNV
extern PFNWGLQUERYCURRENTCONTEXTNVPROC _funcptr_wglQueryCurrentContextNV;
#define wglQueryCurrentContextNV _funcptr_wglQueryCurrentContextNV

#define WGL_BIND_TO_TEXTURE_DEPTH_NV 0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV 0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV 0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV 0x20A6
#define WGL_DEPTH_COMPONENT_NV 0x20A7

#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV 0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV 0x20A1
#define WGL_TEXTURE_RECTANGLE_NV 0x20A2

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLJOINSWAPGROUPNVPROC)(HDC , GLuint );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLBINDSWAPBARRIERNVPROC)(GLuint , GLuint );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLQUERYSWAPGROUPNVPROC)(HDC , GLuint *, GLuint *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLQUERYMAXSWAPGROUPSNVPROC)(HDC , GLuint *, GLuint *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLQUERYFRAMECOUNTNVPROC)(HDC , GLuint *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLRESETFRAMECOUNTNVPROC)(HDC );

extern PFNWGLJOINSWAPGROUPNVPROC _funcptr_wglJoinSwapGroupNV;
#define wglJoinSwapGroupNV _funcptr_wglJoinSwapGroupNV
extern PFNWGLBINDSWAPBARRIERNVPROC _funcptr_wglBindSwapBarrierNV;
#define wglBindSwapBarrierNV _funcptr_wglBindSwapBarrierNV
extern PFNWGLQUERYSWAPGROUPNVPROC _funcptr_wglQuerySwapGroupNV;
#define wglQuerySwapGroupNV _funcptr_wglQuerySwapGroupNV
extern PFNWGLQUERYMAXSWAPGROUPSNVPROC _funcptr_wglQueryMaxSwapGroupsNV;
#define wglQueryMaxSwapGroupsNV _funcptr_wglQueryMaxSwapGroupsNV
extern PFNWGLQUERYFRAMECOUNTNVPROC _funcptr_wglQueryFrameCountNV;
#define wglQueryFrameCountNV _funcptr_wglQueryFrameCountNV
extern PFNWGLRESETFRAMECOUNTNVPROC _funcptr_wglResetFrameCountNV;
#define wglResetFrameCountNV _funcptr_wglResetFrameCountNV

#define WGL_UNIQUE_ID_NV 0x20CE
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV 0x20CF

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)(UINT , HVIDEOINPUTDEVICENV );
typedef UINT (CODEGEN_FUNCPTR * PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)(HDC , HVIDEOINPUTDEVICENV *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)(HDC , HVIDEOINPUTDEVICENV );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)(HDC , HVIDEOINPUTDEVICENV , int , int *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)(HDC , HVIDEOINPUTDEVICENV );

extern PFNWGLBINDVIDEOCAPTUREDEVICENVPROC _funcptr_wglBindVideoCaptureDeviceNV;
#define wglBindVideoCaptureDeviceNV _funcptr_wglBindVideoCaptureDeviceNV
extern PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC _funcptr_wglEnumerateVideoCaptureDevicesNV;
#define wglEnumerateVideoCaptureDevicesNV _funcptr_wglEnumerateVideoCaptureDevicesNV
extern PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC _funcptr_wglLockVideoCaptureDeviceNV;
#define wglLockVideoCaptureDeviceNV _funcptr_wglLockVideoCaptureDeviceNV
extern PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC _funcptr_wglQueryVideoCaptureDeviceNV;
#define wglQueryVideoCaptureDeviceNV _funcptr_wglQueryVideoCaptureDeviceNV
extern PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC _funcptr_wglReleaseVideoCaptureDeviceNV;
#define wglReleaseVideoCaptureDeviceNV _funcptr_wglReleaseVideoCaptureDeviceNV

#define WGL_BIND_TO_VIDEO_RGB_NV 0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV 0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV 0x20C2
#define WGL_VIDEO_OUT_COLOR_NV 0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV 0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV 0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV 0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV 0x20C7
#define WGL_VIDEO_OUT_FRAME 0x20C8
#define WGL_VIDEO_OUT_FIELD_1 0x20C9
#define WGL_VIDEO_OUT_FIELD_2 0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2 0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1 0x20CC

typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETVIDEODEVICENVPROC)(HDC , int , HPVIDEODEV *);
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLRELEASEVIDEODEVICENVPROC)(HPVIDEODEV );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLBINDVIDEOIMAGENVPROC)(HPVIDEODEV , HPBUFFERARB , int );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLRELEASEVIDEOIMAGENVPROC)(HPBUFFERARB , int );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLSENDPBUFFERTOVIDEONVPROC)(HPBUFFERARB , int , unsigned long *, BOOL );
typedef BOOL (CODEGEN_FUNCPTR * PFNWGLGETVIDEOINFONVPROC)(HPVIDEODEV , unsigned long *, unsigned long *);

extern PFNWGLGETVIDEODEVICENVPROC _funcptr_wglGetVideoDeviceNV;
#define wglGetVideoDeviceNV _funcptr_wglGetVideoDeviceNV
extern PFNWGLRELEASEVIDEODEVICENVPROC _funcptr_wglReleaseVideoDeviceNV;
#define wglReleaseVideoDeviceNV _funcptr_wglReleaseVideoDeviceNV
extern PFNWGLBINDVIDEOIMAGENVPROC _funcptr_wglBindVideoImageNV;
#define wglBindVideoImageNV _funcptr_wglBindVideoImageNV
extern PFNWGLRELEASEVIDEOIMAGENVPROC _funcptr_wglReleaseVideoImageNV;
#define wglReleaseVideoImageNV _funcptr_wglReleaseVideoImageNV
extern PFNWGLSENDPBUFFERTOVIDEONVPROC _funcptr_wglSendPbufferToVideoNV;
#define wglSendPbufferToVideoNV _funcptr_wglSendPbufferToVideoNV
extern PFNWGLGETVIDEOINFONVPROC _funcptr_wglGetVideoInfoNV;
#define wglGetVideoInfoNV _funcptr_wglGetVideoInfoNV

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*WINDOWSGL_GEN_EXTENSIONS_H*/