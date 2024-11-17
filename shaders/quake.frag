#version 330 core
precision highp float;

in vec2 fragTexCoord;
out vec4 finalColor;

void main() {
    // Center coordinates (assuming fragTexCoord is in 0 to 1 range)
    vec2 center = vec2(0.5, 0.5);

    // Calculate distance from current pixel to center
    float dist = distance(fragTexCoord, center);

    // Define circle radius (adjust this value to change circle size)
    float radius = 0.25;

    // Create smooth circle edge
    float smoothWidth = 0.001;
    float circle = 1.0 - smoothstep(radius - smoothWidth, radius + smoothWidth, dist);

    // Create circle color (white circle on black background)
    // You can modify the vec4 values to change the circle's color
    // finalColor = vec4(vec3(circle), 1.0);

    // Alternative: Create a colored circle
    vec3 circleColor = vec3(fragTexCoord.x, 0.0, fragTexCoord.y); // Red circle
    finalColor = vec4(circleColor * circle, 1.0);
}
