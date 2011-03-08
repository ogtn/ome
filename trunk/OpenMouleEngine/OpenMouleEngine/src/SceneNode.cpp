////////////////////////////////////////////////////////////////////////
// SceneNode.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "SceneNode.hpp"

namespace OpenMouleEngine
{
    SceneNode::SceneNode(): Renderable(), subNodes()
    {
    }


    SceneNode::~SceneNode()
    {
    }


    void SceneNode::add(SceneNode &node)
    {
        subNodes.insert(&node);
    }
} // namespace
