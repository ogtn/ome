////////////////////////////////////////////////////////////////////////
// ResourceSaver.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
ResourceSaver<T>::ResourceSaver()
{
}


template <typename T>
ResourceSaver<T>::~ResourceSaver()
{
}


template <typename T>
void ResourceSaver<T>::saveAs(std::string fileName, T &resource)
{
    std::cerr << "saveToFile() not implemented for " + fileName << std::endl;
}
