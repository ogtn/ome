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
#include <iostream>
#include <GL/glew.h>

namespace OpenMouleEngine
{
    // forward declaration, to avoid warning about the friend
    class ShaderProgram;
    template <typename T> class Vector3;
    typedef Vector3<GLfloat> vec3;
    template <typename T> std::ostream &operator<<(std::ostream &ostr, const Vector3<T> &v);
    template <typename T> std::istream &operator>>(std::istream &istr, Vector3<T> &v);

    template <typename T>
    class Vector3
    {
    public:
        Vector3(T x = 0, T y = 0, T z = 0);

        ~Vector3();
        
        Vector3 &normalize();

        Vector3 operator-(Vector3<T> v);

        Vector3 operator*(Vector3<T> v);

        T dot(Vector3<T> v);

        T length();

        void sendAsUniform(ShaderProgram &program, std::string name);
        
        friend std::ostream &operator<< <> (std::ostream &ostr, const Vector3 &v);

        friend std::istream &operator>> <> (std::istream &istr, Vector3 &v);
               
        T x, y, z;
    };
   
    #include "Vector3.inl"
    
} // namespace

#endif // HPP_VECTOR3
