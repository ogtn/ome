////////////////////////////////////////////////////////////////////////
// ShaderLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SHADERLOADER
#define HPP_SHADERLOADER

#include "ResourceLoader.hpp"
#include "Shader.hpp"

namespace OpenMouleEngine
{
    class VertexShaderLoader: public ResourceLoader<Shader>
    {
    public:
        VertexShaderLoader();
        ~VertexShaderLoader();

        Shader *loadFromFile(std::string fileName);
    };


    class FragmentShaderLoader: public ResourceLoader<Shader>
    {
    public:
        FragmentShaderLoader();
        ~FragmentShaderLoader();

        Shader *loadFromFile(std::string fileName);
    };

    std::string getShaderCode(std::string &fileName);

} // namespace

#endif // HPP_SHADERLOADER
