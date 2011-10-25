
#include <string>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <utility>

#include <glload/gl_3_3.hpp>
#include <glload/gll.hpp>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glutil/glutil.h>
#include <glmesh/glmesh.h>
#include "framework_draw.h"

class BasicDrawable : public Drawable
{
public:
	BasicDrawable()
	{

	}

	~BasicDrawable()
	{

	}

	virtual void Draw(const glm::mat4 &cameraToClip, const glm::mat4 &worldToCamera,
		const glm::mat4 &modelToWorld)
	{
		
	}

private:
};


Drawable *CreateDrawable()
{
	return new BasicDrawable();
}
