////////////////////////////////////////////////////////////////////////
// Material.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MATERIAL
#define HPP_MATERIAL

#include "ShaderProgram.hpp"
#include "Resource.hpp"
#include "Texture.hpp"
#include "Color.hpp"
#include <string>

namespace OpenMouleEngine
{
    class Material: public Resource
    {
    public:
        Material(const std::string &name);
        ~Material();

        // setters for each property
        void setAmbiant(const Color &color = defaultAmbiant);
        void setDiffuse(const Color &color = defaultDiffuse);
        void setDiffuse(Texture *t);
        void setSpecular(const Color &color = defaultSpecular);
        void setSpecular(Texture *t);
        void setEmissive(const Color &color = defaultEmissive);
        void setEmissive(Texture *t);
        void setShininess(GLfloat s = defaultShininess);
        void setShininess(Texture *t);
        void setDefault();

        void sendAsUniform(ShaderProgram &program, const std::string &name);

    private:
        Color ambiantColor;
        Color diffuseColor;
        Color specularColor;
        Color emissiveColor;
        GLfloat shininess;

        Texture *diffuseTexture;
        Texture *specularTexture;
        Texture *emissiveTexture;
        Texture *shininessTexture;

        // default values for colors
        static Color defaultAmbiant;
        static Color defaultDiffuse;
        static Color defaultSpecular;
        static Color defaultEmissive;
        static GLfloat defaultShininess;
    };
} // namespace

#endif // HPP_MATERIAL
