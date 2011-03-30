////////////////////////////////////////////////////////////////////////
// Material.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MATERIAL
#define HPP_MATERIAL

#include "Color.hpp"
#include "Resource.hpp"
#include <string>

namespace OpenMouleEngine
{
    // forward declaration
    class Texture;

    class Material: public Resource
    {
    public:
        Material(const std::string &name);
        ~Material();

        // setters for each property
        void setAmbiant(const Color3 &color = defaultAmbiant);
        void setDiffuse(const Color3 &color = defaultDiffuse);
        void setDiffuse(Texture *texture);
        void setSpecular(const Color3 &color = defaultSpecular);
        void setSpecular(Texture *texture);
        void setEmissive(const Color3 &color = defaultEmissive);
        void setEmissive(Texture *texture);
        void setShininess(GLfloat s = defaultShininess);
        void setShininess(Texture *texture);
        void setDefault();

        int bindTextures();
        void sendAsUniform(ShaderProgram &program, const std::string &name);

    private:
        Color3 ambiantColor;
        Color3 diffuseColor;
        Color3 specularColor;
        Color3 emissiveColor;
        GLfloat shininess;

        Texture *diffuseTexture;
        Texture *specularTexture;
        Texture *emissiveTexture;
        Texture *shininessTexture;

        // default values for colors
        static Color3 defaultAmbiant;
        static Color3 defaultDiffuse;
        static Color3 defaultSpecular;
        static Color3 defaultEmissive;
        static GLfloat defaultShininess;
    };
} // namespace

#endif // HPP_MATERIAL
