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
        Renderable(const std::string &name);
        virtual ~Renderable();
        
        virtual void render() const = 0;        
        void translate(const vec3 &v);       
        void scale(const vec3 &v);      
        void rotate(const vec3 &v);
        
        // getters
        const vec3 &getPosition() const;
        const vec3 &getScaling() const;
        const vec3 &getRotation() const;

    protected:
        std::string name;

    private:
        vec3 position;
        vec3 scaling;
        vec3 rotation;
    };
} // namespace

#endif // HPP_RENDERABLE
