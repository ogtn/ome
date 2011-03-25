#version 330

struct Material
{
	vec3 ambiantColor;
	sampler2D diffuseTexture;
	vec3 specularColor;
	vec3 emissiveColor;
	float shininess;
};

uniform Material mat;

in vec2 coord0;
in vec3 color;

out vec4 outColor;

void main()
{	
	outColor.rgb = texture(mat.diffuseTexture, coord0).rgb * color;
	outColor.a = 1;
}
