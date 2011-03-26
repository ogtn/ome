#version 330

struct Material
{
	vec3 ambiantColor;
	sampler2D diffuseTexture;
	vec3 specularColor;
	vec3 emissiveColor;
	float shininess;
};

struct DirLight
{
	vec3 ambiantColor;
	vec3 diffuseColor;
	vec3 specularColor;
	vec3 direction;
};

uniform Material mat;
uniform DirLight light;

in vec2 coord0;
in vec3 color;
in vec3 norm;
in vec3 lightDir;
in vec3 eyePos;

out vec4 outColor;

void main()
{
	outColor.rgb = color;
	normalize(norm);
	float lightAngle = max(dot(norm, lightDir), 0);

	if(lightAngle > 0)
	{
		// diffuse component
		outColor.rgb += light.diffuseColor * lightAngle;			// missing mat.diffuseColor

		// calculating half vector
		vec3 halfVector = normalize(lightDir + eyePos);

		// angle between half vector and the normal
		float halfAngle = max(dot(norm, halfVector), 0);

		// specular component
		outColor.rgb += mat.specularColor * light.specularColor * pow(halfAngle, mat.shininess);
	}

	outColor.a = 1;
	outColor *= texture(mat.diffuseTexture, coord0);
}
