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
    // forward declaration
    class Resource;

    class ResourceSaver
    {
    public:
        ResourceSaver() {}
        virtual ~ResourceSaver() {};

        virtual void saveAs(const std::string &fileName, const Resource &resource) = 0;
    };

    class MeshSaver: public ResourceSaver
    {
    public:
        MeshSaver() {}
        ~MeshSaver() {}

        void saveAs(const std::string &fileName, const Resource &resource)
        {
            /*const MeshData &meshData = dynamic_cast<const MeshData &>(resource);

            std::ofstream file(fileName.c_str(), std::ofstream::binary | std::ios::out | std::ios::trunc);

            if(!file)
            {
                std::cerr << "Impossible d'acceder � " + fileName << std::endl;
                return;
            }

            unsigned int size;
            const std::vector<IVertexArray *> &arrays = meshData.arrays();

            for(unsigned int i = 0; i < arrays.size(); i++)
            {
                size = arrays[i]->bytes();
                file.write((char *)&size, sizeof(size));
                file.write(arrays[i]->data(), size);
            }*/
        }
    };

} // namespace

#endif // HPP_RESOURCESAVER
