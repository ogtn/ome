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


    Mesh *ObjLoader::loadFromFile(std::string fileName)
    {
        std::ifstream file(fileName.c_str());

        if(!file)
        {
            std::cerr << "erreur d'ouverture de " + fileName << std::endl;
            return NULL;
        }

        std::string line;
        std::vector<vec3> positions;
        std::vector<vec3> tmp_positions;
        std::vector<vec3> normals;
        std::vector<vec3> tmp_normals;
        std::vector<vec2> textureCoordinates;
        std::vector<vec2> tmp_textureCoordinates;

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
                tmp_textureCoordinates.push_back(v2);
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
                    positions.push_back(tmp_positions[offset - 1]);
                    line_stream.ignore();

                    // textures
                    line_stream >> offset;
                    textureCoordinates.push_back(tmp_textureCoordinates[offset - 1]);
                    line_stream.ignore();

                    // normals
                    line_stream >> offset;
                    normals.push_back(tmp_normals[offset - 1]);
                    line_stream.ignore();
                }
            }
        }

        return new Mesh(fileName, positions, textureCoordinates, normals);
    }
} // namespace
