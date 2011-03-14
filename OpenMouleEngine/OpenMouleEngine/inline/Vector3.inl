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


template <typename T>
Vector3<T> Vector3<T>::operator-(Vector3<T> v)
{
    return Vector3<T>(x - v.x, y - v.y, z - v.z);
}


template <typename T>
Vector3<T> Vector3<T>::operator*(Vector3<T> v)
{
    return Vector3<T>(
        (y * v.z - z * v.y),
        (z * v.x - x * v.z),
        (x * v.y - y * v.x));
}


template <typename GLfloat>
void Vector3<GLfloat>::send(GLint location)
{
    glUniform3f(location, x, y, z);
}


template <typename T>
std::ostream &operator<<(std::ostream &ostr, const Vector3<T> &v)
{
    return ostr << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}
