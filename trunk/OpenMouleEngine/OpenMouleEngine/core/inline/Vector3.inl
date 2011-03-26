////////////////////////////////////////////////////////////////////////
// Vector3.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
Vector3<T>::Vector3(T x, T y, T z)
    : x(x),
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
Vector3<T> Vector3<T>::operator+(Vector3<T> v)
{
    return Vector3<T>(x + v.x, y + v.y, z + v.z);
}



template <typename T>
Vector3<T> Vector3<T>::operator-(Vector3<T> v)
{
    return Vector3<T>(x - v.x, y - v.y, z - v.z);
}


template <typename T>
Vector3<T> operator*(Vector3<T> v, T t)
{
    return Vector3<T>(t * v.x, t * v.y, t * v.z);
}


template <typename T>
Vector3<T> operator*(T t, Vector3<T> v)
{
    return v * t;
}


template <typename T>
Vector3<T> Vector3<T>::operator/(T t)
{
    return Vector3<T>(x / t, y / t, z / t);
}


template <typename T>
std::ostream &operator<<(std::ostream &ostr, const Vector3<T> &v)
{
    return ostr << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}


template <typename T>
std::istream &operator>>(std::istream &istr, Vector3<T> &v)
{
    return istr >> v.x >> v.y >> v.z;
}

template <typename T>
void Vector3<T>::sendAsUniform(ShaderProgram &program, const std::string &name)
{
    glUniform3fv(program.getUniformLocation(name), 1, tab);
}


template <typename T> 
Vector3<T> operator*(Vector3<T> v1, Vector3<T> v2)
{
    return Vector3<T>(
        v1.x * v2.x,
        v1.y * v2.y,
        v1.z * v2.z);
}


template <typename T> 
Vector3<T> cross(Vector3<T> v1, Vector3<T> v2)
{
    return Vector3<T>(
        (v1.y * v2.z - v1.z * v2.y),
        (v1.z * v2.x - v1.x * v2.z),
        (v1.x * v2.y - v1.y * v2.x));
}


template <typename T> 
T dot(Vector3<T> v1, Vector3<T> v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
