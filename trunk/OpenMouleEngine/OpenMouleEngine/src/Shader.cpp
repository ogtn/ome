////////////////////////////////////////////////////////////////////////
// Shader.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Shader.hpp"

namespace OpenMouleEngine
{
    Shader::Shader(): 
fragmentCode(
"#version 140\n\
 void main()\n\
{\n\
    gl_FragColor = vec4(0.0, 0.8, 1.0, 1.0);\n\
}"),
vertexCode(
"#version 140\n\
in vec3 in_Vertex;\n\
void main()\n\
{\n\
    gl_Position = vec4(in_Vertex, 1.0);\n\
}")
    {
        // creating OpenGL objects
        program = glCreateProgram();
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
    }


    Shader::~Shader()
    {
        unbind();

        // detaching shaders from the program
        glDetachShader(program, fragmentShader);
        glDetachShader(program, vertexShader);

        // deleting OpenGL objects
        glDeleteProgram(program);
        glDeleteShader(fragmentShader);
        glDeleteShader(vertexShader);
    }


    Shader &Shader::link()
    {
        GLint status;
        GLsizei size;
        const GLchar *tmp;
        char log[512]; // glGetShader with the value GL_INFO_LOG_LENGTH to get the right size

        // sending sources
        tmp = static_cast<const GLchar *>(fragmentCode.c_str());
        glShaderSource(fragmentShader, 1, &tmp, NULL);

        tmp = static_cast<const GLchar *>(vertexCode.c_str());
        glShaderSource(vertexShader, 1, &tmp, NULL);

        // compiling and testing
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);

        if(status == GL_FALSE)
        {
            std::cout << "Echec de la compilation du fragment shader:" << std::endl;
            std::cout << fragmentCode.c_str() << std::endl;
            glGetShaderInfoLog(fragmentShader, 511, &size, log);
            std::cout << log << std::endl;
        }

        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

        if(status == GL_FALSE)
        {
            std::cout << "Echec de la compilation du vertex shader:" << std::endl;
            std::cout << vertexCode.c_str() << std::endl;
            glGetShaderInfoLog(vertexShader, 511, &size, log);
            std::cout << log << std::endl;
        }

        // attaching shaders to the program
        glAttachShader(program, fragmentShader);
        glAttachShader(program, vertexShader);

        // linking
        glLinkProgram(program);
        glGetProgramiv(program, GL_LINK_STATUS, &status);
        
        if(status == GL_FALSE)
        {
            std::cout << "Echec de l'edition de lien du programme:" << std::endl;
            glGetProgramInfoLog(program, 511, &size, log);
            std::cout << log << std::endl;
        }

        return *this;
    }


    Shader &Shader::bind()
    {
        glUseProgram(program);

        return *this;
    }


    Shader &Shader::unbind()
    {
        glUseProgram(0);

        return *this;
    }
} // namespace
