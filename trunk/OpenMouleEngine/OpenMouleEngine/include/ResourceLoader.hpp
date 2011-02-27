////////////////////////////////////////////////////////////////////////
// ResourceLoader.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCELOADER
#define HPP_RESOURCELOADER

#include <iostream>
#include <string>

namespace OpenMouleEngine
{
    template <typename T>
    class ResourceLoader
    {
    public:
        ResourceLoader();

        virtual ~ResourceLoader() = 0;

        virtual T *loadFromFile(std::string fileName);

        virtual T *loadFromRAM(void *ptr);
    };

    #include "ResourceLoader.inl"

    // just for a temporary test
    class DummyVShaderLoader: public ResourceLoader<Shader>
    {
        Shader *loadFromFile(std::string fileName)
        {
            std::string vertCode("\
                             #version 140\n\
                             in vec2 a_Vertex;\n\
                             uniform mat4 projection;\n\
                             uniform mat4 modelview;\n\
                             void main()\n\
                             {\n\
                             vec4 pos = modelview * vec4(a_Vertex, 0, 1.0);\n\
                             gl_Position = projection * pos;\n\
                             //gl_Position = vec4(a_Vertex, 0, 1) * modelview;\n\
                             }\n\
                             ");

            return new Shader(fileName, GL_VERTEX_SHADER, vertCode);
        }
    };

    // just for a temporary test
    class DummyFShaderLoader: public ResourceLoader<Shader>
    {
        Shader *loadFromFile(std::string fileName)
        {
            std::string fragCode("\
                             #version 140\n\
                             out vec4 outColor;\n\
                             void main()\n\
                             {\n\
                             outColor = vec4(0.3, 0.1, 0.7, 1);\n\
                             }\n\
                             ");

            return new Shader(fileName, GL_FRAGMENT_SHADER, fragCode);
        }
    };

} // namespace


#endif // HPP_RESOURCELOADER
