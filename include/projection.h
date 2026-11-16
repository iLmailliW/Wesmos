#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace projection
{

    constexpr float FOV = 45.0f;
    constexpr float NEAR = 0.01f;
    constexpr float FAR = 1000.0f;
    constexpr float PI = glm::pi<float>();

    /// @brief returns the matrix needed to transform vertices from world space into clip space, fed directly to the shader
    /// @param yaw yaw, in radians
    /// @param pitch pitch, in radians
    /// @return
    glm::mat4 GetVertexMatrix(int screenWidth, int screenHeight, float yaw, float pitch, float distance)
    {
        glm::mat4 proj = glm::perspective(glm::radians(FOV), (float)screenWidth / (float)screenHeight, NEAR, FAR);
        // Spherical transform
        float phi = PI / 2 - pitch;
        float yawPrime = yaw + PI / 2;
        glm::vec3 right = glm::vec3(glm::cos(yawPrime),
                                    glm::sin(yawPrime),
                                    0.0f);
        glm::vec3 cameraPos = glm::vec3(glm::cos(yaw) * glm::sin(phi) * distance,
                                        glm::sin(yaw) * glm::sin(phi) * distance,
                                        glm::cos(phi) * distance);
        glm::vec3 up = glm::cross(cameraPos, right);
        glm::mat4 view = glm::lookAt(cameraPos, glm::vec3(0.0f, 0.0f, 0.0f), up);
        return proj * view;
    }
}