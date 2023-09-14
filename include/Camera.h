#pragma once

#include "glm/glm.hpp"

struct Camera {
    glm::vec3 cameraPosition;
    glm::vec3 targetPosition;
    glm::vec3 upVector;
    glm::vec3 rightVector;

    // Constructor to initialize camera properties
    Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up)
        : cameraPosition(position), targetPosition(target), upVector(up) {
        // Calculate the initial right vector
        rightVector = glm::normalize(glm::cross(target - cameraPosition, upVector));
    }

    // Function to rotate the camera horizontally (left or right)
    void Rotate(float angleRadians) {
        // Rotate the camera around its own up vector
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angleRadians, upVector);
        // Update the target position and right vector
        targetPosition = cameraPosition + glm::mat3(rotationMatrix) * (targetPosition - cameraPosition);
        rightVector = glm::normalize(glm::cross(targetPosition - cameraPosition, upVector));
    }

    // Function to move the camera forward
    void MoveForward(float movementSpeed) {
        glm::vec3 viewDirection = glm::normalize(targetPosition - cameraPosition);
        cameraPosition += viewDirection * movementSpeed;
        targetPosition += viewDirection * movementSpeed;
    }

    // Function to move the camera backward
    void MoveBackward(float movementSpeed) {
        glm::vec3 viewDirection = glm::normalize(targetPosition - cameraPosition);
        cameraPosition -= viewDirection * movementSpeed;
        targetPosition -= viewDirection * movementSpeed;
    }
};