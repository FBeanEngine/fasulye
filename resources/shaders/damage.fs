#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

uniform float seconds;


void main() {

    // Texel color fetching from texture sampler
    vec4 texelColor = texture(texture0, fragTexCoord)*colDiffuse*fragColor;

    // Calculate the hue based on time
    float hue = fract(seconds * 1.25);

    // Mix red and white based on time
    vec3 redColor = vec3(1.0, 0.0, 0.0);
    vec3 whiteColor = vec3(1.0, 1.0, 1.0);
    vec3 degrade = texelColor.rgb * mix(redColor, whiteColor, hue);

    // Output the final color
    finalColor = vec4(degrade, texelColor.a);
}
