#version 330

uniform mat4 projection;
uniform mat4 modelview;
uniform float pointSize;

in vec3 a_Vertex;
in vec4 a_Color;

out vec4 color;

void main()
{
	// standard vertex transformation
	vec4 pos = modelview * vec4(a_Vertex, 1.0);
	gl_Position = projection * pos;

	color = a_Color;
	gl_PointSize = pointSize / -pos.z;
}
