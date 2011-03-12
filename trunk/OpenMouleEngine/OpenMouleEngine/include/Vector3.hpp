////////////////////////////////////////////////////////////////////////
// Vector3.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_VECTOR3
#define HPP_VECTOR3

#include "Uniform.hpp"
#include <cmath>
#ifndef M_PI
#define M_PI 3.141592653589793238462643
#endif
#include <iostream>

namespace OpenMouleEngine
{
    // forward declaration, to avoid warning about the friend
    template <typename T> class Vector3;
    typedef Vector3<GLfloat> vec3;
    template <typename T> std::ostream &operator<<(std::ostream &ostr, const Vector3<T> &v);

    template <typename T>
    class Vector3: public Uniform
    {
    public:
        Vector3(T x = 0, T y = 0, T z = 0);

        ~Vector3();
        
        Vector3 &normalize();

        void send(GLint location);
        
        friend std::ostream &operator<< <> (std::ostream &ostr, const Vector3 &v);
                
        T x, y, z;
    };
    
    #include "Vector3.inl"
    
} // namespace

#endif // HPP_VECTOR3
