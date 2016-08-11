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

package inet.visualizer.base;

simple RoutingTableVisualizerBase extends VisualizerBase
{
    parameters:
        @class(RoutingTableVisualizerBase);
        string subscriptionModule = default(""); // module path where the visualizer subscribes for routing table signals, root module by default
        string destinationFilter = default(""); // which destinations are considered, matches no destinations by default
        string lineColor = default("black"); // route line color, black by default
        double lineWidth = default(3); // route line width
        string lineStyle = default("solid"); // route line style (solid, dashed, dotted)
}
