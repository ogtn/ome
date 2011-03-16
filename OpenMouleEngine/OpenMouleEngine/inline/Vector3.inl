////////////////////////////////////////////////////////////////////////
// Vector3.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
Vector3<T>::Vector3(T x, T y, T z):
    x(x),
    y(y),
    z(z)
{
}


template <typename T>
Vector3<T>::~Vector3()
{
}


template <typename T>
Vector3<T> &Vector3<T>::normalize()
{
    T norm = length();
    
    if(norm != 0)
    {
        x /= norm;
        y /= norm;
        z /= norm;
    }
    
    return *this;
}


template <typename T>
T Vector3<T>::length()
{
    return sqrt(x * x + y * y + z * z);
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


template <typename T>
T Vector3<T>::dot(Vector3<T> v)
{
    return x * v.x + y * v.y + z * v.z;
}


template <typename T>
std::ostream &operator<<(std::ostream &ostr, const Vector3<T> &v)
{
    return ostr << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}


template <typename T>
std::istream &operator>>(std::istream &istr, Vector3<T> &v)
{
    istr >> v.x >> v.y >> v.z;

    return istr;
}






/*
template <typename GLfloat>
void Vector3<GLfloat>::send(GLint location)
{
    glUniform3f(location, x, y, z);
}
*/