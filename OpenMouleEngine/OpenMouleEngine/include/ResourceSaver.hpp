////////////////////////////////////////////////////////////////////////
// ResourceSaver.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCESAVER
#define HPP_RESOURCESAVER

#include <string>

namespace OpenMouleEngine
{
    template <typename T>
    class ResourceSaver
    {
    public:
        ResourceSaver();
        virtual ~ResourceSaver() = 0;

        virtual void saveAs(std::string fileName, T &resource);
    };

#include "ResourceSaver.inl"

} // namespace

#endif // HPP_RESOURCESAVER
