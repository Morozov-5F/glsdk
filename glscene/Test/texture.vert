#version 330

layout(location = 0) in vec4 ms_position;
layout(location = 2) in vec4 ms_normal;

layout(location = 5) in vec2 texCoord;

smooth out vec2 vertTexCoord;

uniform mat4 modelToCamera;
uniform mat4 cameraToPerspective;

void main()
{
   gl_Position = cameraToPerspective * (modelToCamera * ms_position);
   vertTexCoord = texCoord;
}
