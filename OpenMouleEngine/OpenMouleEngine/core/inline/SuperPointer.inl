////////////////////////////////////////////////////////////////////////
// SuperPointer.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
SuperPointer<T>::SuperPointer()
    : SuperPointerBase()
{
}


template <typename T>
SuperPointer<T>::SuperPointer(T *p)
    : SuperPointerBase(p)
{
}


template <typename T>
SuperPointer<T>::SuperPointer(const SuperPointer<T> &sp)
    : SuperPointerBase(sp)
{
}


template <typename T>
template <typename U>
SuperPointer<T>::SuperPointer(const SuperPointer<U> &sp)
    : SuperPointerBase(sp)
{
    static_cast<T*>(sp.getPtr());
}


template <typename T>
SuperPointer<T>::~SuperPointer()
{
    reset();
}


template <typename T>
bool SuperPointer<T>::operator ==(const SuperPointer<T> &sp)
{
    return ptr == sp.ptr;
}


template <typename T>
bool SuperPointer<T>::operator !=(const SuperPointer<T> &sp)
{
    return !(*this == sp);
}


template <typename T>
template <typename U>
bool SuperPointer<T>::operator ==(const SuperPointer<U> &sp)
{
    return ptr == static_cast<T*>(sp.getPtr());
}


template <typename T>
template <typename U>
bool SuperPointer<T>::operator !=(const SuperPointer<U> &sp)
{
    return !(*this == sp);
}


template <typename T>
SuperPointer<T> &SuperPointer<T>::operator =(T *p)
{
    reset();
    SuperPointerBase::operator =(p);

    return *this;
}


template <typename T>
SuperPointer<T> &SuperPointer<T>::operator =(const SuperPointer<T> &sp)
{
    if(*this != sp)
    {
        reset();
        SuperPointerBase::operator =(sp);
    }

    return *this;
}


template <typename T>
template <typename U>
SuperPointer<T> &SuperPointer<T>::operator =(U *p)
{

    if(dynamic_cast<T*>(p))
    {
        static_cast<T*>(p);
        reset();
        SuperPointerBase::operator =(p);
    }
    else
    {
        std::cerr << "kernel panic!!!" << endl;
    }

    return *this;
}


template <typename T>
template <typename U>
SuperPointer<T> &SuperPointer<T>::operator =(SuperPointer<U> &sp)
{
    // on empeche l'auto affectation
    if(*this != sp)
    {
        if(dynamic_cast<T*>(sp.getPtr()))
        {
            static_cast<T*>(sp.getPtr());
            reset();
            SuperPointerBase::operator =(sp);
        }
        else
        {
            //std::cerr << "kernel panic!!!" << endl;
        }
    }

    return *this;
}


template <typename T>
T *SuperPointer<T>::operator ->()
{
    if(isValid())
        return reinterpret_cast<T*>(ptr);
    else
    {
        std::exception e;
        throw e;
    }
}


template <typename T>
T *SuperPointer<T>::getPtr() const
{
    return static_cast<T *>(ptr);
}


template <typename T>
void SuperPointer<T>::reset()
{
    if(refCount != NULL)
    {
        --(*refCount);

        if(*refCount == 0)
        {
            delete reinterpret_cast<T*>(ptr);
            delete refCount;
        }
    }
}
