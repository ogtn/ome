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
        material(material)
    {
    }


    Mesh::~Mesh()
    {
    }


    void Mesh::sendUniforms() const
    {
        vec3 pos = getPosition();

        shader->sendUniform("mdlPosition", pos);
        shader->sendUniform("camera", *Engine::getInstance()->getCamera());
        shader->sendUniform("mat", *material);

        DirectionalLight light(vec3(1, 1, 1));
        shader->sendUniform("light", light);
    }


    void Mesh::render() const
    {
        shader->bind();
        sendUniforms();
        geometry->render(*shader);
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
} // namespace
