/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Arduino library for MicroChip MCP4728 I2C D/A converter.
 */

#ifndef DAC_MCP4728_H
#define DAC_MCP4728_H

#include "MarlinConfig.h"

#if ENABLED(DAC_STEPPER_CURRENT)
#include "Wire.h"

#define defaultVDD     DAC_STEPPER_MAX //was 5000 but differs with internal Vref
#define BASE_ADDR      0x60
#define RESET          0B00000110
#define WAKE           0B00001001
#define UPDATE         0B00001000
#define MULTIWRITE     0B01000000
#define SINGLEWRITE    0B01011000
#define SEQWRITE       0B01010000
#define VREFWRITE      0B10000000
#define GAINWRITE      0B11000000
#define POWERDOWNWRITE 0B10100000
#define GENERALCALL    0B00000000
#define GAINWRITE      0B11000000

// This is taken from the original lib, makes it easy to edit if needed
// DAC_OR_ADDRESS defined in pins_BOARD.h  file
#define DAC_DEV_ADDRESS (BASE_ADDR | DAC_OR_ADDRESS)


void mcp4728_init();
uint8_t mcp4728_analogWrite(uint8_t channel, uint16_t value);
uint8_t mcp4728_eepromWrite();
uint8_t mcp4728_setVref_all(uint8_t value);
uint8_t mcp4728_setGain_all(uint8_t value);
uint16_t mcp4728_getValue(uint8_t channel);
uint8_t mcp4728_fastWrite();
uint8_t mcp4728_simpleCommand(byte simpleCommand);
uint8_t mcp4728_getDrvPct(uint8_t channel);
void mcp4728_setDrvPct(uint8_t pct[XYZE]);

#endif
#endif // DAC_MCP4728_H


