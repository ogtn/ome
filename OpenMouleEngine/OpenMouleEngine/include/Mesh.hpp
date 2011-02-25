////////////////////////////////////////////////////////////////////////
// Mesh.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MESH
#define HPP_MESH

#include "Resource.hpp"
#include <GL/glew.h>
#include <vector>

namespace OpenMouleEngine
{
    class Mesh: public Resource
    {
    public:
        Mesh(std::string name);

        ~Mesh();

    private:
        std::vector<GLfloat> verticesPositions;
    };
} // namespace

#endif // HPP_MESH
