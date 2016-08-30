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

#ifndef __INET_PACKETDROPVISUALIZERBASE_H
#define __INET_PACKETDROPVISUALIZERBASE_H

#include "inet/common/PatternMatcher.h"
#include "inet/visualizer/base/VisualizerBase.h"

namespace inet {

namespace visualizer {

class INET_API PacketDropVisualizerBase : public VisualizerBase, public cListener
{
  protected:
    class INET_API PacketDrop {
      public:
        int moduleId;
        cPacket *packet;
        simtime_t dropTime;

      public:
        PacketDrop(int moduleId, cPacket *packet, simtime_t dropTime);
        virtual ~PacketDrop() { delete packet; }
    };

  protected:
    /** @name Parameters */
    //@{
    cModule *subscriptionModule = nullptr;
    PatternMatcher packetNameMatcher;
    const char *icon = nullptr;
    cFigure::Color iconTintColor;
    double iconTintAmount = NaN;
    double opacityHalfLife = NaN;
    //@}

    std::vector<const PacketDrop *> packetDrops;

  protected:
    virtual ~PacketDropVisualizerBase();

    virtual void initialize(int stage) override;
    virtual void refreshDisplay() const override;
    virtual void receiveSignal(cComponent *source, simsignal_t signal, cObject *object DETAILS_ARG) override;

    virtual void setAlpha(const PacketDrop *packetDrop, double alpha) const = 0;
    virtual void setPosition(cModule *node, const Coord& position) const = 0;
    virtual const PacketDrop *createPacketDrop(cModule *module, cPacket *packet) const = 0;
    virtual void addPacketDrop(const PacketDrop *packetDrop);
    virtual void removePacketDrop(const PacketDrop *packetDrop);
};

} // namespace visualizer

} // namespace inet

#endif // ifndef __INET_PACKETDROPVISUALIZERBASE_H

