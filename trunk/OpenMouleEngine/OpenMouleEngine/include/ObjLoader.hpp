////////////////////////////////////////////////////////////////////////
// ObjLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_OBJLOADER
#define HPP_OBJLOADER

#include "ResourceLoader.hpp"
#include "Mesh.hpp"
#include <fstream>

namespace OpenMouleEngine
{
    class ObjLoader: public ResourceLoader<Mesh>
    {
    public:
        ObjLoader();

        ~ObjLoader();

        Mesh *loadFromFile(std::string fileName);
    };


    class MeshLoader: public ResourceLoader<Mesh>
    {
    public:
        MeshLoader() {}

        ~MeshLoader() {}

        Mesh *loadFromFile(std::string fileName)
        {
            std::ifstream file(fileName.c_str());

            if(!file)
            {
                std::cerr << "erreur d'ouverture de " + fileName << std::endl;
                return NULL;
            }

            std::vector<vec3>::size_type size;

            file.read((char*)&size, sizeof(std::vector<vec3>::size_type));
            std::vector<vec3> positions(size);
            file.read((char*)&positions[0], size * sizeof(vec3));

            file.read((char*)&size, sizeof(std::vector<vec3>::size_type));
            std::vector<vec3> normals(size);
            file.read((char*)&normals[0], size * sizeof(vec3));

            return new Mesh(fileName, positions, normals);
        }
    };
} // namespace

#endif // HPP_OBJLOADER
