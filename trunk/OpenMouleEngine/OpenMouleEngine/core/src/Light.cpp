////////////////////////////////////////////////////////////////////////
// Light.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Light.hpp"

namespace OpenMouleEngine
{
    Light::Light()
        : ambiantColor(),
        diffuseColor(),
        specularColor()
    {
    }


    Light::~Light()
    {
    }


    void Light::sendAsUniform(ShaderProgram &program, const std::string &name)
    {
        ambiantColor.sendAsUniform(program, name + ".ambiantColor");
        diffuseColor.sendAsUniform(program, name + ".diffuseColor");
        specularColor.sendAsUniform(program, name + ".specularColor");        
    }


    DirectionalLight::DirectionalLight(const vec3 &direction)
        : direction(direction)
    {
    }
    
    
    DirectionalLight::~DirectionalLight()
    {
    }

    
    void DirectionalLight::sendAsUniform(ShaderProgram &program, const std::string &name)
    {
        Light::sendAsUniform(program, name);
        direction.sendAsUniform(program, name + ".direction");
    }
} // namespace
