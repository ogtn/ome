////////////////////////////////////////////////////////////////////////
// ShaderLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SHADERLOADER
#define HPP_SHADERLOADER

#include "ResourceLoader.hpp"

namespace OpenMouleEngine
{
    // forward declaration
    class Shader;

    class VertexShaderLoader: public ResourceLoader<Shader>
    {
    public:
        VertexShaderLoader();
        ~VertexShaderLoader();

        Shader *loadFromFile(const std::string &fileName);
    };


    class FragmentShaderLoader: public ResourceLoader<Shader>
    {
    public:
        FragmentShaderLoader();
        ~FragmentShaderLoader();

        Shader *loadFromFile(const std::string &fileName);
    };

    std::string getShaderCode(const std::string &fileName);

} // namespace

#endif // HPP_SHADERLOADER
