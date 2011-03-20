////////////////////////////////////////////////////////////////////////
// ShaderLoader.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ShaderLoader.hpp"
#include <iostream>
#include <fstream>

namespace OpenMouleEngine
{
    VertexShaderLoader::VertexShaderLoader()
    {
    }


    VertexShaderLoader::~VertexShaderLoader()
    {
    }


    Shader *VertexShaderLoader::loadFromFile(std::string fileName)
    {
        return new Shader(fileName, GL_VERTEX_SHADER, getShaderCode(fileName));
    }


    FragmentShaderLoader::FragmentShaderLoader()
    {
    }


    FragmentShaderLoader::~FragmentShaderLoader()
    {
    }


    Shader *FragmentShaderLoader::loadFromFile(std::string fileName)
    {
        return new Shader(fileName, GL_FRAGMENT_SHADER, getShaderCode(fileName));
    }


    std::string getShaderCode(std::string &fileName)
    {
        std::ifstream file(fileName.c_str());
        std::string code;
        std::string line;

        if(!file)
            std::cerr << "Fichier " + fileName << " introuvable" << std::endl;

        while(std::getline(file, line))
        {
            code += line;
            code += "\n";
        }

        return code;
    }
} // namespace
