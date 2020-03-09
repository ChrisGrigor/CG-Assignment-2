#version 440

layout (location = 0) in vec2 inUV;
layout (location = 1) in vec2 inScreenCoords ;

layout (location = 0) out vec4 outColor;

uniform sampler2D xImage;

uniform float a_BloomThreshold;

void main() {
	vec3 sampled = texture2D(xImage, inUV).rgb;
	// Determine our luminance, based on percieved brightness of colors
	float luminance = dot(sampled, vec3(0.3, 0.6, 0.1)); 
	// Step will return 0 if luminance < threshhold, and 1 if otherwise
	outColor.rgb = sampled * step(a_BloomThreshold, luminance); 
	outColor.a = 1.0;
}