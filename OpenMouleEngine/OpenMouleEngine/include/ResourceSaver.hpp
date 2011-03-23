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
{
    class ResourceSaver
    {
    public:
        ResourceSaver() {}
        virtual ~ResourceSaver() {};

        virtual void saveAs(const std::string &fileName, Resource &resource) = 0;
    };

    class MeshSaver: public ResourceSaver
    {
    public:
        MeshSaver() {}
        ~MeshSaver() {}

        void saveAs(const std::string &fileName, Resource &resource)
        {
            /*const Mesh &mesh = (const Mesh &)resource;

            std::ofstream file(fileName.c_str(), std::ofstream::binary | std::ios::out | std::ios::trunc);

            if(!file)
            {
                std::cerr << "Impossible d'acceder à " + fileName << std::endl;
                return;
            }

            std::vector<vec3>::size_type size;

            // positions
            const std::vector<vec3> positions = mesh.getPositions();
            size = positions.size();
            file.write((char*)&size, sizeof(std::vector<vec3>::size_type));
            file.write((char*)&positions[0], positions.size() * sizeof(vec3));

            // texture coordinates
            const std::vector<vec2> textureCoordinates = mesh.getTextureCoordinates();
            size = textureCoordinates.size();
            file.write((char*)&size, sizeof(std::vector<vec3>::size_type));
            file.write((char*)&textureCoordinates[0], textureCoordinates.size() * sizeof(vec2));

            // normals
            const std::vector<vec3> normals = mesh.getNormals();
            size = normals.size();
            file.write((char*)&size, sizeof(std::vector<vec3>::size_type));
            file.write((char*)&normals[0], normals.size() * sizeof(vec3));*/
        }
    };

} // namespace

#endif // HPP_RESOURCESAVER
