#version 330

uniform mat4 projection;
uniform mat4 modelview;

in vec3 a_Vertex;
in vec3 a_Normal;
in vec2 a_Coord0;

out vec3 norm;
out vec2 coord0;

void main()
{
	vec4 pos = modelview * vec4(a_Vertex, 1.0);
	gl_Position = projection * pos;

	norm = a_Normal;
	coord0 = a_Coord0;
}
