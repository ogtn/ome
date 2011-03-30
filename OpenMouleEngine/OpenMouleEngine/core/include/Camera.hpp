////////////////////////////////////////////////////////////////////////
// Camera.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_CAMERA
#define HPP_CAMERA

#include "Matrix4x4.hpp"

namespace OpenMouleEngine
{
    // forward declaration
    class ShaderProgram;

    class Camera
    {
    public:
        Camera();
        virtual ~Camera();

        virtual void updateMatrices() = 0;
        const mat4 &getModelView();
        const mat4 &getProjection();

    protected:
        mat4 projection;
        mat4 modelview;
        bool ready;
    };


    class CameraOrtho: public Camera
    {
    public:
        CameraOrtho(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);

        void updateMatrices();

    private:
        GLfloat left;
        GLfloat right;
        GLfloat bottom;
        GLfloat top;
        GLfloat near;
        GLfloat far;  
    };


    class CameraPerspective: public Camera
    {
    public:
        CameraPerspective(GLfloat fov, GLfloat ratio, GLfloat near, GLfloat far, vec3 pos = vec3(1, 1, 1), vec3 target = vec3(), vec3 up = vec3(0, 0, 1));

        void perspective(GLfloat fov, GLfloat ratio, GLfloat near, GLfloat far);
        void lookAt(vec3 pos, vec3 target = vec3(), vec3 up = vec3(0, 0, 1));
        void updateMatrices();
    
    private:
        vec3 pos;
        vec3 target;
        vec3 up;
        GLfloat fov;
        GLfloat ratio;
        GLfloat near;
        GLfloat far;
    };
} // namespace

#endif // HPP_CAMERA
