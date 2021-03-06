////////////////////////////////////////////////////////////////////////
// Matrix4x4.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MATRIX4X4
#define HPP_MATRIX4X4

#include "Vector3.hpp"
#include <cstdio>

namespace OpenMouleEngine
{
    template <typename T>
    class Matrix4x4
    {
    public:
        Matrix4x4();
        Matrix4x4(T *tab);
        ~Matrix4x4();
        
        Matrix4x4 &makeIdentity();
        Matrix4x4 &makeOrtho(T left, T right, T bottom, T top, T zNear, T zFar);
        Matrix4x4 &makePerspective(T angle, T ratio, T near, T far);
        Matrix4x4 &lookAt(Vector3<T> pos, Vector3<T> target = Vector3<T>(), Vector3<T> up = Vector3<T>(0, 0, 1));
        Matrix4x4 &translate(const Vector3<T> &v); 
        Matrix4x4 &scale(const Vector3<T> &v);
        Matrix4x4 &rotate(const Vector3<T> &axis, T theta);
        Matrix4x4 &rotate(const Vector3<T> &angle);
        Matrix4x4 &transpose();
        const Matrix4x4 &load(bool transpose = true) const;
        const Matrix4x4 operator*(const Matrix4x4 &m) const;
        const Vector3<T> operator*(const Vector3<T> &v) const;
        void sendAsUniform(ShaderProgram &program, const std::string &name) const;
    
        union
        {
            T data[4][4];
            T tab[16];
        };
    };

    template <typename T> Matrix4x4<T> operator*(const Matrix4x4<T> &m1, const Matrix4x4<T> &m2);
    template <typename T> std::ostream &operator<<(std::ostream &ostr, const Matrix4x4<T> &m);

    typedef Matrix4x4<GLfloat> mat4;
    
    #include "Matrix4x4.inl"
    
} // namespace

#endif // HPP_MATRIX4X4
