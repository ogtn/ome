////////////////////////////////////////////////////////////////////////
// Matrix4x4.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
Matrix4x4<T>::Matrix4x4()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            data[i][j] = 0;
}


template <typename T>
Matrix4x4<T>::Matrix4x4(T *tab)
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            data[i][j] = tab[i * 4 + j];
}


template <typename T>
Matrix4x4<T>::~Matrix4x4()
{
}


template <typename T>
Matrix4x4<T> &Matrix4x4<T>::makeIdentity()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            data[i][j] = i == j ? 1 : 0;
    
    return *this;
}


template <typename T>
Matrix4x4<T> &Matrix4x4<T>::translate(const Vector3<T> &v)
{
    Matrix4x4<T> m;
    m.makeIdentity();
    
    m.data[0][3] = v.x;
    m.data[1][3] = v.y;
    m.data[2][3] = v.z;
        
    return *this = *this * m;
}


template <typename T>       
Matrix4x4<T> &Matrix4x4<T>::scale(const Vector3<T> &v)
{
    Matrix4x4<T> m;
    m.makeIdentity();
    
    m.data[0][0] = v.x;
    m.data[1][1] = v.y;
    m.data[2][2] = v.z;
    
    return *this = *this * m;
}


template <typename T>       
Matrix4x4<T> &Matrix4x4<T>::rotate(const Vector3<T> &axis, T theta)
{
    Vector3<T> v(axis);
    theta *= M_PI / 180;
    T ct = cos(theta), st = sin(theta);
    Matrix4x4<T> m;
    
    v.normalize();
    m.makeIdentity();
    
    m.data[0][0] = v.x * v.x * (1 - ct) + ct;
    m.data[0][1] = v.x * v.y * (1 - ct) - v.z * st;
    m.data[0][2] = v.x * v.z * (1 - ct) + v.y * st;
    
    m.data[1][0] = v.x * v.y * (1 - ct) + v.z * st;
    m.data[1][1] = v.y * v.y * (1 - ct) + ct;
    m.data[1][2] = v.y * v.z * (1 - ct) + v.x * st;
    
    m.data[2][0] = v.x * v.z * (1 - ct) - v.y * st;
    m.data[2][1] = v.y * v.z * (1 - ct) + v.x * st;
    m.data[2][2] = v.z * v.z * (1 - ct) + ct;
    
    return *this = *this * m;
}


template <typename T>
Matrix4x4<T> &Matrix4x4<T>::transpose()
{
    Matrix4x4<T> copy(*this);
    
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            data[i][j] = copy.data[j][i];
    
    return *this;
}


template <typename T>
const Matrix4x4<T> &Matrix4x4<T>::load(bool transpose) const
{
    if(transpose)
    {
        Matrix4x4<T> copy(*this);
        
        copy.transpose();
        glLoadMatrixf((float*)copy.data);
    }
    else
        glLoadMatrixf((float*)data);

    return *this;
}


template <typename T>
const Matrix4x4<T> Matrix4x4<T>::operator*(const Matrix4x4 &m) const
{
    Matrix4x4<T> res;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            res.data[i][j] = 0;
    
            for(int k = 0; k < 4; k++)
                res.data[i][j] += data[i][k] * m.data[k][j];
        }
    }
        
    return res;
}


template <typename T>
const Vector3<T> Matrix4x4<T>::operator*(const Vector3<T> &v) const
{
    Vector3<T> res;
    
    res.x = data[0][0] * v.x + data[0][1] * v.y + data[0][2] * v.z + data[0][3];
    res.y = data[1][0] * v.x + data[1][1] * v.y + data[1][2] * v.z + data[1][3];
    res.z = data[2][0] * v.x + data[2][1] * v.y + data[2][2] * v.z + data[2][3];
    
    return res; // cette fonction fait de la merde, il manque une dimension au vecteur...
}


template <typename T>
std::ostream &operator<<(std::ostream &ostr, const Matrix4x4<T> &m)
{
    for(int i = 0; i < 16; i++)
        ostr << ((float*)m.data)[i] << " ";
        
        /*
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            ostr << m.data[i][j] << "  ";
        
        ostr << std::endl;
    }
    */
    
    return ostr;
}