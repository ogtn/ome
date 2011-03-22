#version 330

uniform sampler2D texture0;

//in vec3 norm;
//in vec2 coord;

out vec4 outColor;

void main()
{
	/*if(gl_FragCoord.x < 240)
		outColor = vec4(norm, 1);
	else if(gl_FragCoord.x < 480)
		outColor = vec4(coord, 0, 1);
	else
		outColor = texture(texture0, coord.st);*/
	outColor = vec4(1, 1, 1, 1);
}
