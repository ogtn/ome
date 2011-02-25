////////////////////////////////////////////////////////////////////////
// ShaderProgram.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SHADER
#define HPP_SHADER

#include "Resource.hpp"
#include "Uniform.hpp"
#include <GL/glew.h>
#include <string>
#include <map>

namespace OpenMouleEngine
{
    class ShaderProgram
    {
    public:
        ShaderProgram(std::string vertFile, std::string fragFile);

        ~ShaderProgram();

        ShaderProgram &link();

        ShaderProgram &bind();

        ShaderProgram &unbind();

        ShaderProgram &sendUniform(std::string name, Uniform &data);
    private:
        // OpenGL objects
        GLuint program;
        GLuint vertexShader;
        GLuint fragmentShader;

        // shaders code
        std::string fragmentCode;
        std::string vertexCode;

        // uniform location cache
        typedef std::map<std::string, GLuint>  LocationMap;
        LocationMap uniformLocation;
    };
} // namespace

#endif // HPP_SHADER
