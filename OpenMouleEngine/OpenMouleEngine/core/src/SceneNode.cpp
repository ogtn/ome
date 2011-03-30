////////////////////////////////////////////////////////////////////////
// SceneNode.cpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "SceneNode.hpp"

namespace OpenMouleEngine
{
    SceneNode::SceneNode(const std::string &name)
        : Renderable(name),
        subNodes()
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
