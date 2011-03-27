////////////////////////////////////////////////////////////////////////
// Vector2.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_VECTOR2
#define HPP_VECTOR2

#include "MathTools.hpp"
#include "ShaderProgram.hpp"
#include <iostream>
#include <GL/glew.h>

namespace OpenMouleEngine
{
    template <typename T>
    class Vector2
    {
    public:
        Vector2(T x = 0, T y = 0);
        ~Vector2();

        void sendAsUniform(ShaderProgram &program, const std::string &name);

        union
        {
            struct
            {
                T x, y;
            };

            T tab[2];
        };
    };

    template <typename T> std::ostream &operator<<(std::ostream &ostr, const Vector2<T> &v);
    template <typename T> std::istream &operator>>(std::istream &istr, Vector2<T> &v);
    template <typename T> Vector2<T> operator*(Vector2<T> v, T t);
    template <typename T> Vector2<T> operator*(T t, Vector2<T> v);

    typedef Vector2<GLfloat> vec2;

#include "Vector2.inl"

} // namespace

#endif // HPP_VECTOR2
