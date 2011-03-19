////////////////////////////////////////////////////////////////////////
// Engine.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ENGINE
#define HPP_ENGINE


#include "Light.hpp"
#include "Camera.hpp"
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

        void clearDepthBuffer();

        Camera *getCamera();

    private:
        Camera *camera;
        Mesh *mesh;
        ResourceManager *rm;
        SceneGraph *sg;
        Light *light;

        friend class Singleton<Engine>;
    };
} // namespace

#endif // HPP_ENGINE
