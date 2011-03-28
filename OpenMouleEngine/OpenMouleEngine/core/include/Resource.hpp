////////////////////////////////////////////////////////////////////////
// Resource.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_RESOURCE
#define HPP_RESOURCE

#include "FileName.hpp"

namespace OpenMouleEngine
{
    class Resource
    {
    public:
        Resource(const std::string &name);
        virtual ~Resource();

        void saveAs(const std::string &name);

    public:
        FileName name;
    };
} // namespace

#endif // HPP_RESOURCE
