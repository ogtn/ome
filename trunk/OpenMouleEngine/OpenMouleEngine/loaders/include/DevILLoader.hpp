////////////////////////////////////////////////////////////////////////
// DevILLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_DEVILLOADER
#define HPP_DEVILLOADER

#include "ResourceLoader.hpp"
#include "Texture.hpp"

namespace OpenMouleEngine
{
    class DevILLoader: public ResourceLoader<Texture>
    {
    public:
        DevILLoader();
        ~DevILLoader();

        Texture *loadFromFile(const std::string &fileName);
    };
} // namespace

#endif // HPP_DEVILLOADER
