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
    
    
    Renderable &Renderable::translate(const Vector3<float> &v)
    {
        modelView.translate(v);
        
        return *this;
    }
    
    
    Renderable &Renderable::scale(const Vector3<float> &v)
    {
        modelView.scale(v);
        
        return *this;
    }
    
    
    Renderable &Renderable::rotate(const Vector3<float> &v, float theta)
    {
        modelView.rotate(v, theta);
        
        return *this;
    }
    
    
} // namespace
