////////////////////////////////////////////////////////////////////////
// Singleton.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SINGLETON
#define HPP_SINGLETON

#include <cstdlib>

namespace OpenMouleEngine
{
    template <typename T>
    class Singleton
    {
    protected:
        Singleton();

        ~Singleton();

    public:
        static T *getInstance();
        
        static void kill();

    private:
        static T *instance;
    };

    #include "Singleton.inl"

} // namespace

#endif // HPP_SINGLETON
