////////////////////////////////////////////////////////////////////////
// Material.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Material.hpp"
#include "Texture.hpp"
#include "ShaderProgram.hpp"

namespace OpenMouleEngine
{
    // default colors
    Color3 Material::defaultAmbiant(0.1F, 0.1F, 0.1F);
    Color3 Material::defaultDiffuse(0.3F, 0.3F, 0.3F);
    Color3 Material::defaultSpecular(0.9F, 0.9F, 0.9F);
    Color3 Material::defaultEmissive(0.0F, 0.0F, 0.0F);
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


    void Material::setAmbiant(const Color3 &color)
    {
        ambiantColor = color;
    }


    void Material::setDiffuse(const Color3 &color)
    {
        diffuseColor = color;
    }


    void Material::setDiffuse(Texture *texture)
    {
        diffuseTexture = texture;
    }


    void Material::setSpecular(const Color3 &color)
    {
        specularColor = color;
    }


    void Material::setSpecular(Texture *texture)
    {
        specularTexture = texture;
    }


    void Material::setEmissive(const Color3 &color)
    {
        emissiveColor = color;
    }


    void Material::setEmissive(Texture *texture)
    {
        emissiveTexture = texture;
    }


    void Material::setShininess(GLfloat s)
    {
        shininess = s;
    }


    void Material::setShininess(Texture *texture)
    {
        shininessTexture = texture;
    }


    void Material::setDefault(void)
    {
        ambiantColor = defaultAmbiant;
        diffuseColor = defaultDiffuse;
        specularColor = defaultSpecular;
        emissiveColor = defaultEmissive;
        shininess = defaultShininess;
    }


    int Material::bindTextures()
    {
        int textureUnit = 0;

        if(diffuseTexture != NULL)
            diffuseTexture->bind(textureUnit++);

        return textureUnit;
    }


    void Material::sendAsUniform(ShaderProgram &program, const std::string &name)
    {
        int textureUnit = 0;

        ambiantColor.sendAsUniform(program, name + ".ambiantColor");

        if(diffuseTexture != NULL)
            diffuseTexture->sendAsUniform(program, name + ".diffuseTexture", textureUnit++);
        else
            diffuseColor.sendAsUniform(program, name + ".diffuseColor");

        specularColor.sendAsUniform(program, name + ".specularColor");
        //emissiveColor.sendAsUniform(program, name + ".emissiveColor");
        glUniform1f(program.getUniformLocation(name + ".shininess"), shininess);
    }
} // namespace

/*
void Mesh::setTexture(const std::string &name)
{
    setTexture(ResourceManager::getInstance()->getTexture(name));
}
*/