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
    class Shader: Resource
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


/*
vertexCode("\
#version 140\n\
in vec2 a_Vertex;\n\
uniform mat4 projection;\n\
uniform mat4 modelview;\n\
void main()\n\
{\n\
    vec4 pos = modelview * vec4(a_Vertex, 0, 1.0);\n\
    gl_Position = projection * pos;\n\
    //gl_Position = vec4(a_Vertex, 0, 1) * modelview;\n\
}\n\
"),
fragmentCode("\
#version 140\n\
out vec4 outColor;\n\
void main()\n\
{\n\
    outColor = vec4(0.3, 0.1, 0.7, 1);\n\
}\n\
*/