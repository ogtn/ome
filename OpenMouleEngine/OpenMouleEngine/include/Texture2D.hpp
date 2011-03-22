////////////////////////////////////////////////////////////////////////
// Texture2D.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_TEXTURE2D
#define HPP_TEXTURE2D

#include "Texture.hpp"
#include "Vector2.hpp"

namespace OpenMouleEngine
{
    class Texture2D: public Texture
    {
    public:
        Texture2D(std::string &name, GLuint id, Vector2<GLint> size, GLenum format, GLvoid *pixels);
        virtual ~Texture2D();

    private:
         Vector2<GLint> size;
    };
} // namespace

#endif // HPP_TEXTURE2D
