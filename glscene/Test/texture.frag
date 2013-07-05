#version 330

smooth in vec2 vertTexCoord;

out vec4 outputColor;

uniform sampler2D image;

void main()
{
   outputColor = texture(image, vertTexCoord); //vec4(vertTexCoord, 0.5, 1.0);
}
