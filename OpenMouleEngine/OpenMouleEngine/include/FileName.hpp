////////////////////////////////////////////////////////////////////////
// FileName.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_FILENAME
#define HPP_FILENAME

#include <string>

namespace OpenMouleEngine
{
    class FileName
    {
    public:
        FileName(const std::string &name);

        ~FileName();

        std::string baseName() const;

        std::string path() const;

        std::string extension() const;

    private:
        std::string name;
    };
} // namespace

#endif // HPP_FILENAME
