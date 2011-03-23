////////////////////////////////////////////////////////////////////////
// ResourceManager.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////


template <typename T>
T *ResourceManager::get(const std::string &name)
{
    T *res; // deux qui la tiennent....

    if(resources.find(name) == resources.end())
    {
        std::string::size_type pos = name.find_last_of('.');
        std::string extension = name.substr(pos + 1);

        if(loaders.find(extension) == loaders.end())
        {
            std::cerr << "Loader introuvable" << std::endl;
            return NULL;
        }

        ResourceLoader<T> *loader = reinterpret_cast<ResourceLoader<T> *>(loaders[extension]);
        res = loader->loadFromFile(name);
        resources[name] = res;
    }
    else
        res = static_cast<T *>(resources[name]);

    return res;
}


template <typename T>
void ResourceManager::add(ResourceLoader<T> *loader, const std::string &extensions)
{
    loaders[extensions] = reinterpret_cast<ResourceLoader<Resource> *>(loader);
}
