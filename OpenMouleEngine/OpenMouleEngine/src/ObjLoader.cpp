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
                line_stream >> v;
                tmp_positions.push_back(v);
            }
            // normal vector
            else if(line.find("vn ") == 0)
            {
                line_stream.ignore(2);
                line_stream >> v;
                tmp_normals.push_back(v);
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
                    offset--;
                    positions.push_back(tmp_positions[offset]);
                    line_stream.ignore();

                    // textures
                    line_stream >> offset;
                    line_stream.ignore();

                    // normals
                    line_stream >> offset;
                    offset--;
                    normals.push_back(tmp_normals[offset]);
                    line_stream.ignore();
                }
            }
        }

        Mesh *res = new Mesh(fileName, positions, normals);
        //res->centerPivot();

        return res;
    }
} // namespace
