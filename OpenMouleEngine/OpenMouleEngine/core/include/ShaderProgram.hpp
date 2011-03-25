////////////////////////////////////////////////////////////////////////
// ShaderProgram.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SHADERPROGRAM
#define HPP_SHADERPROGRAM

#include "Texture.hpp"
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
        ShaderProgram(const std::string &vertFile, const std::string &fragFile);
        ~ShaderProgram();

        void link();
        void bind();
        void unbind();

        template <typename T>
        void sendUniform(const std::string &name, T &data);
        void sendUniform(const std::string &name, Texture &data, GLint texUnit);

        GLint getUniformLocation(const std::string &name);
        GLint getAttribLocation(const std::string &name);
        bool isLinked();

    private:
        GLuint program;
        Shader *vertexShader;
        Shader *fragmentShader;
        bool linked;

        // uniform and attrib location cache
        typedef std::map<std::string, GLint>  LocationMap;
        LocationMap locations;
    };

#include "ShaderProgram.inl"

} // namespace

#endif // HPP_SHADERPROGRAM
