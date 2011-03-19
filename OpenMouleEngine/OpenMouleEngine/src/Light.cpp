////////////////////////////////////////////////////////////////////////
// Light.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Light.hpp"

namespace OpenMouleEngine
{
    Light::Light(Color color)
        : color(color)
    {
    }


    Light::~Light()
    {
    }


    void Light::sendAsUniform(ShaderProgram &program, std::string name)
    {
        color.sendAsUniform(program, name + ".color");
    }
} // namespace
