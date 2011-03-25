////////////////////////////////////////////////////////////////////////
// Texture.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Texture.hpp"
#include "ShaderProgram.hpp"

namespace OpenMouleEngine
{
    Texture::Texture(const std::string &name, GLuint id, GLenum type)
        : Resource(name),
        id(id),
        type(type)
    {
    }


    Texture::~Texture()
    {
        bind();
        glDeleteTextures(1, &id);
    }


    void Texture::bind()
    {
        glBindTexture(type, id);
    }


    void Texture::sendAsUniform(ShaderProgram &program, const std::string &name, GLint texUnit)
    {
        glUniform1i(program.getUniformLocation(name), texUnit);
    }
} // namespace
