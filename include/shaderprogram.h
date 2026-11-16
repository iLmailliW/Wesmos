#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class ShaderProgram {
    public:
        unsigned int ID;

        ShaderProgram(const std::string& vertexpath, const std::string& fragmentpath);

        void setFloatUniform(const std::string& name, float value);

        void setIntUniform(const std::string& name, int value);

        void setVec3Uniform(const std::string& name, float x, float y, float z);

        void setVec4Uniform(const std::string& name, float x, float y, float z, float w);

        void use();
};