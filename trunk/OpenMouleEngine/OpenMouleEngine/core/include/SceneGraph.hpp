////////////////////////////////////////////////////////////////////////
// SceneGraph.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SCENEGRAPH
#define HPP_SCENEGRAPH

#include "Singleton.hpp"
#include <set>

namespace OpenMouleEngine
{
    // forward declaration
    class SceneNode;

    class SceneGraph: public Singleton<SceneGraph>
    {
    private:
        SceneGraph();
        ~SceneGraph();

    public:
        void add(SceneNode &node);
        void renderAll();

    private:
        std::set<SceneNode*> nodes;

        friend class Singleton<SceneGraph>;
    };
} // namespace

#endif // HPP_SCENEGRAPH
