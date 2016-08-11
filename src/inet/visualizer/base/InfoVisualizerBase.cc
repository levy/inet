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

#include "inet/visualizer/base/InfoVisualizerBase.h"

namespace inet {

namespace visualizer {

void InfoVisualizerBase::initialize(int stage)
{
    VisualizerBase::initialize(stage);
    if (!hasGUI()) return;
    if (stage == INITSTAGE_LOCAL) {
        moduleMatcher.setPattern(par("modules"), true, true, true);
        auto simulation = getSimulation();
        for (int id = 0; id < simulation->getLastComponentId(); id++) {
            auto component = simulation->getComponent(id);
            if (component != nullptr && component->isModule() && moduleMatcher.matches(component->getFullPath().c_str()))
                moduleIds.push_back(static_cast<cModule *>(component)->getId());
        }
    }
}

} // namespace visualizer

} // namespace inet

