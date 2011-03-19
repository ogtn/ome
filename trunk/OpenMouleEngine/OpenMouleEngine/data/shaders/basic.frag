#version 140

struct Light
{
	vec4 color;
};

uniform Light myLight;
uniform vec4 prout;

in vec3 color;
out vec4 outColor;

void main()
{
	outColor = vec4(color, 1);
}
