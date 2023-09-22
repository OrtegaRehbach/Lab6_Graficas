
#include "Shaders.h"

Vertex vertexShader(const Vertex& vertex, const Uniforms& uniforms) {
    // Apply transformations to the input vertex using the matrices from the uniforms
    glm::vec4 clipSpaceVertex = uniforms.projection * uniforms.view * uniforms.model * glm::vec4(vertex.position, 1.0f);

    // Perspective divide
    glm::vec3 ndcVertex = glm::vec3(clipSpaceVertex) / clipSpaceVertex.w;

    // Apply the viewport transform
    glm::vec4 screenVertex = uniforms.viewport * glm::vec4(ndcVertex, 1.0f);

    // Transform the normal
    glm::vec3 transformedNormal = glm::mat3(uniforms.model) * vertex.normal;
    transformedNormal = glm::normalize(transformedNormal);

    // Return the transformed vertex
    return Vertex{
        glm::vec3(screenVertex),    // Transformed position
        transformedNormal,          // Transformed normal
        vertex.position             // Original position
    };
}

Fragment fragmentShader(const Fragment& fragment) {
    glm::vec3 fragmentPosition(fragment.x, fragment.y, fragment.z);
    Color fragmentColor = Color(120, 0, 220);

    float intensity = fragment.intensity;

    float xPos = fragment.originalPosition.x;
    float yPos = fragment.originalPosition.y;

    fragmentColor = fragmentColor + Color(0, 0, 255) * 1.2f * std::abs(std::sin(6 * (3.1416f * yPos) + 0.5f) * std::sin(9 * 3.1416f * yPos + 20 * std::pow(yPos, 3)) + 0.6f * std::sin(0.4f * 3.146f * xPos + 3));

    Fragment shadedFragment = Fragment(fragmentPosition, fragmentColor * intensity);
    
    return shadedFragment;
}

Fragment testFragmentShader(const Fragment& fragment) {
    glm::vec3 fragmentPosition(fragment.x, fragment.y, fragment.z);
    Color fragmentColor = Color(220, 220, 220);

    float intensity = fragment.intensity;

    Fragment shadedFragment = Fragment(fragmentPosition, fragmentColor * intensity);
    
    return shadedFragment;
}