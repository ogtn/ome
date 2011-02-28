////////////////////////////////////////////////////////////////////////
// Engine.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ENGINE
#define HPP_ENGINE

#include "Matrix4x4.hpp"
#include "ShaderProgram.hpp"
#include "ResourceManager.hpp"
#include <vector>

namespace OpenMouleEngine
{    
    class Engine
    {
    public:
        Engine();
        
        ~Engine();
        
        Engine &render();
        
        Engine &clearColorBuffer();

    private:
        mat4 projection, modelview;
        ShaderProgram *shader;
        Mesh *mesh;
        ResourceManager rm;
    };
} // namespace

#endif // HPP_ENGINE
