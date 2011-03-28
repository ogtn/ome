////////////////////////////////////////////////////////////////////////
// Vector3.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_VECTOR3
#define HPP_VECTOR3

#include "Vector2.hpp"

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
        Vector3 operator/(T t);
        Vector3 &normalize();
        T length();

        void sendAsUniform(ShaderProgram &program, const std::string &name);

        // needed for VertexArray?
        //static int nbElements();
        //static GLenum GLType();

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
    template <typename T> Vector3<T> operator*(Vector3<T> v1, Vector3<T> v2);
    template <typename T> Vector3<T> cross(Vector3<T> v1, Vector3<T> v2);
    template <typename T> T dot(Vector3<T> v1, Vector3<T> v2);

    typedef Vector3<GLfloat> vec3;

#include "Vector3.inl"

} // namespace

#endif // HPP_VECTOR3
