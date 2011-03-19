////////////////////////////////////////////////////////////////////////
// Shader.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Shader.hpp"
#include <iostream>

namespace OpenMouleEngine
{
    Shader::Shader(std::string name, GLenum type, std::string code)
    : Resource(name),
    type(type),
    code(code),
    compiled(false)
    {
        id = glCreateShader(type);
    }


    Shader::~Shader()
    {
        glDeleteShader(id);
    }


    Shader &Shader::compile()
    {
        GLint status;
        GLsizei size;
        const GLchar *tmp;
        char log[512]; // glGetShaderProgram with the value GL_INFO_LOG_LENGTH to get the right size

        // sending sources
        tmp = static_cast<const GLchar *>(code.c_str());
        glShaderSource(id, 1, &tmp, NULL);

        // compiling and testing
        glCompileShader(id);
        glGetShaderiv(id, GL_COMPILE_STATUS, &status);

        if(status == GL_FALSE)
        {
            if(type == GL_FRAGMENT_SHADER)
                std::cerr << "Echec de la compilation du fragment shader:" << std::endl;
            else if(type == GL_VERTEX_SHADER)
                std::cerr << "Echec de la compilation du vertex shader:" << std::endl;
                
            glGetShaderInfoLog(id, 512, &size, log);
            std::cerr << log << std::endl;
        }
        else
            compiled = true;

        return *this;
    }


    Shader &Shader::attach(GLuint programId)
    {
        glAttachShader(programId, id);

        return *this;
    }


    Shader &Shader::detach(GLuint programId)
    {
        glDetachShader(programId, id);

        return *this;
    }


    bool Shader::isCompiled()
    {
        return compiled;
    }
} // namespace
