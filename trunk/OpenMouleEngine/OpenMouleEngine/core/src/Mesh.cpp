////////////////////////////////////////////////////////////////////////
// Mesh.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include "Light.hpp"
#include "Engine.hpp"
#include "Camera.hpp"
#include "Material.hpp"
#include "MeshData.hpp"

namespace OpenMouleEngine
{
    Mesh::Mesh(const std::string &name, MeshData *geometry, ShaderProgram *shader, Material *material)
        : SceneNode(name),
        geometry(geometry),
        shader(shader),
        material(material),
        mode(GL_TRIANGLES),
        pointSize(640.f)
    {
    }


    Mesh::~Mesh()
    {
    }


    void Mesh::sendUniforms() const
    {
        // apply mesh transformation to the modelview
        Camera *camera = Engine::getInstance()->getCamera();

        mat4 matrixPos;
        matrixPos.translate(getPosition());

        mat4 matrixRot;
        matrixRot.rotate(getRotation());

        mat4 matrixScal;
        matrixScal.scale(getScaling());

        mat4 mdlvw = camera->getModelView() * matrixPos * matrixScal * matrixRot;

        // sending modelview and projection matrices to the shader
        shader->sendUniform("modelview", mdlvw);
        shader->sendUniform("projection", camera->getProjection());

        // send material if available
        if(material != NULL)
            shader->sendUniform("mat", *material);

        // if using pointsprites, send the size to the shader
        if(mode == GL_POINTS)
            glUniform1f(shader->getUniformLocation("pointSize"), pointSize);

        // temporary
        if(material != NULL && material->name.name == "smbCube")
        {
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


    void Mesh::setPointSize(float size)
    {
        pointSize = size;
    }


    const MeshData *Mesh::data() const
    {
        return geometry;
    }
} // namespace
