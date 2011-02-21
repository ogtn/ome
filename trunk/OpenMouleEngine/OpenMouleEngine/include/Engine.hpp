////////////////////////////////////////////////////////////////////////
// Engine.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ENGINE
#define HPP_ENGINE

#include "Matrix4x4.hpp"
#include <vector>

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
        GLuint vbo;
        std::vector<GLfloat> vertices;
    };
} // namespace

#endif // HPP_ENGINE
