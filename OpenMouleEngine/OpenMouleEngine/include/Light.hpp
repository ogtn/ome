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
        Light(Color color = Color());

        ~Light();

        virtual void sendAsUniform(ShaderProgram &program, std::string name);

    private:
        Color color;
    };
} // namespace

#endif // HPP_LIGHT
