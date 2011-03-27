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

in vec4 color;

out vec4 outColor;

void main()
{
	outColor = color * texture(mat.diffuseTexture, gl_PointCoord);
}
