////////////////////////////////////////////////////////////////////////
// ResourceLoader.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
ResourceLoader<T>::ResourceLoader()
{
}


template <typename T>
ResourceLoader<T>::~ResourceLoader()
{
}


template <typename T>
T *ResourceLoader<T>::loadFromFile(std::string fileName)
{
    std::cout << "loadFromFile() not implemented for " + fileName << std::endl;
    return NULL;
}


template <typename T>
T *ResourceLoader<T>::loadFromRAM(void *ptr)
{
    std::cout << "loadFromRAM() not implemented for " << ptr << std::endl;
    return NULL;
}
