////////////////////////////////////////////////////////////////////////
// MeshData.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T> 
MeshData::MeshData(const std::string &name, const std::string &attribName, std::vector<T> *data, DataType type)
    : Resource(name),
    meshes(),
    vertexAttribs(),
    nbVertices(),
    interleavedData(NULL),
    offset(0),
    byteSize(0),
    nbMeshes(0),
    interleaved(false),
    finalized(false)
{
    // creating VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // creating the first vertex attribute
    nbVertices = data->size();
    vertexAttribs[attribName] = VertexAttrib((char *)(&(*data)[0]), byteSize, nbVertices, sizeof(T) / type.size, type);
    byteSize += data->size() * sizeof(T);
    offset += sizeof(T);
}


template <typename T> 
MeshData::MeshData(const std::string &name, const std::string &attribName, T *data, unsigned int nbVertices, DataType type)
    : Resource(name),
    meshes(),
    vertexAttribs(),
    nbVertices(nbVertices),
    interleavedData(NULL),
    offset(0),
    byteSize(0),
    nbMeshes(0),
    interleaved(false),
    finalized(false)
{
    // creating VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // creating the first vertex attribute
    vertexAttribs[attribName] = VertexAttrib(data, 0, sizeof(T) / type.size, type);
    byteSize += nbVertices * sizeof(T);
}


template <typename T> 
MeshData::MeshData(const std::string &name, T *data, int nbVertices)
    : Resource(name),
    meshes(),
    vertexAttribs(),
    nbVertices(nbVertices),
    interleavedData((char *)data),
    offset(0),
    byteSize(0),
    nbMeshes(0),
    interleaved(true),
    finalized(false)
{
    // creating VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}


template <typename T>
void MeshData::addSubArray(const std::string &attribName, std::vector<T> *data, DataType type)
{
    if(data->size() != nbVertices)
    {
        std::cerr << "addSubArray(): taille du vertex array invalide" << std::endl;
        return;
    }

    if(finalized)
    {
        std::cerr << "addSubArray(): impossible d'ajouter dans un vertex array finalise" << std::endl;
        return;
    }

    if(interleaved)
    {
        std::cerr << "addSubArray(): impossible d'ajouter dans un vertex array entrelace" << std::endl;
        return;
    }

    if(vertexAttribs.find(attribName) != vertexAttribs.end())
    {
        std::cerr << "addSubArray(): impossible d'ecraser des donnees" << std::endl;
        return;
    }

    vertexAttribs[attribName] = VertexAttrib((char *)(&(*data)[0]), byteSize, nbVertices, sizeof(T) / type.size, type);
    byteSize += data->size() * sizeof(T);
    offset += sizeof(T);
}


template <typename T>
T *MeshData::rawData(const std::string &name)
{
    if(vertexAttribs.find(name) == vertexAttribs.end())
    {
        std::cerr << "l'attribut " + name + " n'existe pas" << std::endl;
    }

    return reinterpret_cast<T *>(vertexAttribs[name].data);
}
