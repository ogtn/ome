////////////////////////////////////////////////////////////////////////
// Uniform.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_UNIFORM
#define HPP_UNIFORM

#include <GL/glew.h>
#include <iostream>
namespace OpenMouleEngine
{
    class Uniform
    {
    public:
        virtual Uniform &send(GLint location) = 0;

    private:
    };
} // namespace

#endif // HPP_UNIFORM
