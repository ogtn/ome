////////////////////////////////////////////////////////////////////////
// MathTools.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
T degToRad(T angle)
{
    return angle * T(pi) / 180;
}

template <typename T>
T radToDeg(T angle)
{
    return angle / T(pi) * 180;
}
