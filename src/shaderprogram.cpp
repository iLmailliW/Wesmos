#include <shaderprogram.h>
#include <iostream>
#include <fstream>
#include <sstream>

ShaderProgram::ShaderProgram(const std::string& vertexpath, const std::string& fragmentpath)
{
    std::string vertexSource, fragmentSource;
    std::ifstream vertexFile, fragmentFile;

    vertexFile.exceptions(std::fstream::failbit | std::fstream::badbit);
    fragmentFile.exceptions(std::fstream::failbit | std::fstream::badbit);

    try
    {
        vertexFile.open(vertexpath);
        fragmentFile.open(fragmentpath);

        std::stringstream vertexStream, fragmentStream;

        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();

        vertexFile.close();
        fragmentFile.close();

        vertexSource = vertexStream.str();
        fragmentSource = fragmentStream.str();
    }
    catch(const std::ifstream::failure& e)
    {
        std::cout << "Error: Shader files could not be read" << std::endl;
    }
    
    const char* vertexCode = vertexSource.c_str();
    const char* fragmentCode = fragmentSource.c_str();

    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) 
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "Error: vertex shader compilation failed\n" << infoLog << std::endl;
    }


    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) 
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "Error: fragment shader compilation failed\n" << infoLog << std::endl;
    }

    this->ID = glCreateProgram();

    glAttachShader(this->ID, vertex);
    glAttachShader(this->ID, fragment);
    glLinkProgram(this->ID);

    glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
    if (!success) 
    {
        glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
        std::cout << "Error: shader program link failed\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void ShaderProgram::setFloatUniform(const std::string& name, float value)
{
    glUniform1f(glGetAttribLocation(this->ID, name.c_str()), value);
}

void ShaderProgram::setIntUniform(const std::string& name, int value)
{
    glUniform1i(glGetAttribLocation(this->ID, name.c_str()), value);
}

void ShaderProgram::setVec3Uniform(const std::string& name, float x, float y, float z)
{
    glUniform3f(glGetAttribLocation(this->ID, name.c_str()), x, y, z);
}

void ShaderProgram::setVec4Uniform(const std::string& name, float x, float y, float z, float w)
{
    glUniform4f(glGetAttribLocation(this->ID, name.c_str()), x, y, z, w);
}

void ShaderProgram::use()
{
    glUseProgram(this->ID);
}