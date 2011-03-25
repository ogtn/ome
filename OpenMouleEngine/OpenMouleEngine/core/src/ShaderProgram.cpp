////////////////////////////////////////////////////////////////////////
// ShaderProgram.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ShaderProgram.hpp"
#include "ResourceManager.hpp"
#include <cstdio>

namespace OpenMouleEngine
{
    ShaderProgram::ShaderProgram(Shader *vertexShader, Shader *fragmentShader)
        : vertexShader(vertexShader),
        fragmentShader(fragmentShader),
        linked(false)
    {
        program = glCreateProgram();
    }


    ShaderProgram::ShaderProgram(const std::string &vertFile, const std::string &fragFile)
        : linked(false)
    {
        program = glCreateProgram();
        vertexShader = ResourceManager::getInstance()->getShader(vertFile);
        fragmentShader = ResourceManager::getInstance()->getShader(fragFile);
    }


    ShaderProgram::~ShaderProgram()
    {
        unbind();

        // detaching shaders from the program
        vertexShader->detach(program);
        fragmentShader->detach(program);

        glDeleteProgram(program);
    }


    void ShaderProgram::link()
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
            std::cerr << "Echec de l'edition de lien du programme:" << std::endl;
            glGetProgramInfoLog(program, 512, &size, log);
            std::cerr << log << std::endl;
        }
    }


    void ShaderProgram::bind()
    {
        glUseProgram(program);
    }


    void ShaderProgram::unbind()
    {
        glUseProgram(0);
    }


    void ShaderProgram::sendUniform(const std::string &name, const Texture &data, GLint texUnit)
    {
        data.sendAsUniform(*this, name, texUnit);
    }


    GLint ShaderProgram::getUniformLocation(const std::string &name)
    {
        if(locations.find(name) == locations.end())
        {
            GLint location = glGetUniformLocation(program, name.c_str());

            if(location == -1)
            {
                std::cerr << "Error: aucune variable uniforme " + name + " dans le shader." << std::endl;
                return -1;
            }

            locations[name] = location;
        }

        return locations[name];
    }


    GLint ShaderProgram::getAttribLocation(const std::string &name)
    {
        if(locations.find(name) == locations.end())
        {
            GLint location = glGetAttribLocation(program, name.c_str());

            if(location == -1)
            {
                std::cerr << "Error: aucun attribut de vertex " + name + " dans le shader." << std::endl;
                return -1;
            }

            locations[name] = location;
        }

        return locations[name];
    }


    bool ShaderProgram::isLinked()
    {
        return linked;
    }
} // namespace
