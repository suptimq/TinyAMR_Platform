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

#ifndef CONFIGURATION_STORE_H
#define CONFIGURATION_STORE_H

#include "MarlinConfig.h"





/****************************BIQU ADD****************************************************/

#if ENABLED(AUTO_BED_LEVELING_BILINEAR) 


void storeLevelingPara(void);
void readLevelingPara(void);

void storeBabyStepping(void);
void readBabyStepping(void);

#endif

/*****************************************************************/



class MarlinSettings {
  public:
    MarlinSettings() { }

    static void reset();
    static bool save();

    #if ENABLED(EEPROM_SETTINGS)
      static bool load();

      #if ENABLED(AUTO_BED_LEVELING_UBL) // Eventually make these available if any leveling system
                                         // That can store is enabled
        FORCE_INLINE static int16_t get_start_of_meshes() { return meshes_begin; }
        FORCE_INLINE static int16_t get_end_of_meshes() { return meshes_end; }
        static uint16_t calc_num_meshes();
        static void store_mesh(const int8_t slot);
        static void load_mesh(const int8_t slot, void * const into=NULL);

        //static void delete_mesh();    // necessary if we have a MAT
        //static void defrag_meshes();  // "
      #endif
    #else
      FORCE_INLINE
      static bool load() { reset(); report(); return true; }
    #endif

    #if DISABLED(DISABLE_M503)
      static void report(const bool forReplay=false);
    #else
      FORCE_INLINE
      static void report(const bool forReplay=false) { UNUSED(forReplay); }
    #endif

  private:
    static void postprocess();

    #if ENABLED(EEPROM_SETTINGS)
      static bool eeprom_error;

      #if ENABLED(AUTO_BED_LEVELING_UBL) // Eventually make these available if any leveling system
                                         // That can store is enabled
        static int16_t meshes_begin;
        const static int16_t meshes_end = E2END - 128; // 128 is a placeholder for the size of the MAT; the MAT will always
                                                       // live at the very end of the eeprom

      #endif

      static void write_data(int &pos, const uint8_t *value, uint16_t size, uint16_t *crc);
      static void read_data(int &pos, uint8_t *value, uint16_t size, uint16_t *crc);
    #endif
};

extern MarlinSettings settings;

#endif // CONFIGURATION_STORE_H


