////////////////////////////////////////////////////////////////////////
// FileName.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "FileName.hpp"

namespace OpenMouleEngine
{
    FileName::FileName(const std:: string &name):
    name(name)
    {
    }


    FileName::~FileName()
    {
    }


    const std::string FileName::baseName() const
    {
        std::string::size_type pos = name.find_last_of("/\\") + 1;

        return name.substr(pos);
    }


    const std::string FileName::path() const
    {
        int pos = name.find_last_of("/\\") + 1;

        return name.substr(0, pos);
    }


    const std::string FileName::extension() const
    {
        int pos = name.find_last_of(".") + 1;

        return name.substr(pos);
    }
} // namespace
