////////////////////////////////////////////////////////////////////////
// Engine.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ENGINE
#define HPP_ENGINE

#include "Matrix4x4.hpp"
#include "Shader.hpp"
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
        GLuint vbo;
        std::vector<GLfloat> vertices;
        mat4 projection, modelview;
        Shader *shader;
    };
} // namespace

#endif // HPP_ENGINE
