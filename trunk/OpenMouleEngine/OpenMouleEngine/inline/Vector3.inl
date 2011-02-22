////////////////////////////////////////////////////////////////////////
// Vector3.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
Vector3<T>::Vector3(T x, T y, T z)
: x(x), y(y), z(z)
{
}


template <typename T>
Vector3<T>::~Vector3()
{
}


template <typename T>
Vector3<T> &Vector3<T>::normalize()
{
    T norm = sqrt(x * x + y * y + z * z);
    
    if(norm != 0)
    {
        x /= norm;
        y /= norm;
        z /= norm;
    }
    
    return *this;
}


template <typename GLfloat>
Vector3<GLfloat> &Vector3<GLfloat>::send(GLint location)
{
    glUniform3f(location, x, y, z);
    
    return *this;
}


template <typename T>
std::ostream &operator<<(std::ostream &ostr, const Vector3<T> &v)
{
    return ostr << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}
