#version 330

uniform mat4 projection;
uniform mat4 modelview;

in vec3 a_Vertex;
in vec3 a_Normal;
in vec2 a_Coord;

out vec3 norm;
out vec2 coord;

void main()
{
	vec4 pos = modelview * vec4(a_Vertex, 1.0);
	gl_Position = projection * pos;

	norm = a_Normal;
	coord = a_Coord;
}
