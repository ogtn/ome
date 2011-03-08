////////////////////////////////////////////////////////////////////////
// Renderable.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RENDERABLE
#define HPP_RENDERABLE

#include "Matrix4x4.hpp"

namespace OpenMouleEngine
{
    class Renderable
    {
    public:
        Renderable();

        virtual ~Renderable();
        
        virtual void render() const = 0;
        
        void translate(const Vector3<float> &v);
        
        void scale(const Vector3<float> &v);
        
        void rotate(const Vector3<float> &v, float theta);
        
    private:
        Matrix4x4<float> modelView;
        Vector3<float> position;
        Vector3<float> scaling;
        Vector3<float> rotation;
    };
} // namespace

#endif // HPP_RENDERABLE
