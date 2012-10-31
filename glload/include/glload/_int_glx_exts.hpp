#ifndef GLXWIN_GEN_EXTENSIONS_HPP
#define GLXWIN_GEN_EXTENSIONS_HPP


#include "_int_load_test.hpp"
namespace glX
{
	namespace exts
	{
		extern glload::LoadTest glXext_3DFX_multisample;
		extern glload::LoadTest glXext_AMD_gpu_association;
		extern glload::LoadTest glXext_ARB_create_context;
		extern glload::LoadTest glXext_ARB_create_context_profile;
		extern glload::LoadTest glXext_ARB_create_context_robustness;
		extern glload::LoadTest glXext_ARB_fbconfig_float;
		extern glload::LoadTest glXext_ARB_framebuffer_sRGB;
		extern glload::LoadTest glXext_ARB_get_proc_address;
		extern glload::LoadTest glXext_ARB_multisample;
		extern glload::LoadTest glXext_ARB_vertex_buffer_object;
		extern glload::LoadTest glXext_EXT_buffer_age;
		extern glload::LoadTest glXext_EXT_create_context_es2_profile;
		extern glload::LoadTest glXext_EXT_fbconfig_packed_float;
		extern glload::LoadTest glXext_EXT_framebuffer_sRGB;
		extern glload::LoadTest glXext_EXT_import_context;
		extern glload::LoadTest glXext_EXT_swap_control;
		extern glload::LoadTest glXext_EXT_swap_control_tear;
		extern glload::LoadTest glXext_EXT_texture_from_pixmap;
		extern glload::LoadTest glXext_EXT_visual_info;
		extern glload::LoadTest glXext_EXT_visual_rating;
		extern glload::LoadTest glXext_INTEL_swap_event;
		extern glload::LoadTest glXext_MESA_agp_offset;
		extern glload::LoadTest glXext_MESA_copy_sub_buffer;
		extern glload::LoadTest glXext_MESA_pixmap_colormap;
		extern glload::LoadTest glXext_MESA_release_buffers;
		extern glload::LoadTest glXext_MESA_set_3dfx_mode;
		extern glload::LoadTest glXext_NV_copy_image;
		extern glload::LoadTest glXext_NV_float_buffer;
		extern glload::LoadTest glXext_NV_multisample_coverage;
		extern glload::LoadTest glXext_NV_present_video;
		extern glload::LoadTest glXext_NV_swap_group;
		extern glload::LoadTest glXext_NV_video_capture;
		extern glload::LoadTest glXext_NV_video_out;
		extern glload::LoadTest glXext_OML_swap_method;
		extern glload::LoadTest glXext_OML_sync_control;
		extern glload::LoadTest glXext_SGIS_blended_overlay;
		extern glload::LoadTest glXext_SGIS_multisample;
		extern glload::LoadTest glXext_SGIS_shared_multisample;
		extern glload::LoadTest glXext_SGIX_fbconfig;
		extern glload::LoadTest glXext_SGIX_pbuffer;
		extern glload::LoadTest glXext_SGIX_swap_barrier;
		extern glload::LoadTest glXext_SGIX_swap_group;
		extern glload::LoadTest glXext_SGIX_video_resize;
		extern glload::LoadTest glXext_SGIX_visual_select_group;
		extern glload::LoadTest glXext_SGI_cushion;
		extern glload::LoadTest glXext_SGI_make_current_read;
		extern glload::LoadTest glXext_SGI_swap_control;
		extern glload::LoadTest glXext_SGI_video_sync;
		extern glload::LoadTest glXext_SUN_get_transparent_index;
	}
	
	enum
	{
		SAMPLE_BUFFERS_3DFX              = 0x8050,
		SAMPLES_3DFX                     = 0x8051,
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
		CONTEXT_DEBUG_BIT_ARB            = 0x00000001,
		CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = 0x00000002,
		CONTEXT_MAJOR_VERSION_ARB        = 0x2091,
		CONTEXT_MINOR_VERSION_ARB        = 0x2092,
		CONTEXT_FLAGS_ARB                = 0x2094,
		CONTEXT_CORE_PROFILE_BIT_ARB     = 0x00000001,
		CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002,
		CONTEXT_PROFILE_MASK_ARB         = 0x9126,
		CONTEXT_ROBUST_ACCESS_BIT_ARB    = 0x00000004,
		LOSE_CONTEXT_ON_RESET_ARB        = 0x8252,
		CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB = 0x8256,
		NO_RESET_NOTIFICATION_ARB        = 0x8261,
		RGBA_FLOAT_TYPE_ARB              = 0x20B9,
		RGBA_FLOAT_BIT_ARB               = 0x00000004,
		FRAMEBUFFER_SRGB_CAPABLE_ARB     = 0x20B2,
		SAMPLE_BUFFERS_ARB               = 100000,
		SAMPLES_ARB                      = 100001,
		CONTEXT_ALLOW_BUFFER_BYTE_ORDER_MISMATCH_ARB = 0x2095,
		BACK_BUFFER_AGE_EXT              = 0x20F4,
		CONTEXT_ES2_PROFILE_BIT_EXT      = 0x00000004,
		RGBA_UNSIGNED_FLOAT_TYPE_EXT     = 0x20B1,
		RGBA_UNSIGNED_FLOAT_BIT_EXT      = 0x00000008,
		FRAMEBUFFER_SRGB_CAPABLE_EXT     = 0x20B2,
		SHARE_CONTEXT_EXT                = 0x800A,
		VISUAL_ID_EXT                    = 0x800B,
		SCREEN_EXT                       = 0x800C,
		SWAP_INTERVAL_EXT                = 0x20F1,
		MAX_SWAP_INTERVAL_EXT            = 0x20F2,
		LATE_SWAPS_TEAR_EXT              = 0x20F3,
		TEXTURE_1D_BIT_EXT               = 0x00000001,
		TEXTURE_2D_BIT_EXT               = 0x00000002,
		TEXTURE_RECTANGLE_BIT_EXT        = 0x00000004,
		BIND_TO_TEXTURE_RGB_EXT          = 0x20D0,
		BIND_TO_TEXTURE_RGBA_EXT         = 0x20D1,
		BIND_TO_MIPMAP_TEXTURE_EXT       = 0x20D2,
		BIND_TO_TEXTURE_TARGETS_EXT      = 0x20D3,
		Y_INVERTED_EXT                   = 0x20D4,
		TEXTURE_FORMAT_EXT               = 0x20D5,
		TEXTURE_TARGET_EXT               = 0x20D6,
		MIPMAP_TEXTURE_EXT               = 0x20D7,
		TEXTURE_FORMAT_NONE_EXT          = 0x20D8,
		TEXTURE_FORMAT_RGB_EXT           = 0x20D9,
		TEXTURE_FORMAT_RGBA_EXT          = 0x20DA,
		TEXTURE_1D_EXT                   = 0x20DB,
		TEXTURE_2D_EXT                   = 0x20DC,
		TEXTURE_RECTANGLE_EXT            = 0x20DD,
		FRONT_LEFT_EXT                   = 0x20DE,
		FRONT_RIGHT_EXT                  = 0x20DF,
		BACK_LEFT_EXT                    = 0x20E0,
		BACK_RIGHT_EXT                   = 0x20E1,
		FRONT_EXT                        = 0x20DE,
		BACK_EXT                         = 0x20E0,
		AUX0_EXT                         = 0x20E2,
		AUX1_EXT                         = 0x20E3,
		AUX2_EXT                         = 0x20E4,
		AUX3_EXT                         = 0x20E5,
		AUX4_EXT                         = 0x20E6,
		AUX5_EXT                         = 0x20E7,
		AUX6_EXT                         = 0x20E8,
		AUX7_EXT                         = 0x20E9,
		AUX8_EXT                         = 0x20EA,
		AUX9_EXT                         = 0x20EB,
		X_VISUAL_TYPE_EXT                = 0x22,
		TRANSPARENT_TYPE_EXT             = 0x23,
		TRANSPARENT_INDEX_VALUE_EXT      = 0x24,
		TRANSPARENT_RED_VALUE_EXT        = 0x25,
		TRANSPARENT_GREEN_VALUE_EXT      = 0x26,
		TRANSPARENT_BLUE_VALUE_EXT       = 0x27,
		TRANSPARENT_ALPHA_VALUE_EXT      = 0x28,
		NONE_EXT                         = 0x8000,
		TRUE_COLOR_EXT                   = 0x8002,
		DIRECT_COLOR_EXT                 = 0x8003,
		PSEUDO_COLOR_EXT                 = 0x8004,
		STATIC_COLOR_EXT                 = 0x8005,
		GRAY_SCALE_EXT                   = 0x8006,
		STATIC_GRAY_EXT                  = 0x8007,
		TRANSPARENT_RGB_EXT              = 0x8008,
		TRANSPARENT_INDEX_EXT            = 0x8009,
		//NONE_EXT taken from EXT_visual_info
		VISUAL_CAVEAT_EXT                = 0x20,
		SLOW_VISUAL_EXT                  = 0x8001,
		NON_CONFORMANT_VISUAL_EXT        = 0x800D,
		BUFFER_SWAP_COMPLETE_INTEL_MASK  = 0x04000000,
		EXCHANGE_COMPLETE_INTEL          = 0x8180,
		COPY_COMPLETE_INTEL              = 0x8181,
		FLIP_COMPLETE_INTEL              = 0x8182,
		_3DFX_WINDOW_MODE_MESA           = 0x1,
		_3DFX_FULLSCREEN_MODE_MESA       = 0x2,
		FLOAT_COMPONENTS_NV              = 0x20B0,
		COVERAGE_SAMPLES_NV              = 100001,
		COLOR_SAMPLES_NV                 = 0x20B3,
		NUM_VIDEO_SLOTS_NV               = 0x20F0,
		DEVICE_ID_NV                     = 0x20CD,
		UNIQUE_ID_NV                     = 0x20CE,
		NUM_VIDEO_CAPTURE_SLOTS_NV       = 0x20CF,
		VIDEO_OUT_COLOR_NV               = 0x20C3,
		VIDEO_OUT_ALPHA_NV               = 0x20C4,
		VIDEO_OUT_DEPTH_NV               = 0x20C5,
		VIDEO_OUT_COLOR_AND_ALPHA_NV     = 0x20C6,
		VIDEO_OUT_COLOR_AND_DEPTH_NV     = 0x20C7,
		VIDEO_OUT_FRAME_NV               = 0x20C8,
		VIDEO_OUT_FIELD_1_NV             = 0x20C9,
		VIDEO_OUT_FIELD_2_NV             = 0x20CA,
		VIDEO_OUT_STACKED_FIELDS_1_2_NV  = 0x20CB,
		VIDEO_OUT_STACKED_FIELDS_2_1_NV  = 0x20CC,
		SWAP_METHOD_OML                  = 0x8060,
		SWAP_EXCHANGE_OML                = 0x8061,
		SWAP_COPY_OML                    = 0x8062,
		SWAP_UNDEFINED_OML               = 0x8063,
		BLENDED_RGBA_SGIS                = 0x8025,
		SAMPLE_BUFFERS_SGIS              = 100000,
		SAMPLES_SGIS                     = 100001,
		MULTISAMPLE_SUB_RECT_WIDTH_SGIS  = 0x8026,
		MULTISAMPLE_SUB_RECT_HEIGHT_SGIS = 0x8027,
		//SCREEN_EXT taken from EXT_import_context
		WINDOW_BIT_SGIX                  = 0x00000001,
		PIXMAP_BIT_SGIX                  = 0x00000002,
		RGBA_BIT_SGIX                    = 0x00000001,
		COLOR_INDEX_BIT_SGIX             = 0x00000002,
		DRAWABLE_TYPE_SGIX               = 0x8010,
		RENDER_TYPE_SGIX                 = 0x8011,
		X_RENDERABLE_SGIX                = 0x8012,
		FBCONFIG_ID_SGIX                 = 0x8013,
		RGBA_TYPE_SGIX                   = 0x8014,
		COLOR_INDEX_TYPE_SGIX            = 0x8015,
		PBUFFER_BIT_SGIX                 = 0x00000004,
		BUFFER_CLOBBER_MASK_SGIX         = 0x08000000,
		FRONT_LEFT_BUFFER_BIT_SGIX       = 0x00000001,
		FRONT_RIGHT_BUFFER_BIT_SGIX      = 0x00000002,
		BACK_LEFT_BUFFER_BIT_SGIX        = 0x00000004,
		BACK_RIGHT_BUFFER_BIT_SGIX       = 0x00000008,
		AUX_BUFFERS_BIT_SGIX             = 0x00000010,
		DEPTH_BUFFER_BIT_SGIX            = 0x00000020,
		STENCIL_BUFFER_BIT_SGIX          = 0x00000040,
		ACCUM_BUFFER_BIT_SGIX            = 0x00000080,
		SAMPLE_BUFFERS_BIT_SGIX          = 0x00000100,
		MAX_PBUFFER_WIDTH_SGIX           = 0x8016,
		MAX_PBUFFER_HEIGHT_SGIX          = 0x8017,
		MAX_PBUFFER_PIXELS_SGIX          = 0x8018,
		OPTIMAL_PBUFFER_WIDTH_SGIX       = 0x8019,
		OPTIMAL_PBUFFER_HEIGHT_SGIX      = 0x801A,
		PRESERVED_CONTENTS_SGIX          = 0x801B,
		LARGEST_PBUFFER_SGIX             = 0x801C,
		WIDTH_SGIX                       = 0x801D,
		HEIGHT_SGIX                      = 0x801E,
		EVENT_MASK_SGIX                  = 0x801F,
		DAMAGED_SGIX                     = 0x8020,
		SAVED_SGIX                       = 0x8021,
		WINDOW_SGIX                      = 0x8022,
		PBUFFER_SGIX                     = 0x8023,
		SYNC_FRAME_SGIX                  = 0x00000000,
		SYNC_SWAP_SGIX                   = 0x00000001,
		VISUAL_SELECT_GROUP_SGIX         = 0x8028,
	};
	
	namespace _detail
	{
		typedef GLXContext (CODEGEN_FUNCPTR * Proc_glXCreateContextAttribsARB)(Display *, GLXFBConfig , GLXContext , Bool , const int *);
	}
	
	extern _detail::Proc_glXCreateContextAttribsARB CreateContextAttribsARB;
	
	namespace _detail
	{
		typedef __GLXextFuncPtr (CODEGEN_FUNCPTR * Proc_glXGetProcAddressARB)(const GLubyte *);
	}
	
	extern _detail::Proc_glXGetProcAddressARB GetProcAddressARB;
	
	namespace _detail
	{
		typedef Display * (CODEGEN_FUNCPTR * Proc_glXGetCurrentDisplayEXT)();
		typedef int (CODEGEN_FUNCPTR * Proc_glXQueryContextInfoEXT)(Display *, GLXContext , int , int *);
		typedef GLXContextID (CODEGEN_FUNCPTR * Proc_glXGetContextIDEXT)(const GLXContext );
		typedef GLXContext (CODEGEN_FUNCPTR * Proc_glXImportContextEXT)(Display *, GLXContextID );
		typedef void (CODEGEN_FUNCPTR * Proc_glXFreeContextEXT)(Display *, GLXContext );
	}
	
	extern _detail::Proc_glXGetCurrentDisplayEXT GetCurrentDisplayEXT;
	extern _detail::Proc_glXQueryContextInfoEXT QueryContextInfoEXT;
	extern _detail::Proc_glXGetContextIDEXT GetContextIDEXT;
	extern _detail::Proc_glXImportContextEXT ImportContextEXT;
	extern _detail::Proc_glXFreeContextEXT FreeContextEXT;
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glXSwapIntervalEXT)(Display *, GLXDrawable , int );
	}
	
	extern _detail::Proc_glXSwapIntervalEXT SwapIntervalEXT;
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glXBindTexImageEXT)(Display *, GLXDrawable , int , const int *);
		typedef void (CODEGEN_FUNCPTR * Proc_glXReleaseTexImageEXT)(Display *, GLXDrawable , int );
	}
	
	extern _detail::Proc_glXBindTexImageEXT BindTexImageEXT;
	extern _detail::Proc_glXReleaseTexImageEXT ReleaseTexImageEXT;
	
	namespace _detail
	{
		typedef unsigned int (CODEGEN_FUNCPTR * Proc_glXGetAGPOffsetMESA)(const void *);
	}
	
	extern _detail::Proc_glXGetAGPOffsetMESA GetAGPOffsetMESA;
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glXCopySubBufferMESA)(Display *, GLXDrawable , int , int , int , int );
	}
	
	extern _detail::Proc_glXCopySubBufferMESA CopySubBufferMESA;
	
	namespace _detail
	{
		typedef GLXPixmap (CODEGEN_FUNCPTR * Proc_glXCreateGLXPixmapMESA)(Display *, XVisualInfo *, Pixmap , Colormap );
	}
	
	extern _detail::Proc_glXCreateGLXPixmapMESA CreateGLXPixmapMESA;
	
	namespace _detail
	{
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXReleaseBuffersMESA)(Display *, GLXDrawable );
	}
	
	extern _detail::Proc_glXReleaseBuffersMESA ReleaseBuffersMESA;
	
	namespace _detail
	{
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXSet3DfxModeMESA)(int );
	}
	
	extern _detail::Proc_glXSet3DfxModeMESA Set3DfxModeMESA;
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glXCopyImageSubDataNV)(Display *, GLXContext , GLuint , GLenum , GLint , GLint , GLint , GLint , GLXContext , GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );
	}
	
	extern _detail::Proc_glXCopyImageSubDataNV CopyImageSubDataNV;
	
	namespace _detail
	{
		typedef unsigned int * (CODEGEN_FUNCPTR * Proc_glXEnumerateVideoDevicesNV)(Display *, int , int *);
		typedef int (CODEGEN_FUNCPTR * Proc_glXBindVideoDeviceNV)(Display *, unsigned int , unsigned int , const int *);
	}
	
	extern _detail::Proc_glXEnumerateVideoDevicesNV EnumerateVideoDevicesNV;
	extern _detail::Proc_glXBindVideoDeviceNV BindVideoDeviceNV;
	
	namespace _detail
	{
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXJoinSwapGroupNV)(Display *, GLXDrawable , GLuint );
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXBindSwapBarrierNV)(Display *, GLuint , GLuint );
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXQuerySwapGroupNV)(Display *, GLXDrawable , GLuint *, GLuint *);
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXQueryMaxSwapGroupsNV)(Display *, int , GLuint *, GLuint *);
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXQueryFrameCountNV)(Display *, int , GLuint *);
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXResetFrameCountNV)(Display *, int );
	}
	
	extern _detail::Proc_glXJoinSwapGroupNV JoinSwapGroupNV;
	extern _detail::Proc_glXBindSwapBarrierNV BindSwapBarrierNV;
	extern _detail::Proc_glXQuerySwapGroupNV QuerySwapGroupNV;
	extern _detail::Proc_glXQueryMaxSwapGroupsNV QueryMaxSwapGroupsNV;
	extern _detail::Proc_glXQueryFrameCountNV QueryFrameCountNV;
	extern _detail::Proc_glXResetFrameCountNV ResetFrameCountNV;
	
	namespace _detail
	{
		typedef int (CODEGEN_FUNCPTR * Proc_glXBindVideoCaptureDeviceNV)(Display *, unsigned int , GLXVideoCaptureDeviceNV );
		typedef GLXVideoCaptureDeviceNV * (CODEGEN_FUNCPTR * Proc_glXEnumerateVideoCaptureDevicesNV)(Display *, int , int *);
		typedef void (CODEGEN_FUNCPTR * Proc_glXLockVideoCaptureDeviceNV)(Display *, GLXVideoCaptureDeviceNV );
		typedef int (CODEGEN_FUNCPTR * Proc_glXQueryVideoCaptureDeviceNV)(Display *, GLXVideoCaptureDeviceNV , int , int *);
		typedef void (CODEGEN_FUNCPTR * Proc_glXReleaseVideoCaptureDeviceNV)(Display *, GLXVideoCaptureDeviceNV );
	}
	
	extern _detail::Proc_glXBindVideoCaptureDeviceNV BindVideoCaptureDeviceNV;
	extern _detail::Proc_glXEnumerateVideoCaptureDevicesNV EnumerateVideoCaptureDevicesNV;
	extern _detail::Proc_glXLockVideoCaptureDeviceNV LockVideoCaptureDeviceNV;
	extern _detail::Proc_glXQueryVideoCaptureDeviceNV QueryVideoCaptureDeviceNV;
	extern _detail::Proc_glXReleaseVideoCaptureDeviceNV ReleaseVideoCaptureDeviceNV;
	
	namespace _detail
	{
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXGetSyncValuesOML)(Display *, GLXDrawable , int64_t *, int64_t *, int64_t *);
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXGetMscRateOML)(Display *, GLXDrawable , int32_t *, int32_t *);
		typedef int64_t (CODEGEN_FUNCPTR * Proc_glXSwapBuffersMscOML)(Display *, GLXDrawable , int64_t , int64_t , int64_t );
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXWaitForMscOML)(Display *, GLXDrawable , int64_t , int64_t , int64_t , int64_t *, int64_t *, int64_t *);
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXWaitForSbcOML)(Display *, GLXDrawable , int64_t , int64_t *, int64_t *, int64_t *);
	}
	
	extern _detail::Proc_glXGetSyncValuesOML GetSyncValuesOML;
	extern _detail::Proc_glXGetMscRateOML GetMscRateOML;
	extern _detail::Proc_glXSwapBuffersMscOML SwapBuffersMscOML;
	extern _detail::Proc_glXWaitForMscOML WaitForMscOML;
	extern _detail::Proc_glXWaitForSbcOML WaitForSbcOML;
	
	namespace _detail
	{
		typedef int (CODEGEN_FUNCPTR * Proc_glXGetFBConfigAttribSGIX)(Display *, GLXFBConfigSGIX , int , int *);
		typedef GLXFBConfigSGIX * (CODEGEN_FUNCPTR * Proc_glXChooseFBConfigSGIX)(Display *, int , int *, int *);
		typedef GLXPixmap (CODEGEN_FUNCPTR * Proc_glXCreateGLXPixmapWithConfigSGIX)(Display *, GLXFBConfigSGIX , Pixmap );
		typedef GLXContext (CODEGEN_FUNCPTR * Proc_glXCreateContextWithConfigSGIX)(Display *, GLXFBConfigSGIX , int , GLXContext , Bool );
		typedef XVisualInfo * (CODEGEN_FUNCPTR * Proc_glXGetVisualFromFBConfigSGIX)(Display *, GLXFBConfigSGIX );
		typedef GLXFBConfigSGIX (CODEGEN_FUNCPTR * Proc_glXGetFBConfigFromVisualSGIX)(Display *, XVisualInfo *);
	}
	
	extern _detail::Proc_glXGetFBConfigAttribSGIX GetFBConfigAttribSGIX;
	extern _detail::Proc_glXChooseFBConfigSGIX ChooseFBConfigSGIX;
	extern _detail::Proc_glXCreateGLXPixmapWithConfigSGIX CreateGLXPixmapWithConfigSGIX;
	extern _detail::Proc_glXCreateContextWithConfigSGIX CreateContextWithConfigSGIX;
	extern _detail::Proc_glXGetVisualFromFBConfigSGIX GetVisualFromFBConfigSGIX;
	extern _detail::Proc_glXGetFBConfigFromVisualSGIX GetFBConfigFromVisualSGIX;
	
	namespace _detail
	{
		typedef GLXPbufferSGIX (CODEGEN_FUNCPTR * Proc_glXCreateGLXPbufferSGIX)(Display *, GLXFBConfigSGIX , unsigned int , unsigned int , int *);
		typedef void (CODEGEN_FUNCPTR * Proc_glXDestroyGLXPbufferSGIX)(Display *, GLXPbufferSGIX );
		typedef int (CODEGEN_FUNCPTR * Proc_glXQueryGLXPbufferSGIX)(Display *, GLXPbufferSGIX , int , unsigned int *);
		typedef void (CODEGEN_FUNCPTR * Proc_glXSelectEventSGIX)(Display *, GLXDrawable , unsigned long );
		typedef void (CODEGEN_FUNCPTR * Proc_glXGetSelectedEventSGIX)(Display *, GLXDrawable , unsigned long *);
	}
	
	extern _detail::Proc_glXCreateGLXPbufferSGIX CreateGLXPbufferSGIX;
	extern _detail::Proc_glXDestroyGLXPbufferSGIX DestroyGLXPbufferSGIX;
	extern _detail::Proc_glXQueryGLXPbufferSGIX QueryGLXPbufferSGIX;
	extern _detail::Proc_glXSelectEventSGIX SelectEventSGIX;
	extern _detail::Proc_glXGetSelectedEventSGIX GetSelectedEventSGIX;
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glXBindSwapBarrierSGIX)(Display *, GLXDrawable , int );
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXQueryMaxSwapBarriersSGIX)(Display *, int , int *);
	}
	
	extern _detail::Proc_glXBindSwapBarrierSGIX BindSwapBarrierSGIX;
	extern _detail::Proc_glXQueryMaxSwapBarriersSGIX QueryMaxSwapBarriersSGIX;
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glXJoinSwapGroupSGIX)(Display *, GLXDrawable , GLXDrawable );
	}
	
	extern _detail::Proc_glXJoinSwapGroupSGIX JoinSwapGroupSGIX;
	
	namespace _detail
	{
		typedef int (CODEGEN_FUNCPTR * Proc_glXBindChannelToWindowSGIX)(Display *, int , int , Window );
		typedef int (CODEGEN_FUNCPTR * Proc_glXChannelRectSGIX)(Display *, int , int , int , int , int , int );
		typedef int (CODEGEN_FUNCPTR * Proc_glXQueryChannelRectSGIX)(Display *, int , int , int *, int *, int *, int *);
		typedef int (CODEGEN_FUNCPTR * Proc_glXQueryChannelDeltasSGIX)(Display *, int , int , int *, int *, int *, int *);
		typedef int (CODEGEN_FUNCPTR * Proc_glXChannelRectSyncSGIX)(Display *, int , int , GLenum );
	}
	
	extern _detail::Proc_glXBindChannelToWindowSGIX BindChannelToWindowSGIX;
	extern _detail::Proc_glXChannelRectSGIX ChannelRectSGIX;
	extern _detail::Proc_glXQueryChannelRectSGIX QueryChannelRectSGIX;
	extern _detail::Proc_glXQueryChannelDeltasSGIX QueryChannelDeltasSGIX;
	extern _detail::Proc_glXChannelRectSyncSGIX ChannelRectSyncSGIX;
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glXCushionSGI)(Display *, Window , float );
	}
	
	extern _detail::Proc_glXCushionSGI CushionSGI;
	
	namespace _detail
	{
		typedef Bool (CODEGEN_FUNCPTR * Proc_glXMakeCurrentReadSGI)(Display *, GLXDrawable , GLXDrawable , GLXContext );
		typedef GLXDrawable (CODEGEN_FUNCPTR * Proc_glXGetCurrentReadDrawableSGI)();
	}
	
	extern _detail::Proc_glXMakeCurrentReadSGI MakeCurrentReadSGI;
	extern _detail::Proc_glXGetCurrentReadDrawableSGI GetCurrentReadDrawableSGI;
	
	namespace _detail
	{
		typedef int (CODEGEN_FUNCPTR * Proc_glXSwapIntervalSGI)(int );
	}
	
	extern _detail::Proc_glXSwapIntervalSGI SwapIntervalSGI;
	
	namespace _detail
	{
		typedef int (CODEGEN_FUNCPTR * Proc_glXGetVideoSyncSGI)(unsigned int *);
		typedef int (CODEGEN_FUNCPTR * Proc_glXWaitVideoSyncSGI)(int , int , unsigned int *);
	}
	
	extern _detail::Proc_glXGetVideoSyncSGI GetVideoSyncSGI;
	extern _detail::Proc_glXWaitVideoSyncSGI WaitVideoSyncSGI;
	
	namespace _detail
	{
		typedef Status (CODEGEN_FUNCPTR * Proc_glXGetTransparentIndexSUN)(Display *, Window , Window , long *);
	}
	
	extern _detail::Proc_glXGetTransparentIndexSUN GetTransparentIndexSUN;
	
}
#endif /*GLXWIN_GEN_EXTENSIONS_HPP*/
