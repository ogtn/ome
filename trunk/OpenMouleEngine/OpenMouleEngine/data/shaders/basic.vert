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

uniform mat4 projection;
uniform mat4 modelview;
uniform vec3 mdlPosition;
uniform Material mat;
uniform DirLight light;

in vec3 a_Vertex;
in vec3 a_Normal;
in vec2 a_Coord0;

out vec3 norm;
out vec2 coord0;
out vec3 color;
out vec3 lightDir;
out vec3 eyePos;

void main()
{
	// standard vertex transformation
	vec3 newPosition = a_Vertex + mdlPosition;
	vec4 pos = modelview * vec4(newPosition, 1.0);
	gl_Position = projection * pos;

	// normal in eye space
	mat3x3 normalMatrix = mat3x3(modelview);
	vec3 normal = normalMatrix * a_Normal;

	// light direction in eye space
	lightDir = normalize(modelview * vec4(light.direction, 0)).xyz;

	// eye position in eye space
	vec3 eyePosition = -pos.xyz;

	// ambiant component
	color = mat.ambiantColor * light.ambiantColor;

	eyePos = eyePosition;
	norm = normal;
	coord0 = a_Coord0;
}
