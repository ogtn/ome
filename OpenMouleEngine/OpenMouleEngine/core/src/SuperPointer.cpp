////////////////////////////////////////////////////////////////////////
// SuperPointer.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "SuperPointer.hpp"
#include <cstdio>

namespace OpenMouleEngine
{
    SuperPointerBase::SuperPointerBase()
        : ptr(NULL),
        refCount(NULL)
    {
    }


    SuperPointerBase::SuperPointerBase(void *p)
        : ptr(p)
    {
        refCount = new int;
        *refCount = 1;
    }


    SuperPointerBase::SuperPointerBase(const SuperPointerBase &sp)
        : ptr(sp.ptr),
        refCount(sp.refCount)
    {
        if(refCount != NULL)
            ++(*refCount);
    }


    SuperPointerBase &SuperPointerBase::operator =(const SuperPointerBase &sp)
    {
        refCount = sp.refCount;
        ptr = sp.ptr;

        ++(*refCount);

        return *this;
    }


    SuperPointerBase &SuperPointerBase::operator =(void *p)
    {
        refCount = new int;
        *refCount = 1;

        ptr = p;

        return *this;
    }


    bool SuperPointerBase::isValid()
    {
        return ptr != NULL;
    }
} // namespace
