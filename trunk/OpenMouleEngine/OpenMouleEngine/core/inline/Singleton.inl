////////////////////////////////////////////////////////////////////////
// Singleton.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
Singleton<T>::Singleton()
{
}


template <typename T>
Singleton<T>::~Singleton()
{
}


template <typename T>
T *Singleton<T>::getInstance()
{
    if(instance == NULL)
        instance = new T();

    return instance;
}
        

template <typename T>
void Singleton<T>::kill()
{
    if(instance != NULL)
    {
        delete instance;
        instance = NULL;
    }
}


template <typename T>
T *Singleton<T>::instance = NULL;
