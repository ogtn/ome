#version 330

uniform sampler2D texture0;
uniform sampler2D texture1;

in vec2 coord0;
in vec3 color;

out vec4 outColor;

void main()
{
	vec3 color0 = texture(texture0, coord0).rgb;
	vec3 color1 = texture(texture1, coord0).rgb;
	
	outColor.rgb = mix(color0, color1, 0.0015625 * gl_FragCoord.x) * color;
	outColor.a = 1;
}
