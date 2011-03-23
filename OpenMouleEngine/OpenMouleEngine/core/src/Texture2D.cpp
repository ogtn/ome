////////////////////////////////////////////////////////////////////////
// Texture2D.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Texture2D.hpp"

namespace OpenMouleEngine
{
    Texture2D::Texture2D(const std::string &name, GLuint id, Vector2<GLint> size, GLenum format, GLvoid *pixels)
        : Texture(name, id, GL_TEXTURE_2D),
        size(size)
    {
        bind();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.x, size.y, 0, format, GL_UNSIGNED_BYTE, pixels);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }


    Texture2D::~Texture2D()
    {
    }
} // namespace
