////////////////////////////////////////////////////////////////////////
// ObjLoader.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ObjLoader.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

namespace OpenMouleEngine
{
    ObjLoader::ObjLoader()
    {
    }


    ObjLoader::~ObjLoader()
    {
    }


    Mesh *ObjLoader::loadFromFile(const std::string &fileName)
    {
        std::ifstream file(fileName.c_str());

        if(!file)
        {
            std::cerr << "erreur d'ouverture de " + fileName << std::endl;
            return NULL;
        }

        std::string line;
        std::vector<vec3> *positions = new std::vector<vec3>();
        std::vector<vec3> tmp_positions;
        std::vector<vec3> *normals = new std::vector<vec3>();
        std::vector<vec3> tmp_normals;
        std::vector<vec2> *coordinates = new std::vector<vec2>();
        std::vector<vec2> tmp_coordinates;

        while(std::getline(file, line))
        {
            std::istringstream line_stream(line);
            vec3 v3;
            vec2 v2;

            // skip comments
            if(line.find("#") == 0)
                continue;

            // position
            if(line.find("v ") == 0)
            {
                line_stream.ignore();
                line_stream >> v3;
                tmp_positions.push_back(v3);
            }
            // normal vector
            else if(line.find("vn ") == 0)
            {
                line_stream.ignore(2);
                line_stream >> v3;
                tmp_normals.push_back(v3);
            }
            // texture coordinates
            else if(line.find("vt ") == 0)
            {
                line_stream.ignore(2);
                line_stream >> v2;
                tmp_coordinates.push_back(v2);
            }
            // face
            else if(line.find("f ") == 0)
            {
                int offset;
                int nb = std::count(line.begin(), line.end(), '/') / 2;

                // only triangles are considered as valid
                if(nb != 3)
                {
                    std::cerr << "Erreur dans le chargement de " + fileName << std::endl;
                    return NULL;
                }

                line_stream.ignore();

                for(int i = 0; i < 3; i++)
                {
                    // positions
                    line_stream >> offset;
                    positions->push_back(tmp_positions[offset - 1]);
                    line_stream.ignore();

                    // textures
                    line_stream >> offset;
                    coordinates->push_back(tmp_coordinates[offset - 1]);
                    line_stream.ignore();

                    // normals
                    line_stream >> offset;
                    normals->push_back(tmp_normals[offset - 1]);
                    line_stream.ignore();
                }
            }
        }

        // center mesh on (0,0,0)
        std::vector<vec3> &pos = *positions;
        vec3 posMin(pos[0]);
        vec3 posMax(pos[0]);

        for(unsigned int i = 0; i < pos.size(); i++)
        {
            posMin.x = std::min(posMin.x, pos[i].x);
            posMin.y = std::min(posMin.y, pos[i].y);
            posMin.z = std::min(posMin.z, pos[i].z);

            posMax.x = std::max(posMax.x, pos[i].x);
            posMax.y = std::max(posMax.y, pos[i].y);
            posMax.z = std::max(posMax.z, pos[i].z);
        }

        vec3 diff(vec3() - (posMax + posMin) / 2.f);

        for(unsigned int i = 0; i < pos.size(); i++)
            pos[i] = pos[i] + diff;

        // gather all arrays
        std::vector<IVertexArray *> vertexArrays;
        vertexArrays.push_back(new VertexArray<vec3, 3, GL_FLOAT>("a_Vertex", positions));
        vertexArrays.push_back(new VertexArray<vec3, 3, GL_FLOAT>("a_Normal", normals));
        vertexArrays.push_back(new VertexArray<vec2, 2, GL_FLOAT>("a_Coord0", coordinates));
        
        return new Mesh(fileName, vertexArrays);
    }
} // namespace
