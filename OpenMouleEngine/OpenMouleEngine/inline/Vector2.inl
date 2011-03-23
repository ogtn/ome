////////////////////////////////////////////////////////////////////////
// Vector2.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
Vector2<T>::Vector2(T x, T y)
    : x(x),
    y(y)
{
}


template <typename T>
Vector2<T>::~Vector2()
{
}


template <typename T>
std::ostream &operator<<(std::ostream &ostr, const Vector2<T> &v)
{
    return ostr << "(" << v.x << ", " << v.y << ")";
}


template <typename T>
std::istream &operator>>(std::istream &istr, Vector2<T> &v)
{
    return istr >> v.x >> v.y;
}

template <typename T>
void Vector2<T>::sendAsUniform(ShaderProgram &program, const std::string &name)
{
    glUniform2fv(program.getUniformLocation(name), 1, tab);
}
