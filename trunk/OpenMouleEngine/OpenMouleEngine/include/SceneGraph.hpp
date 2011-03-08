////////////////////////////////////////////////////////////////////////
// SceneGraph.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SCENEGRAPH
#define HPP_SCENEGRAPH

#include "Singleton.hpp"
#include "SceneNode.hpp"

namespace OpenMouleEngine
{
    class SceneGraph: public Singleton<SceneGraph>
    {
    private:
        SceneGraph();

        ~SceneGraph();

    public:
        void add(SceneNode &node);

    private:
        std::set<SceneNode*> nodes;

        friend class Singleton<SceneGraph>;
    };
} // namespace

#endif // HPP_SCENEGRAPH
