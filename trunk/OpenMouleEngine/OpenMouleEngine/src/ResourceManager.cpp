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


    Mesh *ResourceManager::getMesh(const std::string &name)
    {
        return get<Mesh>(name);
    }


    Shader *ResourceManager::getShader(const std::string &name)
    {
        return get<Shader>(name);
    }
} // namespace
