////////////////////////////////////////////////////////////////////////
// DevILLoader.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "DevILLoader.hpp"
#include "Texture2D.hpp"
#include <IL/il.h>

namespace OpenMouleEngine
{
    DevILLoader::DevILLoader()
    {
        ilInit();
        ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
        ilEnable(IL_ORIGIN_SET);
    }


    DevILLoader::~DevILLoader()
    {
    }


    Texture *DevILLoader::loadFromFile(std::string fileName)
    {
        GLuint id;
        ILuint il_id;

        ilGenImages(1, &il_id);
        ilBindImage(il_id);

        if(ilLoadImage((wchar_t *) fileName.c_str()) == IL_FALSE)
        {
            ilDeleteImage(il_id);
            std::cerr << "Impossible de charger: " + fileName << std::endl;
            return NULL;
        }

        if(ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE) == IL_FALSE)
        {
            ilDeleteImage(il_id);
            std::cerr << "Impossible de convertir: " + fileName << std::endl;
            return NULL;
        }

        Vector2<int> size(ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT));
        GLenum format = ilGetInteger(IL_IMAGE_FORMAT);

        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
        Texture *res = new Texture2D(fileName, id, size, format, ilGetData());
        ilDeleteImage(il_id);

        return res;
    }
} // namespace
