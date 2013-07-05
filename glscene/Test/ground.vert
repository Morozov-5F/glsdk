#version 330
layout(location = 0) in vec4 ms_position;

uniform mat4 modelToCamera;uniform mat4 cameraToPerspective;
void main(){   gl_Position = cameraToPerspective * (modelToCamera * ms_position);}