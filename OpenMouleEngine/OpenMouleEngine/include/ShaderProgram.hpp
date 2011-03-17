////////////////////////////////////////////////////////////////////////
// ShaderProgram.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SHADERPROGRAM
#define HPP_SHADERPROGRAM

#include "Shader.hpp"
#include "Vector3.hpp"
#include <GL/glew.h>
#include <string>
#include <map>

namespace OpenMouleEngine
{
    class ShaderProgram
    {
    public:
        ShaderProgram(Shader *vertexShader, Shader *fragmentShader);

        ShaderProgram(const std::string &vertFile, const std::string &fragFile);

        ~ShaderProgram();

        ShaderProgram &link();

        ShaderProgram &bind();

        ShaderProgram &unbind();

        template <typename T>
        void sendUniform(std::string name, T &data);

        GLint getUniformLocation(std::string name);

        bool isLinked();

    private:
        GLuint program;
        Shader *vertexShader;
        Shader *fragmentShader;
        bool linked;

        // uniform location cache
        typedef std::map<std::string, GLint>  LocationMap;
        LocationMap uniformLocation;
    };

#include "ShaderProgram.inl"

} // namespace

#endif // HPP_SHADERPROGRAM
