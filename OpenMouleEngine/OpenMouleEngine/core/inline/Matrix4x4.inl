////////////////////////////////////////////////////////////////////////
// Matrix4x4.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
Matrix4x4<T>::Matrix4x4()
{
    makeIdentity();
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
            data[i][j] = i == j ? T(1) : T(0);
    
    return *this;
}


template <typename T>
Matrix4x4<T> &Matrix4x4<T>::makeOrtho(T left, T right, T bottom, T top, T zNear, T zFar)
{
    makeIdentity();

    data[0][0] = 2 / (right - left);
    data[0][3] = -(right + left) / (right - left);

    data[1][1] = 2 / (top - bottom);
    data[1][3] = -(top + bottom) / (top - bottom);

    data[2][2] = 2 / (zFar - zNear);
    data[2][3] = -(zFar + zNear) / (zFar - zNear);

    return *this;
}


template <typename T>
Matrix4x4<T> &Matrix4x4<T>::makePerspective(T angle, T ratio, T near, T far)
{
    makeIdentity();

    angle *= M_PI / 180;
    T f = 1 / tan(angle / 2);

    data[0][0] = f / ratio;
    data[1][1] = f;
    data[2][2] = (near + far) / (near - far);
    data[3][3] = 0;
    data[2][3] = (2 * near * far) / (near - far);
    data[3][2] = -1;

    return *this;
}


template <typename T>
Matrix4x4<T> &Matrix4x4<T>::lookAt(Vector3<T> pos, Vector3<T> target, Vector3<T> up)
{
    makeIdentity();

    Vector3<T> forward = target - pos;
    forward.normalize();
    Vector3<T> side = forward * up.normalize();
    Vector3<T> newUP = side.normalize() * forward;

    data[0][0] = side.x;
    data[0][1] = side.y;
    data[0][2] = side.z;

    data[1][0] = newUP.x;
    data[1][1] = newUP.y;
    data[1][2] = newUP.z;

    data[2][0] = -forward.x;
    data[2][1] = -forward.y;
    data[2][2] = -forward.z;
    data[2][3] = forward.dot(pos);  // wtf?

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
    theta = degToRad(theta);
    T ct = cos(theta), st = sin(theta);
    Matrix4x4<T> m;
    
    v.normalize();
    m.makeIdentity();
    
    m.data[0][0] = v.x * v.x * (1 - ct) + ct;
    m.data[0][1] = v.x * v.y * (1 - ct) - v.z * st;
    m.data[0][2] = v.x * v.z * (1 - ct) + v.y * st;
    
    m.data[1][0] = v.x * v.y * (1 - ct) + v.z * st;
    m.data[1][1] = v.y * v.y * (1 - ct) + ct;
    m.data[1][2] = v.y * v.z * (1 - ct) - v.x * st;
    
    m.data[2][0] = v.x * v.z * (1 - ct) - v.y * st;
    m.data[2][1] = v.y * v.z * (1 - ct) + v.x * st;
    m.data[2][2] = v.z * v.z * (1 - ct) + ct;
    
    return *this = *this * m;
}


template <typename T>       
Matrix4x4<T> &Matrix4x4<T>::rotate(const Vector3<T> &angle)
{
    // awful, but temporary...
    Matrix4x4<T> mx(*this);
    Matrix4x4<T> my(*this);
    Matrix4x4<T> mz(*this);

    mx.rotate(Vector3<T>(1, 0, 0), angle.x);
    my.rotate(Vector3<T>(0, 1, 0), angle.y);
    mz.rotate(Vector3<T>(0, 0, 1), angle.z);

    return *this = *this * mx * my * mz;
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


template <typename GLfloat>
const Matrix4x4<GLfloat> &Matrix4x4<GLfloat>::load(bool transpose) const
{
    if(transpose)
    {
        Matrix4x4<GLfloat> copy(*this);
        
        copy.transpose();
        glLoadMatrixf((GLfloat *)copy.data);
    }
    else
        glLoadMatrixf((GLfloat *)data);

    return *this;
}


template <typename T>
void Matrix4x4<T>::sendAsUniform(ShaderProgram &program, const std::string &name) const
{
    glUniformMatrix4fv(program.getUniformLocation(name), 1, GL_TRUE, tab);
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
Matrix4x4<T> operator*(const Matrix4x4<T> &m1, const Matrix4x4<T> &m2)
{
    Matrix4x4<T> res;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            res.data[i][j] = 0;
    
            for(int k = 0; k < 4; k++)
                res.data[i][j] += m1.data[i][k] * m2.data[k][j];
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
    
    return NULL; // cette fonction fait de la merde, il manque une dimension au vecteur...
}


template <typename T>
std::ostream &operator<<(std::ostream &ostr, const Matrix4x4<T> &m)
{
    for(int i = 0; i < 16; i++)
    {
        if(i && i % 4 == 0)
            std::printf("\n");
        std::printf("%+2.3f\t", ((float *)m.data)[i]);
    }

    return ostr;
}
