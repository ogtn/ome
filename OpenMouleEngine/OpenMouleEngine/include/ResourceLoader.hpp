////////////////////////////////////////////////////////////////////////
// ResourceLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCELOADER
#define HPP_RESOURCELOADER

#include <iostream>
#include <fstream>
#include <string>
#include "Shader.hpp"
#include "Mesh.hpp"

namespace OpenMouleEngine
{
    template <typename T>
    class ResourceLoader
    {
    public:
        ResourceLoader();

        virtual ~ResourceLoader() = 0;

        virtual T *loadFromFile(std::string fileName);

        virtual T *loadFromRAM(void *ptr);
    };

    #include "ResourceLoader.inl"

    // just for a temporary test
    class DefaultVertexShader: public ResourceLoader<Shader>
    {
        Shader *loadFromFile(std::string fileName)
        {
            std::ifstream file(fileName.c_str());
            std::string vertCode;
            std::string line;

            if(!file)
            {
                std::cerr << "Fichier " + fileName << " introuvable" << std::endl;
            }

            while(std::getline(file, line))
            {
                vertCode += line;
                vertCode += "\n";
            }

            return new Shader(fileName, GL_VERTEX_SHADER, vertCode);
        }
    };

    // just for a temporary test
    class DefaultFragmentShader: public ResourceLoader<Shader>
    {
        Shader *loadFromFile(std::string fileName)
        {
            std::ifstream file(fileName.c_str());
            std::string fragCode;
            std::string line;

            if(!file)
                std::cerr << "Fichier " + fileName << " introuvable" << std::endl;

            while(std::getline(file, line))
            {
                fragCode += line;
                fragCode += "\n";
            }

            return new Shader(fileName, GL_FRAGMENT_SHADER, fragCode);
        }
    };
} // namespace


#endif // HPP_RESOURCELOADER
