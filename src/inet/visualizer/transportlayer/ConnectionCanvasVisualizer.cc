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

#include "inet/visualizer/transportlayer/ConnectionCanvasVisualizer.h"

namespace inet {

namespace visualizer {

Define_Module(ConnectionCanvasVisualizer);

ConnectionCanvasVisualizer::CanvasConnection::CanvasConnection(cFigure *sourceFigure, cFigure *destinationFigure, int sourceModuleId, int destinationModuleId, int count) :
    Connection(sourceModuleId, destinationModuleId, count),
    sourceFigure(sourceFigure),
    destinationFigure(destinationFigure)
{
}

void ConnectionCanvasVisualizer::initialize(int stage)
{
    ConnectionVisualizerBase::initialize(stage);
    if (!hasGUI()) return;
    if (stage == INITSTAGE_LOCAL) {
        auto canvas = visualizerTargetModule->getCanvas();
        canvasProjection = CanvasProjection::getCanvasProjection(canvas);
        connectionGroup = new cGroupFigure();
        canvas->addFigure(connectionGroup);
    }
}

cFigure *ConnectionCanvasVisualizer::createConnectionEndFigure(cFigure::Point position) const
{
    double size = 10;
    auto figure = new cPieSliceFigure();
    figure->setStartAngle(0);
    figure->setEndAngle(M_PI / 2);
    figure->setFilled(true);
    figure->setBounds(cFigure::Rectangle(position.x - size, position.y - size, 2 * size, 2 * size));
    return figure;
}

const ConnectionVisualizerBase::Connection *ConnectionCanvasVisualizer::createConnection(cModule *source, cModule *destination) const
{
    auto sourceFigure = createConnectionEndFigure(canvasProjection->computeCanvasPoint(getPosition(source)));
    auto destinationFigure = createConnectionEndFigure(canvasProjection->computeCanvasPoint(getPosition(destination)));
    return new CanvasConnection(sourceFigure, destinationFigure, source->getId(), destination->getId(), 1);
}

void ConnectionCanvasVisualizer::addConnection(const Connection *connection)
{
    ConnectionVisualizerBase::addConnection(connection);
    auto canvasConnection = static_cast<const CanvasConnection *>(connection);
    connectionGroup->addFigure(canvasConnection->sourceFigure);
    connectionGroup->addFigure(canvasConnection->destinationFigure);
}

void ConnectionCanvasVisualizer::removeConnection(const Connection *connection)
{
    ConnectionVisualizerBase::removeConnection(connection);
    auto canvasConnection = static_cast<const CanvasConnection *>(connection);
    connectionGroup->removeFigure(canvasConnection->sourceFigure);
    connectionGroup->removeFigure(canvasConnection->destinationFigure);
}

} // namespace visualizer

} // namespace inet

