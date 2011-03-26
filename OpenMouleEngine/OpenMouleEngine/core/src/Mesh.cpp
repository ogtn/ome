////////////////////////////////////////////////////////////////////////
// Mesh.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include "Engine.hpp"

namespace OpenMouleEngine
{
    Mesh::Mesh(const MeshData *geometry, ShaderProgram *shader, Material *material)
        : geometry(geometry),
        shader(shader),
        material(material),
        mode(GL_TRIANGLES)
    {
    }


    Mesh::~Mesh()
    {
    }


    void Mesh::sendUniforms() const
    {
        Camera *camera = Engine::getInstance()->getCamera();

        mat4 matrixPos;
        matrixPos.translate(getPosition());

        mat4 matrixRot;
        matrixRot.rotate(getRotation());

        mat4 matrixScal;
        matrixScal.scale(getScaling());

        mat4 mdlvw = camera->getModelView() * matrixPos * matrixScal * matrixRot;        
        shader->sendUniform("modelview", mdlvw);
        shader->sendUniform("projection", camera->getProjection());

        if(material != NULL)
        {
            shader->sendUniform("mat", *material);
            DirectionalLight light(vec3(1, 1, 1));
            shader->sendUniform("light", light);
        }
    }


    void Mesh::render() const
    {
        shader->bind();
        sendUniforms();
        geometry->render(*shader, mode);
        shader->unbind();
    }


    void Mesh::setShader(ShaderProgram *s)
    {
        shader = s;
    }


    void Mesh::setMaterial(Material *mat)
    {
        material = mat;
    }


    void Mesh::setRenderMode(GLenum m)
    {
        mode = m;
    }
} // namespace
