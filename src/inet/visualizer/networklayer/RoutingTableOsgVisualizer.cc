//
// Copyright (C) 2016 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#include "inet/visualizer/networklayer/RoutingTableOsgVisualizer.h"

namespace inet {

namespace visualizer {

Define_Module(RoutingTableOsgVisualizer);

RoutingTableOsgVisualizer::OsgRoute::OsgRoute(osg::Node *node, int nodeModuleId, int nextHopModuleId) :
    Route(nodeModuleId, nextHopModuleId),
    node(node)
{
}

RoutingTableOsgVisualizer::OsgRoute::~OsgRoute()
{
    // TODO: delete node;
}

void RoutingTableOsgVisualizer::setPosition(cModule *node, const Coord& position) const
{
}

const RoutingTableVisualizerBase::Route *RoutingTableOsgVisualizer::createRoute(cModule *node, cModule *nextHop) const
{
    return nullptr;
}

} // namespace visualizer

} // namespace inet

