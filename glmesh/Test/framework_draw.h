
#ifndef FRAMEWORK_DRAW_H
#define FRAMEWORK_DRAW_H

#include <glm/glm.hpp>

class Drawable
{
public:
	virtual ~Drawable() {}

	virtual void Draw(const glm::mat4 &cameraToClip, const glm::mat4 &worldToCamera,
		const glm::mat4 &modelToWorld) = 0;

private:
};

Drawable *CreateDrawable();


#endif //FRAMEWORK_DRAW_H
