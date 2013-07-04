#version 330
layout(location = 0) in vec4 position;
uniform mat4 modelToCamera;uniform mat4 cameraToPerspective;
void main(){   gl_Position = cameraToPerspective * (modelToCamera * position);}