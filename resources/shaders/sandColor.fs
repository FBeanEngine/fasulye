#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

uniform vec3 u_tintColor;

void main() {
    // Sample the grayscale value from the texture
    vec4 texColor = texture(texture0, fragTexCoord);
    float grayscaleValue = (texColor.r + texColor.g + texColor.b) / 3.0; // Average of all channels

    // Mix the grayscale value with the tint color
    vec3 coloredValue = mix(vec3(grayscaleValue), u_tintColor, grayscaleValue);

    // Output the final color by multiplying with the diffuse color
    finalColor = vec4(coloredValue, 1.0) * colDiffuse;
}