////////////////////////////////////////////////////////////////////////
// Texture.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_TEXTURE
#define HPP_TEXTURE

#include "Resource.hpp"
#include "ShaderProgram.hpp"
#include <GL/glew.h>

namespace OpenMouleEngine
{
    class Texture: public Resource
    {
    public:
        Texture(std::string &name, GLuint id, GLenum type);
        virtual ~Texture() = 0;

        void bind();
        void sendAsUniform(ShaderProgram &program, std::string name);

    private:
        GLuint id;
        GLenum type;
    };
} // namespace

#endif // HPP_TEXTURE
