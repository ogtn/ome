#version 330

uniform mat4 projection;
uniform mat4 modelview;
uniform vec3 mdlPosition;

in vec3 a_Vertex;
in vec3 a_Normal;
in vec2 a_Coord0;

out vec3 norm;
out vec2 coord0;
out vec3 color;

void main()
{
	vec3 lightPos = vec3(0, 0, 1);

	vec3 newPosition = a_Vertex + mdlPosition;

	// standard vertex transformation
	vec4 pos = modelview * vec4(newPosition, 1.0);
	gl_Position = projection * pos;

	// normal in eye space
	mat3x3 normalMatrix = mat3x3(modelview);
	vec3 normal = normalize(normalMatrix * a_Normal);

	// light direction in eye space
	vec3 lightDir = normalize(modelview * vec4(lightPos, 0)).xyz;

	float lightAngle = max(dot(normal, lightPos), 0);

	// ambiant component
	color = vec3(0.1, 0.1, 0.1);

	if(lightAngle > 0)
	{
		// diffuse component
		color += vec3(1, 1, 1) * lightAngle;

		// eye position in eye space
		vec3 eyePosition = -pos.xyz;

		// calculating half vector
		vec3 halfVector = normalize(lightDir + eyePosition);

		// angle between half vector and the normal
		float halfAngle = max(dot(normal, halfVector), 0);

		// specular component
		color += vec3(1, 1, 1) * pow(halfAngle, 60);
	}

	norm = normal;
	coord0 = a_Coord0;
}
