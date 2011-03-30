////////////////////////////////////////////////////////////////////////
// Engine.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ENGINE
#define HPP_ENGINE

#include <vector>
#include "Singleton.hpp"

namespace OpenMouleEngine
{
    // forward declarations
    class Light;
    class Mesh;
    class Camera;
    class SceneGraph;
    class ResourceManager;

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
