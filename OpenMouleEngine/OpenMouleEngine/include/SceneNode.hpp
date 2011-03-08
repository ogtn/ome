////////////////////////////////////////////////////////////////////////
// SceneNode.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SCENENODE
#define HPP_SCENENODE

#include <set>
#include "Renderable.hpp"

namespace OpenMouleEngine
{
    class SceneNode: public Renderable
    {
    public:
        SceneNode();

        virtual ~SceneNode() = 0;

        void add(SceneNode &node);

    private:
        std::set<SceneNode*> subNodes;
    };
} // namespace

#endif // HPP_SCENENODE
