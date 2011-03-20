////////////////////////////////////////////////////////////////////////
// ObjLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_OBJLOADER
#define HPP_OBJLOADER

#include "ResourceLoader.hpp"
#include "Mesh.hpp"

namespace OpenMouleEngine
{
    class ObjLoader: public ResourceLoader<Mesh>
    {
    public:
        ObjLoader();

        ~ObjLoader();

        Mesh *loadFromFile(std::string fileName);

    private:
    };
} // namespace

#endif // HPP_OBJLOADER
