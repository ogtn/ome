////////////////////////////////////////////////////////////////////////
// Matrix4x4.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MATRIX4X4
#define HPP_MATRIX4X4

#include "Vector3.hpp"
#include "Uniform.hpp"

namespace OpenMouleEngine
{
    // forward declaration, to avoid warning about the friend
    template <typename T> class Matrix4x4;
    typedef Matrix4x4<GLfloat> mat4;
    template <typename T> std::ostream &operator<<(std::ostream &ostr, const Matrix4x4<T> &m);
        
    template <typename T>
    class Matrix4x4: public Uniform
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
        
        Matrix4x4 &transpose();
        
        const Matrix4x4 &load(bool transpose = true) const;

        void send(GLint location);
        
        const Matrix4x4 operator*(const Matrix4x4 &m) const;
        
        const Vector3<T> operator*(const Vector3<T> &v) const;
        
        friend std::ostream &operator<< <> (std::ostream &ostr, const Matrix4x4<T> &m);
    
    private:
        T data[4][4];
    };
    
    #include "Matrix4x4.inl"
    
} // namespace

#endif // HPP_MATRIX4X4
