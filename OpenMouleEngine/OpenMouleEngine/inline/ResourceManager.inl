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

/*
template <typename T>
void ResourceManager::add(ResourceSaver<T> *saver, const std::string &extensions)
{
    // no need of templates here, polymorphism should be fine 
    savers[extensions] = reinterpret_cast<ResourceSaver<Resource> *>(savers);
}
*/

void ResourceManager::add(ResourceSaver *saver, const std::string &extensions)
{
    savers[extensions] = saver;
}

/*
template <typename T>
void ResourceManager::saveAs(T &resource, std::string fileName)
{
    std::string::size_type pos = fileName.find_last_of('.');
    std::string extension = fileName.substr(pos + 1);

    if(loaders.find(extension) == loaders.end())
    {
        std::cerr << "Saver introuvable" << std::endl;
        return;
    }

    ResourceSaver<T> *saver = reinterpret_cast<ResourceSaver<T> *>(savers[extension]);
    saver->saveAs(fileName, resource);
}
*/

void ResourceManager::saveAs(Resource &resource, std::string fileName)
{
    std::string::size_type pos = fileName.find_last_of('.');
    std::string extension = fileName.substr(pos + 1);

    if(loaders.find(extension) == loaders.end())
    {
        std::cerr << "Saver introuvable" << std::endl;
        return;
    }

    savers[extension]->saveAs(fileName, resource);
}
