////////////////////////////////////////////////////////////////////////
// ShaderProgram.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ShaderProgram.hpp"
#include "ResourceManager.hpp"

namespace OpenMouleEngine
{
    ShaderProgram::ShaderProgram(Shader *vertexShader, Shader *fragmentShader):
    vertexShader(vertexShader),
    fragmentShader(fragmentShader),
    linked(false)
    {
        program = glCreateProgram();
    }


    ShaderProgram::ShaderProgram(const std::string &vertFile, const std::string &fragFile):
    linked(false)
    {
        program = glCreateProgram();
        vertexShader = ResourceManager::getInstance()->getShader("vertFile.vert");
        fragmentShader = ResourceManager::getInstance()->getShader("fragFile.frag");
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
        
        // compiling shaders if needed
        if(!vertexShader->isCompiled())
            vertexShader->compile();

        if(!fragmentShader->isCompiled())
            fragmentShader->compile();

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
        {
            GLint location = glGetUniformLocation(program, name.c_str());

            if(location == -1)
            {
                std::cout << "Error: aucune variable uniforme " + name + " dans le shader." << std::endl;
                std::getchar();
            }

            uniformLocation[name] = location;
        }

        data.send(uniformLocation[name]);

        return *this;
    }


    bool ShaderProgram::isLinked()
    {
        return linked;
    }
} // namespace
