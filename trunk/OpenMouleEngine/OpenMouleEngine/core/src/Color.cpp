////////////////////////////////////////////////////////////////////////
// Color.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Color.hpp"
#include "ShaderProgram.hpp"

namespace OpenMouleEngine
{
    Color::Color(float r, float g, float b, float a)
        : r(r),
        g(g),
        b(b),
        a(a)
    {
    }

    Color::Color(unsigned int c)
        : r((c & 0xFF000000) / 255.f),
        g((c & 0x00FF0000) / 255.f),
        b((c & 0x0000FF00) / 255.f),
        a((c & 0x000000FF) / 255.f)
    {
    }


    Color::~Color()
    {
    }


    void Color::sendAsUniform(ShaderProgram &program, const std::string &name) const
    {
        glUniform4fv(program.getUniformLocation(name), 1, vec);
    }


    Color3::Color3(float r, float g, float b)
        : r(r),
        g(g),
        b(b)
    {
    }

    Color3::Color3(unsigned int c)
        : r((c & 0xFF000000) / 255.f),
        g((c & 0x00FF0000) / 255.f),
        b((c & 0x0000FF00) / 255.f)
    {
    }


    Color3::~Color3()
    {
    }


    void Color3::sendAsUniform(ShaderProgram &program, const std::string &name) const
    {
        glUniform3fv(program.getUniformLocation(name), 1, vec);
    }
} // namespace
