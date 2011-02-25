////////////////////////////////////////////////////////////////////////
// ResourceManager.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////


template <typename T>
T *ResourceManager::get(std::string fileName)
{
    Mesh *mesh;

    if(resources.find(fileName) == resources.end())
    {
        char name[256];
        sprintf(name, "Mesh_%d", cpt++);
        std::string sname(name);
        mesh = new Mesh(name);
    }
    else
        mesh = resources[name];

    return mesh;
}
