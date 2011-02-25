////////////////////////////////////////////////////////////////////////
// ResourceManager.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCEMANAGER
#define HPP_RESOURCEMANAGER

#include <iostream>
#include <map>
#include "ShaderProgram.hpp"
#include "Mesh.hpp"

namespace OpenMouleEngine
{
    class ResourceManager
    {
    public:
        ResourceManager();

        ~ResourceManager();

        template <typename T>
        T *get(std::string name);

        Mesh *getMesh(std::string name);

        Mesh *getShaderProgram(std::string name);

    private:
        typedef std::map<std::string, Resource *> ResourceMap;

        ResourceMap resources;
        unsigned int cpt;
    };

    #include "ResourceManager.inl"

} // namespace

#endif // HPP_RESOURCEMANAGER
