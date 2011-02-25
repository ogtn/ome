////////////////////////////////////////////////////////////////////////
// Resource.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCE
#define HPP_RESOURCE

#include <iostream>

namespace OpenMouleEngine
{
    class Resource
    {
    public:
        Resource(std::string name);

        ~Resource();

    private:
        std::string name;
    };
} // namespace

#endif // HPP_RESOURCE
