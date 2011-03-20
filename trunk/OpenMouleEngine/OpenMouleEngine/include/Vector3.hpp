////////////////////////////////////////////////////////////////////////
// Vector3.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_VECTOR3
#define HPP_VECTOR3

#include <cmath>
#ifndef M_PI
#define M_PI 3.141592653589793238462643
#endif

#ifndef MAX
#define MAX(x,y) ((x)>(y)?(x):(y))
#endif

#ifndef MIN
#define MIN(x,y) ((x)<(y)?(x):(y))
#endif

#include "ShaderProgram.hpp"
#include <iostream>
#include <GL/glew.h>

namespace OpenMouleEngine
{
    template <typename T>
    class Vector3
    {
    public:
        Vector3(T x = 0, T y = 0, T z = 0);
        ~Vector3();

        Vector3 operator+(Vector3<T> v);
        Vector3 operator-(Vector3<T> v);
        Vector3 operator*(Vector3<T> v);
        Vector3 operator/(T t);
        Vector3 &normalize();
        T dot(Vector3<T> v);
        T length();

        void sendAsUniform(ShaderProgram &program, std::string name);

        union
        {
            struct
            {
                T x, y, z;
            };

            T tab[3];
        };
    };

    template <typename T> std::ostream &operator<<(std::ostream &ostr, const Vector3<T> &v);
    template <typename T> std::istream &operator>>(std::istream &istr, Vector3<T> &v);
    template <typename T> Vector3<T> operator*(Vector3<T> v, T t);
    template <typename T> Vector3<T> operator*(T t, Vector3<T> v);

    typedef Vector3<GLfloat> vec3;

#include "Vector3.inl"

} // namespace

#endif // HPP_VECTOR3
