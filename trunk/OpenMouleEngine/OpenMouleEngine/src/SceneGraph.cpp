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


    void SceneGraph::renderAll()
    {
        std::set<SceneNode*>::iterator it;

        for(it = nodes.begin(); it != nodes.end(); ++it)
            (*it)->render();
    }
} // namespace
