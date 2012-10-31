
#ifndef GLSDK_LOAD_H
#define GLSDK_LOAD_H

/**
\file
\brief The C header to include if you want to initialize the OpenGL functions.

\deprecated
**/

/**\addtogroup module_glload_cinter**/
/**@{**/

/**
\brief The loading status returned by the GL loading functions.

\deprecated
**/
enum LoadSucceeded
{
	LS_LOAD_FAILED,				/**<Function loading failed. Things were reset to nothing being loaded.**/
	LS_LOAD_SUCCEEDED,			/**<All functions for the current version were loaded.**/
};

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

/**
\brief Loads all of the OpenGL function pointers for the current version and extensions.

This function will respect the core/compatibility flags that the context was created under
(if the version is 3.2 or better and thus has those flags available). Similarly, if ARB_compatibility
is defined for a 3.1 context, it will load the compatibility profile; otherwise, it will load the core.
For 3.0 and below, it loads everything available.

\return Of the type ::LoadSucceeded.
\deprecated
**/
int LoadFunctions();

#ifdef WIN32
/**
\brief Loads all of the function pointers associated with WGL.

\return Of the type ::LoadSucceeded.
\deprecated
**/
int LoadWinFunctions(void *hdc);
#endif /*WIN32*/
#ifdef GLX_H
/**
\brief Loads all of the function pointers associated with GLX.

\return Of the type ::LoadSucceeded.
\deprecated
**/
int LoadGLXFunctions(void *display, int screen);
#endif

/**
This function retrieves the major GL version number of the OpenGL context. Only works after LoadFunctions has been called.
\deprecated
**/
int GetMajorVersion();

/**
This function retrieves the minor GL version number of the OpenGL context. Only works after LoadFunctions has been called.
\deprecated
**/
int GetMinorVersion();

/**
\brief Returns non-zero if the current GL version is greater than or equal to the given version.
\deprecated
**/
int IsVersionGEQ(int iMajorVersion, int iMinorVersion);
/**@}**/

#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*GLSDK_LOAD_H*/

