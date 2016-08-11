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

#include "inet/visualizer/common/PacketDropOsgVisualizer.h"

namespace inet {

namespace visualizer {

Define_Module(PacketDropOsgVisualizer);

PacketDropOsgVisualizer::OsgPacketDrop::OsgPacketDrop(int moduleId, cPacket *packet, simtime_t dropTime) :
    PacketDrop(moduleId, packet, dropTime)
{
}

PacketDropOsgVisualizer::OsgPacketDrop::~OsgPacketDrop()
{
    // TODO: delete node;
}

const PacketDropVisualizerBase::PacketDrop *PacketDropOsgVisualizer::createPacketDrop(cModule *module, cPacket *packet) const
{
    return new OsgPacketDrop(module->getId(), packet, simTime());
}

void PacketDropOsgVisualizer::setAlpha(const PacketDrop *packetDrop, double alpha) const
{
}

void PacketDropOsgVisualizer::setPosition(cModule *node, const Coord& position) const
{
}

} // namespace visualizer

} // namespace inet

