#version 140

uniform mat4 projection;
uniform mat4 modelview;

in vec3 a_Vertex;
in vec3 a_Normal;
out vec3 color;

void main()
{
	vec4 pos = modelview * vec4(a_Vertex, 1.0);
	gl_Position = projection * pos;
	color = a_Normal;
}
