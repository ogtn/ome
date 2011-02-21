////////////////////////////////////////////////////////////////////////
// Engine.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#ifndef HPP_ENGINE
#define HPP_ENGINE

#include "Matrix4x4.hpp"

namespace OpenMouleEngine
{
    typedef Vector3<GLfloat> Vec3f;
    typedef Matrix4x4<GLfloat> Mat4f;
    
    class Engine
    {
    public:
        Engine();
        
        ~Engine();
        
        Engine &render();
        
        Engine &clearColorBuffer();
    private:
    };
} // namespace

namespace ome = OpenMouleEngine;

#endif // HPP_ENGINE
