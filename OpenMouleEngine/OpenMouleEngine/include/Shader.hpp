////////////////////////////////////////////////////////////////////////
// Shader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SHADER
#define HPP_SHADER

#include "Uniform.hpp"
#include <GL/glew.h>
#include <iostream>
#include <map>

namespace OpenMouleEngine
{
    class Shader
    {
    public:
        Shader();

        ~Shader();

        Shader &link();

        Shader &bind();

        Shader &unbind();

        Shader &sendUniform(std::string name, Uniform &data);
    private:
        // OpenGL objects
        GLuint program;
        GLuint vertexShader;
        GLuint fragmentShader;

        // shaders code
        std::string fragmentCode;
        std::string vertexCode;

        // uniform location cache
        std::map<std::string, GLuint> uniformLocation;
    };
} // namespace

#endif // HPP_SHADER
