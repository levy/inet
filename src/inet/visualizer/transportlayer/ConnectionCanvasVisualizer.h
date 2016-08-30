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

#ifndef __INET_CONNECTIONCANVASVISUALIZER_H
#define __INET_CONNECTIONCANVASVISUALIZER_H

#include "inet/common/geometry/common/CanvasProjection.h"
#include "inet/visualizer/base/ConnectionVisualizerBase.h"

namespace inet {

namespace visualizer {

class INET_API ConnectionCanvasVisualizer : public ConnectionVisualizerBase
{
  protected:
    class INET_API CanvasConnection : public Connection {
      public:
        cFigure *sourceFigure = nullptr;
        cFigure *destinationFigure = nullptr;

      public:
        CanvasConnection(cFigure *sourceFigure, cFigure *destinationFigure, int sourceModuleId, int destinationModuleId, int count);
    };

  protected:
    const CanvasProjection *canvasProjection = nullptr;
    cGroupFigure *connectionGroup = nullptr;

  protected:
    virtual void initialize(int stage) override;

    virtual cFigure *createConnectionEndFigure(cFigure::Point position) const;
    virtual const Connection *createConnection(cModule *source, cModule *destination) const override;

    virtual void addConnection(const Connection *connection) override;
    virtual void removeConnection(const Connection *connection) override;
};

} // namespace visualizer

} // namespace inet

#endif // ifndef __INET_CONNECTIONCANVASVISUALIZER_H

