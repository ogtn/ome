////////////////////////////////////////////////////////////////////////
// ResourceLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCELOADER
#define HPP_RESOURCELOADER

#include <iostream>

namespace OpenMouleEngine
{
    template <typename T>
    class ResourceLoader
    {
    public:
        ResourceLoader();

        virtual ~ResourceLoader() = 0;

        virtual void loadFromFile(std::string fileName);

        virtual void loadFromRAM(void *ptr);
    };

    #include "ResourceLoader.inl"

} // namespace

#endif // HPP_RESOURCELOADER
