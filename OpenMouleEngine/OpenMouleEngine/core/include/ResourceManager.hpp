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
#include "Texture.hpp"
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

        void add(ResourceSaver *saver, const std::string &extensions);
        void saveAs(Resource &resource, const std::string &fileName);

        Mesh *getMesh(const std::string &name);
        Shader *getShader(const std::string &name);
        Texture *getTexture(const std::string &name);

    private:
         template <typename T>
        T *get(const std::string &name);

        typedef std::map<std::string, Resource *> ResourceMap;
        typedef std::map<std::string, ResourceLoader<Resource> *> LoaderMap;
        typedef std::map<std::string, ResourceSaver *> SaverMap;

        LoaderMap loaders;
        SaverMap savers;
        ResourceMap resources;

        friend class Singleton<ResourceManager>;
    };

    #include "ResourceManager.inl"

} // namespace

#endif // HPP_RESOURCEMANAGER
