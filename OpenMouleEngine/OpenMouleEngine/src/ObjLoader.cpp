////////////////////////////////////////////////////////////////////////
// ObjLoader.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ObjLoader.hpp"
#include <fstream>
#include <sstream>

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
        std::ifstream file(fileName);

        if(!file)
        {
            std::cout << "erreur d'ouverture de " + fileName << std::endl;
            return NULL;
        }

        std::string line;
        std::vector<vec3> positions;
        std::vector<vec3> tmp_positions;

        while(std::getline(file, line))
        {
            std::istringstream line_stream(line);
            vec3 v;

            // skip comments
            if(line.find("#") == 0)
                continue;

            // position
            if(line.find("v ") == 0)
            {
                line_stream.ignore();
                line_stream >> v.x >> v.y >> v.z;
                tmp_positions.push_back(v);
            }
            // face
            else if(line.find("f ") == 0)
            {
                int offset;

                line_stream.ignore();

                for(int i = 0; i < 3; i++)
                {
                    // positions
                    line_stream >> offset;
                    offset--;
                    positions.push_back(tmp_positions[offset]);
                    line_stream.ignore();

                    // textures
                    line_stream >> offset;
                    line_stream.ignore();

                    // normals
                    line_stream >> offset;
                    line_stream.ignore();
                }
            }
        }

        //positions.push_back(vec3(0.1f, 0.1f));
        //positions.push_back(vec3(0.9f, 0.9f));
        //positions.push_back(vec3(0.9f, 0.1f));

        vec3 v = positions[0];

        return new Mesh(fileName, positions);
    }
} // namespace
