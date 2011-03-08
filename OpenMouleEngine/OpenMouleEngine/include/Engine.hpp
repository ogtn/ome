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
    class Engine: public Singleton<Engine>
    {
    private:
        Engine();
        
        ~Engine();
        
    public:
        Engine &render();
        
        Engine &clearColorBuffer();

    private:
        mat4 projection, modelview;
        ShaderProgram *shader;
        Mesh *mesh;
        ResourceManager *rm;

        friend class Singleton<Engine>;
    };
} // namespace

#endif // HPP_ENGINE
