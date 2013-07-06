#ifndef GLSDK_GLSCENE_PARSE_H
#define GLSDK_GLSCENE_PARSE_H

/**
\file
\brief Defines a parsing system for building SceneGraph objects.
**/

#include <stddef.h>
#include <string>
#include <stdexcept>
#include <boost/utility/string_ref.hpp>

namespace glmesh
{
	class Mesh;
}

namespace glscene
{
	class SceneGraph;
	///\addtogroup module_glscene_exceptions
	///@{

	/**
	\brief Thrown if parsing fails.

	The error message taken from the `what` member will generally be quite detailed. It should describe
	the location of the error in both line and column numbers, as well as provide the filename where
	the error happened (if your graph includes resource files). It will also include a copy of the line
	in question, with a direct pointer to the malformed input, where possible.

	The error will have multiple lines, so take this into account when you try to present it to the user.

	Note that the error's location may not be exactly where the error itself occurred. Though the grammar
	is generally designed to prevent catch these kinds of errors as soon as possible, a missing 
	`end` token can still cause these kinds of issues.
	**/
	class MalformedSceneFile : public std::runtime_error
	{
	public:
		MalformedSceneFile(const std::string &msg) : std::runtime_error(msg) {}
	};

	///@}

	///\addtogroup module_glscene_parsing
	///@{

	///Represents the data for a loaded texture.
	struct LoadedTexture
	{
		unsigned int texType;	///<The texture binding target.
		unsigned int texName;	///<The texture object name.
	};

	/**
	\brief Base class for loading file-based resources for the scene graph parser.
	**/
	class BaseLoader
	{
	public:
		virtual LoadedTexture LoadTexture(boost::string_ref basePath, boost::string_ref filename) const = 0;
		virtual glmesh::Mesh *LoadMesh(boost::string_ref basePath, boost::string_ref filename) const = 0;
	};

	/**
	\brief Default file loader for file-based resources.
	**/
	class DefaultLoader : public BaseLoader
	{
	public:
		virtual LoadedTexture LoadTexture(boost::string_ref basePath, boost::string_ref filename) const;
		virtual glmesh::Mesh *LoadMesh(boost::string_ref basePath, boost::string_ref filename) const;
	};

	/**
	\brief Parses a scene graph file from a string you previously loaded.
	
	**/
	SceneGraph *ParseFromMemory(boost::string_ref graphString, const BaseLoader & loader = DefaultLoader());

	/**
	\brief Parses a scene graph file from a filename on disk.
	
	**/
	SceneGraph *ParseFromFile(boost::string_ref filename, const BaseLoader & loader = DefaultLoader());
	///@}
}

#endif //GLSDK_GLSCENE_PARSE_H
