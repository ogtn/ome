////////////////////////////////////////////////////////////////////////
// Camera.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Camera.hpp"
#include "ShaderProgram.hpp"

namespace OpenMouleEngine
{
    Camera::Camera()
        : ready(false)
    {
    }


    Camera::~Camera()
    {
    }


    CameraOrtho::CameraOrtho(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
        : Camera(),
        left(left),
        right(right),
        bottom(bottom),
        top(top),
        near(near),
        far(far)
    {
    }


    void CameraOrtho::updateMatrices()
    {
        projection.makeIdentity();

        projection.data[0][0] = 2 / (right - left);
        projection.data[0][3] = -(right + left) / (right - left);

        projection.data[1][1] = 2 / (top - bottom);
        projection.data[1][3] = -(top + bottom) / (top - bottom);

        projection.data[2][2] = 2 / (far - near);
        projection.data[2][3] = -(far + near) / (far - near);
    }


    void Camera::sendAsUniform(ShaderProgram &program, std::string name)
    {
        if(!ready)
        {
            ready = true;
            updateMatrices();
        }

        glUniformMatrix4fv(program.getUniformLocation("projection"), 1, GL_TRUE, (GLfloat *)projection.data);
        glUniformMatrix4fv(program.getUniformLocation("modelview"), 1, GL_TRUE, (GLfloat *)modelview.data);
    }


    CameraPerspective::CameraPerspective(GLfloat fov, GLfloat ratio, GLfloat near, GLfloat far, vec3 pos, vec3 target, vec3 up)
        : Camera(),
        fov(fov),
        ratio(ratio),
        near(near),
        far(far),
        pos(pos),
        target(target),
        up(up)
    {
    }


    void CameraPerspective::lookAt(vec3 npos, vec3 ntarget, vec3 nup)
    {
        ready = false;

        pos = npos;
        target = ntarget;
        up = nup;
    }


    void CameraPerspective::perspective(GLfloat nfov, GLfloat nratio, GLfloat nnear, GLfloat nfar)
    {
        ready = false;

        fov = nfov * 0.0174532925f; // deg to rad
        ratio = nratio;
        near = nnear;
        far = nfar;
    }


    void CameraPerspective::updateMatrices()
    {
        // projection
        projection.makeIdentity();

        GLfloat f = 1 / tan(ratio / 2);

        projection.data[0][0] = f / ratio;
        projection.data[1][1] = f;
        projection.data[2][2] = (near + far) / (near - far);
        projection.data[2][3] = (2 * near * far) / (near - far);
        projection.data[3][2] = -1;
        projection.data[3][3] = 0;


        // modelview
        modelview.makeIdentity();

        vec3 forward(target - pos);
        forward.normalize();
        vec3 side = forward * up.normalize();
        vec3 newUP = side.normalize() * forward;

        modelview.data[0][0] = side.x;
        modelview.data[0][1] = side.y;
        modelview.data[0][2] = side.z;

        modelview.data[1][0] = newUP.x;
        modelview.data[1][1] = newUP.y;
        modelview.data[1][2] = newUP.z;

        modelview.data[2][0] = -forward.x;
        modelview.data[2][1] = -forward.y;
        modelview.data[2][2] = -forward.z;
        modelview.data[2][3] = forward.dot(pos);  // wtf? nothing about that in the OpenGL manpages...
    }
} // namespace
