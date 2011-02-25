////////////////////////////////////////////////////////////////////////
// ShaderProgram.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SHADERPROGRAM
#define HPP_SHADERPROGRAM

#include "Uniform.hpp"
#include "Shader.hpp"
#include <GL/glew.h>
#include <string>
#include <map>

namespace OpenMouleEngine
{
    class ShaderProgram
    {
    public:
        ShaderProgram(Shader *vertexShader, Shader *fragmentShader);

        ~ShaderProgram();

        ShaderProgram &link();

        ShaderProgram &bind();

        ShaderProgram &unbind();

        ShaderProgram &sendUniform(std::string name, Uniform &data);

        bool isLinked();

    private:
        GLuint program;
        Shader *vertexShader;
        Shader *fragmentShader;
        bool linked;

        // uniform location cache
        typedef std::map<std::string, GLuint>  LocationMap;
        LocationMap uniformLocation;
    };
} // namespace

#endif // HPP_SHADERPROGRAM
