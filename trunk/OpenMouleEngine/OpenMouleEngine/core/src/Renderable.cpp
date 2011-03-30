////////////////////////////////////////////////////////////////////////
// Renderable.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Renderable.hpp"

namespace OpenMouleEngine
{
    Renderable::Renderable(const std::string &name)
        : name(name),
        position(),
        scaling(1.f, 1.f ,1.f),
        rotation()
    {
    }


    Renderable::~Renderable()
    {
    }


    void Renderable::translate(const vec3 &v)
    {
        position = position + v;
    }


    void Renderable::scale(const vec3 &v)
    {
        scaling = scaling * v;
    }


    void Renderable::rotate(const vec3 &v)
    {
        rotation = rotation + v;
    }


    const vec3 &Renderable::getPosition() const
    {
        return position;
    }


    const vec3 &Renderable::getScaling() const
    {
        return scaling;
    }


    const vec3 &Renderable::getRotation() const
    {
        return rotation;
    }
} // namespace
