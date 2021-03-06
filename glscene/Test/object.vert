#version 330

layout(location = 0) in vec4 ms_position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec4 ms_normal;

smooth out vec4 vertColor;

uniform mat4 modelToCamera;
uniform mat4 cameraToPerspective;

void main()
{
   gl_Position = cameraToPerspective * (modelToCamera * ms_position);
   vertColor = color;
}
