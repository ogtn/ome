////////////////////////////////////////////////////////////////////////
// Renderable.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#ifndef HPP_RENDERABLE
#define HPP_RENDERABLE

#include "Matrix4x4.hpp"

namespace OpenMouleEngine
{
    class Renderable
    {
    public:
        Renderable();

        ~Renderable();
        
        virtual Renderable &render() const = 0;
        
        Renderable &translate(const Vector3<float> &v);
        
        Renderable &scale(const Vector3<float> &v);
        
        Renderable &rotate(const Vector3<float> &v, float theta);
        
    private:
        Matrix4x4<float> modelView;
        Vector3<float> position;
        Vector3<float> scaling;
        Vector3<float> rotation;
    };
} // namespace

#endif // HPP_RENDERABLE
