////////////////////////////////////////////////////////////////////////
// Renderable.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Renderable.hpp"

namespace OpenMouleEngine
{
    Renderable::Renderable()
    {
    }


    Renderable::~Renderable()
    {
    }
    
    
    void Renderable::translate(const Vector3<float> &v)
    {
        modelView.translate(v);
    }
    
    
    void Renderable::scale(const Vector3<float> &v)
    {
        modelView.scale(v);
    }
    
    
    void Renderable::rotate(const Vector3<float> &v, float theta)
    {
        modelView.rotate(v, theta);;
    }
    
    
} // namespace
