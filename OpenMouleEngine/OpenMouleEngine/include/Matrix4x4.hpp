////////////////////////////////////////////////////////////////////////
// Matrix4x4.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MATRIX4X4
#define HPP_MATRIX4X4

#include "Vector3.hpp"
#define GLEW_STATIC
#include <GL/glew.h>

namespace OpenMouleEngine
{
    // forward declaration, to avoid warning about the friend
    template <typename T> class Matrix4x4;
    template <typename T> std::ostream &operator<<(std::ostream &ostr, const Matrix4x4<T> &m);
        
    template <typename T>
    class Matrix4x4
    {
    public:
        Matrix4x4();
        
        Matrix4x4(T *tab);

        ~Matrix4x4();
        
        Matrix4x4<T> &makeIdentity();
        
        Matrix4x4<T> &translate(const Vector3<T> &v);
        
        Matrix4x4<T> &scale(const Vector3<T> &v);
        
        Matrix4x4<T> &rotate(const Vector3<T> &axis, T theta);
        
        Matrix4x4<T> &transpose();
        
        const Matrix4x4<T> &load(bool transpose = true) const;
        
        const Matrix4x4 operator*(const Matrix4x4 &m) const;
        
        const Vector3<T> operator*(const Vector3<T> &v) const;
        
        friend std::ostream &operator<< <> (std::ostream &ostr, const Matrix4x4<T> &m);
    
    private:
        T data[4][4];
    };
    
    #include "Matrix4x4.inl"
    
} // namespace

#endif // HPP_MATRIX4X4
