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
#include "Singleton.hpp"
#include "ResourceSaver.hpp"
#include "ResourceLoader.hpp"

namespace OpenMouleEngine
{
    class ResourceManager: public Singleton<ResourceManager>
    {
    private:
        ResourceManager();
        ~ResourceManager();

    public:
        template <typename T>
        void add(ResourceLoader<T> *loader, const std::string &extensions);

        template <typename T>
        void add(ResourceSaver<T> *saver, const std::string &extensions);

        template <typename T>
        T *get(const std::string &name);

        Mesh *getMesh(const std::string &name);
        Shader *getShader(const std::string &name);

        template <typename T>
        void saveAs(T &resource, std::string fileName);

    private:
        typedef std::map<std::string, Resource *> ResourceMap;
        typedef std::map<std::string, ResourceLoader<Resource> *> LoaderMap;
        typedef std::map<std::string, ResourceSaver<Resource> *> SaverMap;

        LoaderMap loaders;
        SaverMap savers;
        ResourceMap resources;

        friend class Singleton<ResourceManager>;
    };

    #include "ResourceManager.inl"

} // namespace

#endif // HPP_RESOURCEMANAGER
