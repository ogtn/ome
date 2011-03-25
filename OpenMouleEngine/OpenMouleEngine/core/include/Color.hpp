////////////////////////////////////////////////////////////////////////
// Color.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_COLOR
#define HPP_COLOR

#include <GL/glew.h>
#include <string>

namespace OpenMouleEngine
{
    // forward declaration
    class ShaderProgram;

    class Color
    {
    public:
        Color(float r = 1, float g = 1, float b = 1, float a = 1);
        Color(unsigned int c);
        ~Color();

        void sendAsUniform(ShaderProgram &program, const std::string &name) const;

        union
        {
            struct
            {
                GLfloat r, g, b, a;
            };

            GLfloat vec[4];
        };
    };


    class Color3
    {
    public:
        Color3(float r = 1, float g = 1, float b = 1);
        Color3(unsigned int c);
        ~Color3();

        void sendAsUniform(ShaderProgram &program, const std::string &name) const;

        union
        {
            struct
            {
                GLfloat r, g, b;
            };

            GLfloat vec[3];
        };
    };
} // namespace

#endif // HPP_COLOR
