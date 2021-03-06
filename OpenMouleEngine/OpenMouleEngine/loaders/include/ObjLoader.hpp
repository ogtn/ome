////////////////////////////////////////////////////////////////////////
// ObjLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_OBJLOADER
#define HPP_OBJLOADER

#include "ResourceLoader.hpp"
#include "MeshData.hpp"
#include <fstream>

namespace OpenMouleEngine
{
    class ObjLoader: public ResourceLoader<MeshData>
    {
    public:
        ObjLoader();
        ~ObjLoader();

        MeshData *loadFromFile(const std::string &fileName);
    };


    class MeshLoader: public ResourceLoader<Mesh>
    {
    public:
        MeshLoader() {}
        ~MeshLoader() {}

        /*Mesh *loadFromFile(std::string fileName)
        {
            std::ifstream file(fileName.c_str(), std::ifstream::binary);

            if(!file)
            {
                std::cerr << "erreur d'ouverture de " + fileName << std::endl;
                return NULL;
            }

            std::vector<vec3>::size_type size;

            // positions
            file.read((char*)&size, sizeof(std::vector<vec3>::size_type));
            std::vector<vec3> *positions = new std::vector<vec3>(size);
            file.read((char*)&(*positions)[0], size * sizeof(vec3));

            // normals
            file.read((char*)&size, sizeof(std::vector<vec3>::size_type));
            std::vector<vec3> *normals = new std::vector<vec3>(size);
            file.read((char*)&(*normals)[0], size * sizeof(vec3));

            // texture coordinates
            file.read((char*)&size, sizeof(std::vector<vec2>::size_type));
            std::vector<vec2> *coordinates = new std::vector<vec2>(size);
            file.read((char*)&(*coordinates)[0], size * sizeof(vec2));
            
            return new Mesh(fileName, positions, normals, coordinates);
        }*/
    };
} // namespace

#endif // HPP_OBJLOADER
