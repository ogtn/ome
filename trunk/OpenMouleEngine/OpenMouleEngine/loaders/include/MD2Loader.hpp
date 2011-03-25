////////////////////////////////////////////////////////////////////////
// MD2Loader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MD2LOADER
#define HPP_MD2LOADER

#include "ResourceLoader.hpp"
#include "Mesh.hpp"

namespace OpenMouleEngine
{
    class MD2Loader: public ResourceLoader<Mesh>
    {
    public:
        MD2Loader();

        ~MD2Loader();

        Mesh *loadFromFile(const std::string &fileName);

    private:
        // structure found here: http://tfcduke.developpez.com/tutoriel/format/md2/
        struct MD2Header
        {
            char ident[4];          // num�ro magique : "IDP2"
            int version;            // version du format : 8

            int skinWidth;          // largeur texture
            int skinHeight;         // hauteur texture

            int frameSize;          // taille d'une frame en octets

            int numSkins;           // nombre de skins
            int numVertices;        // nombre de vertices par frame
            int numTextureCoords;   // nombre de coordonn�es de texture
            int numTriangle;        // nombre de triangles
            int numGLcmds;          // nombre de commandes opengl
            int numFrames;          // nombre de frames

            int skinOffset;         // offset donn�es skins
            int texCoordOffset;     // offset donn�es coordonn�es de texture
            int triangleOffset;     // offset donn�es triangles
            int frameOffset;        // offset donn�es frames
            int GLCmdOffset;        // offset donn�es commandes OpenGL
            int eofOffset;          // offset fin de fichier
        };

        struct Triangle
        {
            short vertexIndex[3];
            short texCoordIndex[3];
        };

        struct KeyFrame
        {
            float scale[3];
            float translate[3];
            char name[16];
        };

        struct Vertex
        {
            unsigned char v[3];
            unsigned char lightNormalIndex;
        };
    };
} // namespace

#endif // HPP_MD2LOADER
