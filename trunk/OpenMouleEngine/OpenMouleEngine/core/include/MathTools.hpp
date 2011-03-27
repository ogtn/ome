////////////////////////////////////////////////////////////////////////
// MathTools.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MATHTOOLS
#define HPP_MATHTOOLS

#include <cmath>

namespace OpenMouleEngine
{
    const double pi = 3.141592653589793238462643;

    template <typename T>
    T degToRad(T angle);

    template <typename T>
    T radToDeg(T angle);

#include "MathTools.inl"

} // namespace

#endif // HPP_MATHTOOLS
