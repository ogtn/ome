////////////////////////////////////////////////////////////////////////
// Shader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SHADER
#define HPP_SHADER

#include <GL\glew.h>
#include <iostream>

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

    private:
        GLuint fragmentShader;
        GLuint vertexShader;
        GLuint program;

        std::string fragmentCode;
        std::string vertexCode;
    };
} // namespace

#endif // HPP_SHADER
