////////////////////////////////////////////////////////////////////////
// Engine.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ENGINE
#define HPP_ENGINE

#include "Matrix4x4.hpp"
#include "SceneGraph.hpp"
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
        void render();
        
        void clearColorBuffer();

        mat4 &getProjection();

        mat4 &getModelView();

    private:
        mat4 projection, modelview;
        Mesh *mesh;
        ResourceManager *rm;
        SceneGraph *sg;

        friend class Singleton<Engine>;
    };
} // namespace

#endif // HPP_ENGINE
