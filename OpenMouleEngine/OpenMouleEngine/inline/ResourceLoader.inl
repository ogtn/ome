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
void ResourceLoader<T>::loadFromFile(std::string fileName)
{
    std::cerr << "loadFromFile() not implemented" << std::end;
}


template <typename T>
void ResourceLoader<T>::loadFromRAM(void *ptr)
{
    std::cerr << "loadFromRAM() not implemented" << std::end;
}
