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

#include "inet/common/ModuleAccess.h"
#include "inet/visualizer/common/InfoCanvasVisualizer.h"

namespace inet {

namespace visualizer {

Define_Module(InfoCanvasVisualizer);

void InfoCanvasVisualizer::initialize(int stage)
{
    InfoVisualizerBase::initialize(stage);
    if (!hasGUI()) return;
    if (stage == INITSTAGE_LOCAL) {
        networkNodeVisualizer = getModuleFromPar<NetworkNodeCanvasVisualizer>(par("networkNodeVisualizerModule"), this);
        auto simulation = getSimulation();
        for (int i = 0; i < moduleIds.size(); i++) {
            double width = 100;
            double height = 24;
            auto figure = new cLabelFigure();
            auto module = simulation->getModule(moduleIds[i]);
            auto visualization = networkNodeVisualizer->getNeworkNodeVisualization(getContainingNode(module));
            visualization->addAnnotation(figure, cFigure::Point(width, height));
            figures.push_back(figure);
        }
    }
}

void InfoCanvasVisualizer::refreshDisplay() const
{
    auto simulation = getSimulation();
    for (int i = 0; i < moduleIds.size(); i++) {
        auto module = simulation->getModule(moduleIds[i]);
        if (module != nullptr) {
            const char *content = par("content");
            const char *info;
            if (!strcmp(content, "info"))
                info = module->info().c_str();
            else if (!strcmp(content, "displayStringText"))
                info = module->getDisplayString().getTagArg("t", 0);
            else
                throw cRuntimeError("Unknown content parameter value: %s", content);
            auto figure = figures[i];
            figure->setText(info);
        }
    }
}

} // namespace visualizer

} // namespace inet

