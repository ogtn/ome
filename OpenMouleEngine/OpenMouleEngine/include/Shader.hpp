////////////////////////////////////////////////////////////////////////
// Shader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SHADER
#define HPP_SHADER

#include "Resource.hpp"
#include <GL/glew.h>
#include <string>

namespace OpenMouleEngine
{
    class Shader: public Resource
    {
    public:
        Shader(std::string name, GLenum type, std::string code);

        ~Shader();

        Shader &compile();

        Shader &attach(GLuint programId);

        Shader &detach(GLuint programId);

        bool isCompiled();

    private:
        GLenum type;
        GLuint id;
        std::string code;
        bool compiled;
    };
} // namespace

#endif // HPP_SHADER
