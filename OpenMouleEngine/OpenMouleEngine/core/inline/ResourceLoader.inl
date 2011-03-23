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
T *ResourceLoader<T>::loadFromFile(const std::string &fileName)
{
    std::cerr << "loadFromFile() not implemented for " + fileName << std::endl;
    return NULL;
}


template <typename T>
T *ResourceLoader<T>::loadFromRAM(void *ptr)
{
    std::cerr << "loadFromRAM() not implemented for " << ptr << std::endl;
    return NULL;
}
