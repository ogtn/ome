////////////////////////////////////////////////////////////////////////
// MD2Loader.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "MD2Loader.hpp"
#include <fstream>

namespace OpenMouleEngine
{
    MD2Loader::MD2Loader()
    {
    }


    MD2Loader::~MD2Loader()
    {
    }

    
    Mesh *MD2Loader::loadFromFile(const std::string &fileName)
    {
        /*
        std::ifstream file(fileName.c_str(), std::ifstream::binary);
        MD2Header header;

        if(!file)
        {
            std::cerr << "erreur d'ouverture de " + fileName << std::endl;
            return NULL;
        }


        file.read((char *)&header, sizeof(MD2Header));
        
        // triangles
        file.seekg(header.triangleOffset);
        std::vector<Triangle> triangles(header.numTriangle);
        file.read((char *)&triangles[0], sizeof(Triangle) * header.numTriangle);
        
        // keyframes
        int cpt = 0;
        std::vector<KeyFrame> keyFrames(header.numFrames);
        std::vector<Vertex> vertices;

        for(int i = 0; i < header.numFrames; i++)
        {
            file.read((char *)&keyFrames[i], sizeof(KeyFrame));
            file.read((char *)&vertices[cpt], sizeof(header.numVertices));
            cpt += header.numFrames;
        }

        // getting frame 0
        std::vector<vec3> *positions = new std::vector<vec3>(header.numVertices);
        
        for(int i = 0; i < header.numVertices; i++)
        {
            (*positions)[i].x = keyFrames[0].scale[0] * vertices[i].v[0] + keyFrames[0].translate[0];
            (*positions)[i].y = keyFrames[0].scale[1] * vertices[i].v[1] + keyFrames[0].translate[1];
            (*positions)[i].z = keyFrames[0].scale[2] * vertices[i].v[2] + keyFrames[0].translate[2];
        }

        std::vector<IVertexArray *> vertexArrays;
        vertexArrays.push_back(new VertexArray<vec3, 3, GL_FLOAT>("a_Vertex", positions));
        
        return new Mesh(fileName, vertexArrays);
        */
        return NULL;
    }
} // namespace
