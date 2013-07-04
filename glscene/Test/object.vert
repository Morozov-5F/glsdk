#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec4 normal;

smooth out vec4 vertColor;

uniform mat4 modelToCamera;
uniform mat4 cameraToPerspective;

void main()
{
   gl_Position = cameraToPerspective * (modelToCamera * position);
   vertColor = color;
}
