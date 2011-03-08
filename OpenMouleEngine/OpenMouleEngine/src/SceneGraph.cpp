////////////////////////////////////////////////////////////////////////
// SceneGraph.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "SceneGraph.hpp"

namespace OpenMouleEngine
{
    SceneGraph::SceneGraph()
    {
    }


    SceneGraph::~SceneGraph()
    {
    }


    void SceneGraph::add(SceneNode &node)
    {
        nodes.insert(&node);
    }
} // namespace
