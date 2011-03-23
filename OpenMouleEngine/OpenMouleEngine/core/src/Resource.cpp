////////////////////////////////////////////////////////////////////////
// Resource.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Resource.hpp"
#include "ResourceManager.hpp"

namespace OpenMouleEngine
{
    Resource::Resource(const std::string &name)
        : name(name)
    {
    }


    Resource::~Resource()
    {
    }


    void Resource::saveAs(const std::string &fileName)
    {
        ResourceManager::getInstance()->saveAs(*this, fileName);
    }
} // namespace
