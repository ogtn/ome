////////////////////////////////////////////////////////////////////////
// Color.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Color.hpp"

namespace OpenMouleEngine
{
    Color::Color(float r, float g, float b, float a):
    r(r),
    g(g),
    b(b),
    a(a)
    {
    }

    Color::Color(unsigned int c):
    r((c & 0xFF000000) / 255.f),
    g((c & 0x00FF0000) / 255.f),
    b((c & 0x0000FF00) / 255.f),
    a((c & 0x000000FF) / 255.f)
    {
    }


    Color::~Color()
    {
    }


    void Color::send(GLint location)
    {
        glUniform4fv(location, 1, vec);
    }
} // namespace
