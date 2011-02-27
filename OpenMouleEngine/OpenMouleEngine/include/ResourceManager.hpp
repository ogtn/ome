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
        void add(ResourceLoader<T> *loader, const std::string &extensions);

        template <typename T>
        T *get(const std::string &name);

        Mesh *getMesh(const std::string &name);

        Shader *getShader(const std::string &name);

    private:
        typedef std::map<std::string, Resource *> ResourceMap;
        typedef std::map<std::string, ResourceLoader<Resource> *> LoaderMap;

        LoaderMap loaders;
        ResourceMap resources;
    };

    #include "ResourceManager.inl"

} // namespace

#endif // HPP_RESOURCEMANAGER
