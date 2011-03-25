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
        glBindTexture(type, id);
    }


    Texture::~Texture()
    {
        glBindTexture(type, id);
        glDeleteTextures(1, &id);
    }


    void Texture::bind(int textureUnit)
    {
        glActiveTexture(GL_TEXTURE0 + textureUnit);
        glBindTexture(type, id);
    }


    void Texture::sendAsUniform(ShaderProgram &program, const std::string &name, GLint texUnit) const
    {
        glUniform1i(program.getUniformLocation(name), texUnit);
    }
} // namespace
