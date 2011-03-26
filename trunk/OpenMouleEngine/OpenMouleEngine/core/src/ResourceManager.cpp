////////////////////////////////////////////////////////////////////////
// ResourceManager.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"

namespace OpenMouleEngine
{
    ResourceManager::ResourceManager()
    {
    }


    ResourceManager::~ResourceManager()
    {
    }


    MeshData *ResourceManager::getMeshData(const std::string &name)
    {
        return get<MeshData>(name);
    }


    Mesh *ResourceManager::getMesh(const std::string &name)
    {
        return get<MeshData>(name)->getMesh();
    }


    Shader *ResourceManager::getShader(const std::string &name)
    {
        return get<Shader>(name);
    }


    Texture *ResourceManager::getTexture(const std::string &name)
    {
        return get<Texture>(name);
    }


    void ResourceManager::add(ResourceSaver *saver, const std::string &extensions)
    {
        savers[extensions] = saver;
    }


    void ResourceManager::saveAs(Resource &resource, const std::string &fileName)
    {
        std::string::size_type pos = fileName.find_last_of('.');
        std::string extension = fileName.substr(pos + 1);

        if(savers.find(extension) == savers.end())
        {
            std::cerr << "Saver introuvable" << std::endl;
            return;
        }

        savers[extension]->saveAs(fileName, resource);
    }

} // namespace
