////////////////////////////////////////////////////////////////////////
// ResourceManager.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCEMANAGER
#define HPP_RESOURCEMANAGER

#include <map>
#include <string>
#include "Mesh.hpp"
#include "Shader.hpp"
#include "ResourceLoader.hpp"

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

        Shader *getShader(std::string name);

    private:
        typedef std::map<std::string, Resource *> ResourceMap;
        typedef std::map<std::string, ResourceLoader<Resource> *> LoaderMap;

        LoaderMap loaders;
        ResourceMap resources;
    };

    #include "ResourceManager.inl"

} // namespace

#endif // HPP_RESOURCEMANAGER
