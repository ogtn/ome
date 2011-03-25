////////////////////////////////////////////////////////////////////////
// Material.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Material.hpp"

namespace OpenMouleEngine
{
    // default colors
    Color Material::defaultAmbiant(0.05F, 0.05F, 0.05F, 1.0F);
    Color Material::defaultDiffuse(0.2F, 0.2F, 0.2F, 1.0F);
    Color Material::defaultSpecular(0.8F, 0.8F, 0.8F, 1.0F);
    Color Material::defaultEmissive(0.0F, 0.0F, 0.0F, 1.0F);
    GLfloat Material::defaultShininess = 64.0F;


    Material::Material(const std::string &name)
        : Resource(name),
        ambiantColor(defaultAmbiant),
        diffuseColor(defaultDiffuse),
        specularColor(defaultSpecular),
        emissiveColor(defaultEmissive),
        shininess(defaultShininess),
        diffuseTexture(NULL),
        specularTexture(NULL),
        emissiveTexture(NULL),
        shininessTexture(NULL)
    {
    }


    Material::~Material()
    {
    }


    void Material::setAmbiant(const Color &color)
    {
        ambiantColor = color;
    }


    void Material::setDiffuse(const Color &color)
    {
        diffuseColor = color;
    }


    void Material::setDiffuse(Texture *t)
    {
    }


    void Material::setSpecular(const Color &color)
    {
        specularColor = color;
    }


    void Material::setSpecular(Texture *t)
    {
    }


    void Material::setEmissive(const Color &color)
    {
        emissiveColor = color;
    }


    void Material::setEmissive(Texture *t)
    {
    }


    void Material::setShininess(GLfloat s)
    {
        shininess = s;
    }


    void Material::setShininess(Texture *t)
    {
    }


    void Material::setDefault(void)
    {
        ambiantColor = defaultAmbiant;
        diffuseColor = defaultDiffuse;
        specularColor = defaultSpecular;
        emissiveColor = defaultEmissive;
        shininess = defaultShininess;
    }


    void Material::sendAsUniform(ShaderProgram &program, const std::string &name)
    {
        ambiantColor.sendAsUniform(program, name + ".ambiantColor");
        diffuseColor.sendAsUniform(program, name + ".diffuseColor");
        specularColor.sendAsUniform(program, name + ".specularColor");
        emissiveColor.sendAsUniform(program, name + ".emissiveColor");
        glUniform1f(program.getUniformLocation(name + ".shininess"), shininess);
    }
} // namespace
