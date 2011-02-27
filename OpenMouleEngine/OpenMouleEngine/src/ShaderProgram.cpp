////////////////////////////////////////////////////////////////////////
// ShaderProgram.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ShaderProgram.hpp"

namespace OpenMouleEngine
{
    ShaderProgram::ShaderProgram(Shader *vertexShader, Shader *fragmentShader):
    vertexShader(vertexShader),
    fragmentShader(fragmentShader),
    linked(false)
    {
        program = glCreateProgram();
    }


    ShaderProgram::ShaderProgram(std::string vertFile, std::string fragFile):
    linked(false)
    {
        program = glCreateProgram();
        //vertexShader = ResourceManager::getInstance().getShader("vertFile");
        //fragmentShader = ResourceManager::getInstance().getShader("fragFile");
    }


    ShaderProgram::~ShaderProgram()
    {
        unbind();

        // detaching shaders from the program
        vertexShader->detach(program);
        fragmentShader->detach(program);

        glDeleteProgram(program);
    }


    ShaderProgram &ShaderProgram::link()
    {
        GLint status;
        GLsizei size;
        char log[512]; // glGetShaderProgram with the value GL_INFO_LOG_LENGTH to get the right size
        
        // attaching shaders to the program
        vertexShader->attach(program);
        fragmentShader->attach(program);

        // linking
        glLinkProgram(program);
        glGetProgramiv(program, GL_LINK_STATUS, &status);
        
        if(status == GL_FALSE)
        {
            std::cout << "Echec de l'edition de lien du programme:" << std::endl;
            glGetProgramInfoLog(program, 512, &size, log);
            std::cout << log << std::endl;
        }

        return *this;
    }


    ShaderProgram &ShaderProgram::bind()
    {
        glUseProgram(program);

        return *this;
    }


    ShaderProgram &ShaderProgram::unbind()
    {
        glUseProgram(0);

        return *this;
    }


    ShaderProgram &ShaderProgram::sendUniform(std::string name, Uniform &data)
    {
        if(uniformLocation.find(name) == uniformLocation.end())
            uniformLocation[name] = glGetUniformLocation(program, name.c_str());

        data.send(uniformLocation[name]);

        GLint location = glGetUniformLocation(program, name.c_str());

        if(location != -1)
            data.send(location);
        else
        {
            std::cout << "Error: aucune variable uniforme " << name.c_str() << " dans le shader." << std::endl;
            std::getchar();
        }

        return *this;
    }


    bool ShaderProgram::isLinked()
    {
        return linked;
    }
} // namespace
