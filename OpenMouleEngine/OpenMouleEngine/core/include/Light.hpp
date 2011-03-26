////////////////////////////////////////////////////////////////////////
// Light.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_LIGHT
#define HPP_LIGHT

#include "Vector3.hpp"
#include "Color.hpp"

namespace OpenMouleEngine
{
    class Light
    {
    public:
        Light();
        ~Light();

        virtual void sendAsUniform(ShaderProgram &program, const std::string &name);

    private:
        Color3 ambiantColor;
        Color3 diffuseColor;
        Color3 specularColor;
    };


    class DirectionalLight: public Light
    {
    public:
        DirectionalLight(const vec3 &direction);
        ~DirectionalLight();

        void sendAsUniform(ShaderProgram &program, const std::string &name);

    private:
        vec3 direction;
    };
} // namespace

#endif // HPP_LIGHT
