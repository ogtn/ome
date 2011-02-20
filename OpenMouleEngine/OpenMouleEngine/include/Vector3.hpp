////////////////////////////////////////////////////////////////////////
// Vector3.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#ifndef HPP_VECTOR3
#define HPP_VECTOR3

#include <cmath>
#ifndef M_PI
#define M_PI 3.141592653589793238462643
#endif
#include <iostream>

namespace OpenMouleEngine
{
    // forward declaration, to avoid warning about the friend
    template <typename T> class Vector3;
    template <typename T> std::ostream &operator<<(std::ostream &ostr, const Vector3<T> &v);

    template <typename T>
    class Vector3
    {
    public:
        Vector3(T x = 0, T y = 0, T z = 0);

        ~Vector3();
        
        Vector3 &normalize();
        
        friend std::ostream &operator<< <> (std::ostream &ostr, const Vector3 &v);
                
        T x, y, z;
    };
    
    #include "Vector3.inl"
    
} // namespace

#endif // HPP_VECTOR3
