#version 330

uniform sampler2D texture0;

in vec3 norm;
in vec2 coord0;

out vec4 outColor;

void main()
{
	if(gl_FragCoord.x < 213)
		outColor.rgb = norm;
	else if(gl_FragCoord.x < 426)
		outColor = texture(texture0, coord0);
	else
		outColor.rg = coord0;

	outColor.a = 1;
}
