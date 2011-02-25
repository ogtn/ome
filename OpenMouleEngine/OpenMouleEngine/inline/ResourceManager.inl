////////////////////////////////////////////////////////////////////////
// ResourceManager.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////


template <typename T>
T *ResourceManager::get(std::string name)
{
    T *res;

    if(resources.find(name) == resources.end())
    {
        res = new T(name); // rechercher et utiliser le loader approprié
        resources[name] = res;
    }
    else
        res = static_cast<T *>(resources[name]);

    return res;
}
