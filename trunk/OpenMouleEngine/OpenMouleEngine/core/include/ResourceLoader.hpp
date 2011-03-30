////////////////////////////////////////////////////////////////////////
// ResourceLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCELOADER
#define HPP_RESOURCELOADER

#include <string>

namespace OpenMouleEngine
{
    template <typename T>
    class ResourceLoader
    {
    public:
        ResourceLoader();
        virtual ~ResourceLoader() = 0;

        virtual T *loadFromFile(const std::string &fileName);
        virtual T *loadFromRAM(void *ptr);
    };

#include "ResourceLoader.inl"

} // namespace

#endif // HPP_RESOURCELOADER
