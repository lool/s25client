// Copyright (c) 2005 - 2015 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.

#include <memory>
#include <stdexcept>
#include "mapGenerator/MapGenerator.h"
#include "mapGenerator/Generator.h"
#include "mapGenerator/GreenlandGenerator.h"

void MapGenerator::Create(const std::string& filePath, Style style, const MapSettings& settings)
{
    std::unique_ptr<Generator> generator;
    
    switch (style)
    {
        case Greenland:
            generator = std::unique_ptr<Generator>(new GreenlandGenerator);
            break;
        case Riverland:
            generator = std::unique_ptr<Generator>(NULL);
            break;
        case Islands:
            generator = std::unique_ptr<Generator>(NULL);
            break;
        case Contient:
            generator = std::unique_ptr<Generator>(NULL);
            break;
        default:
            generator = std::unique_ptr<Generator>(NULL);
            break;
    }
    
    if (generator.get() == NULL)
    {
        throw new std::invalid_argument("Style not supported");
    }
    
    generator->Create(filePath, settings);
}
