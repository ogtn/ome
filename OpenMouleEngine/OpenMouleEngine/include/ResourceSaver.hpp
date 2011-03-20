////////////////////////////////////////////////////////////////////////
// ResourceSaver.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCESAVER
#define HPP_RESOURCESAVER

#include <string>
#include <fstream>

namespace OpenMouleEngine
{/*
    template <typename T>
    class ResourceSaver
    {
    public:
        ResourceSaver();
        virtual ~ResourceSaver() = 0;

        virtual void saveAs(std::string fileName, T &resource);
    };

#include "ResourceSaver.inl"
    */

    class ResourceSaver
    {
    public:
        ResourceSaver() {}
        virtual ~ResourceSaver() = 0;

        virtual void saveAs(std::string fileName, Resource &resource);
    };

    class MeshSaver: public ResourceSaver
    {
    public:
        MeshSaver() {}
        ~MeshSaver() {}

        void saveAs(std::string fileName, Mesh &mesh)
        {
            std::ofstream file(fileName.c_str(), std::ios::out | std::ios::trunc);

            if(!file)
            {
                std::cerr << "Impossible d'acceder à " + fileName << std::endl;
                return;
            }

            const std::vector<vec3> positions = mesh.getPositions();
            file << positions.size();

            for(int i = 0; i < positions.size(); i++)
                file << positions[i];

            const std::vector<vec3> normals = mesh.getNormals();
            file << normals.size();

            for(int i = 0; i < normals.size(); i++)
                file << normals[i];
        }
    };

} // namespace

#endif // HPP_RESOURCESAVER
