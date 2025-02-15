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
 * Czech
 *
 * LCD Menu Messages
 * See also http://marlinfw.org/docs/development/lcd_language.html
 *
 * Translated by Petr Zahradnik, Computer Laboratory
 * Blog and video blog Zahradnik se bavi
 * http://www.zahradniksebavi.cz
 *
 */
#ifndef LANGUAGE_CZ_H
#define LANGUAGE_CZ_H

#define DISPLAY_CHARSET_ISO10646_1

#define WELCOME_MSG                         MACHINE_NAME _UxGT(" pripraven.")
#define MSG_BACK                            _UxGT("Zpet")
#define MSG_SD_INSERTED                     _UxGT("Karta vlozena")
#define MSG_SD_REMOVED                      _UxGT("Karta vyjmuta")
#define MSG_LCD_ENDSTOPS                    _UxGT("Endstopy") // max 8 znaku
#define MSG_MAIN                            _UxGT("Hlavni nabidka")
#define MSG_AUTOSTART                       _UxGT("Autostart")
#define MSG_DISABLE_STEPPERS                _UxGT("Uvolnit motory")
#define MSG_DEBUG_MENU                      _UxGT("Nabidka ladeni")
#define MSG_PROGRESS_BAR_TEST               _UxGT("Test uk.prubehu")
#define MSG_AUTO_HOME                       _UxGT("Domovska pozice")
#define MSG_AUTO_HOME_X                     _UxGT("Domu osa X")
#define MSG_AUTO_HOME_Y                     _UxGT("Domu osa Y")
#define MSG_AUTO_HOME_Z                     _UxGT("Domu osa Z")
#define MSG_LEVEL_BED_HOMING                _UxGT("Mereni podlozky")
#define MSG_LEVEL_BED_WAITING               _UxGT("Kliknutim spustte")
#define MSG_LEVEL_BED_NEXT_POINT            _UxGT("Dalsi bod")
#define MSG_LEVEL_BED_DONE                  _UxGT("Mereni hotovo!")
#define MSG_Z_FADE_HEIGHT                   _UxGT("Vyska srovnavani")
#define MSG_SET_HOME_OFFSETS                _UxGT("Nastavit ofsety")
#define MSG_HOME_OFFSETS_APPLIED            _UxGT("Ofsety nastaveny")
#define MSG_SET_ORIGIN                      _UxGT("Nastavit pocatek")
#define MSG_PREHEAT_1                       _UxGT("Zahrat PLA")
#define MSG_PREHEAT_1_N                     MSG_PREHEAT_1 _UxGT(" ")
#define MSG_PREHEAT_1_ALL                   MSG_PREHEAT_1 _UxGT(" vse")
#define MSG_PREHEAT_1_END                   MSG_PREHEAT_1 _UxGT(" hotend")
#define MSG_PREHEAT_1_BEDONLY               MSG_PREHEAT_1 _UxGT(" podloz")
#define MSG_PREHEAT_1_SETTINGS              MSG_PREHEAT_1 _UxGT(" nast")
#define MSG_PREHEAT_2                       _UxGT("Zahrat ABS")
#define MSG_PREHEAT_2_N                     MSG_PREHEAT_2 _UxGT(" ")
#define MSG_PREHEAT_2_ALL                   MSG_PREHEAT_2 _UxGT(" vse")
#define MSG_PREHEAT_2_END                   MSG_PREHEAT_2 _UxGT(" hotend")
#define MSG_PREHEAT_2_BEDONLY               MSG_PREHEAT_2 _UxGT(" podloz")
#define MSG_PREHEAT_2_SETTINGS              MSG_PREHEAT_2 _UxGT(" nast")
#define MSG_COOLDOWN                        _UxGT("Zchladit")
#define MSG_SWITCH_PS_ON                    _UxGT("Zapnout napajeni")
#define MSG_SWITCH_PS_OFF                   _UxGT("Vypnout napajeni")
#define MSG_EXTRUDE                         _UxGT("Vytlacit (extr.)")
#define MSG_RETRACT                         _UxGT("Zatlacit (retr.)")
#define MSG_MOVE_AXIS                       _UxGT("Posunout osy")
#define MSG_BED_LEVELING                    _UxGT("Vyrovnat podlozku")
#define MSG_LEVEL_BED                       _UxGT("Vyrovnat podlozku")
#define MSG_LEVEL_CORNERS                   _UxGT("Vyrovnat rohy")
#define MSG_NEXT_CORNER                     _UxGT("Dalsi roh")
#define MSG_EDITING_STOPPED                 _UxGT("Konec uprav site")

#define MSG_UBL_DOING_G29                   _UxGT("Provadim G29")
#define MSG_UBL_UNHOMED                     _UxGT("Prejedte domu")
#define MSG_UBL_TOOLS                       _UxGT("UBL nastroje")
#define MSG_UBL_LEVEL_BED                   _UxGT("Unified Bed Leveling")
#define MSG_UBL_MANUAL_MESH                 _UxGT("Manualni sit bodu")
#define MSG_UBL_BC_INSERT                   _UxGT("Vlozte kartu, zmerte")
#define MSG_UBL_BC_INSERT2                  _UxGT("Zmerte")
#define MSG_UBL_BC_REMOVE                   _UxGT("Odstrante a zmerte")
#define MSG_UBL_MOVING_TO_NEXT              _UxGT("Presoun na dalsi")
#define MSG_UBL_ACTIVATE_MESH               _UxGT("Aktivovat UBL")
#define MSG_UBL_DEACTIVATE_MESH             _UxGT("Deaktivovat UBL")
#define MSG_UBL_SET_BED_TEMP                _UxGT("Teplota podlozky")
#define MSG_UBL_CUSTOM_BED_TEMP             MSG_UBL_SET_BED_TEMP
#define MSG_UBL_SET_HOTEND_TEMP             _UxGT("Teplota hotendu")
#define MSG_UBL_CUSTOM_HOTEND_TEMP          MSG_UBL_SET_HOTEND_TEMP
#define MSG_UBL_MESH_EDIT                   _UxGT("Uprava site bodu")
#define MSG_UBL_EDIT_CUSTOM_MESH            _UxGT("Upravit vlastni sit")
#define MSG_UBL_FINE_TUNE_MESH              _UxGT("Doladit sit bodu")
#define MSG_UBL_DONE_EDITING_MESH           _UxGT("Konec uprav site")
#define MSG_UBL_BUILD_CUSTOM_MESH           _UxGT("Vlastni sit")
#define MSG_UBL_BUILD_MESH_MENU             _UxGT("Vytvorit sit")
#define MSG_UBL_BUILD_PLA_MESH              _UxGT("Sit bodu PLA")
#define MSG_UBL_BUILD_ABS_MESH              _UxGT("Sit bodu ABS")
#define MSG_UBL_BUILD_COLD_MESH             _UxGT("Studena sit bodu")
#define MSG_UBL_MESH_HEIGHT_ADJUST          _UxGT("Upravit vysku site")
#define MSG_UBL_MESH_HEIGHT_AMOUNT          _UxGT("Vyska")
#define MSG_UBL_VALIDATE_MESH_MENU          _UxGT("Zkontrolovat sit")
#define MSG_UBL_VALIDATE_PLA_MESH           _UxGT("Kontrola site PLA")
#define MSG_UBL_VALIDATE_ABS_MESH           _UxGT("Kontrola site ABS")
#define MSG_UBL_VALIDATE_CUSTOM_MESH        _UxGT("Kontrola vlast. site")
#define MSG_UBL_CONTINUE_MESH               _UxGT("Pokracovat v siti")
#define MSG_UBL_MESH_LEVELING               _UxGT("Sitove rovnani")
#define MSG_UBL_3POINT_MESH_LEVELING        _UxGT("3-bodove rovnani")
#define MSG_UBL_GRID_MESH_LEVELING          _UxGT("Mrizkove rovnani")
#define MSG_UBL_MESH_LEVEL                  _UxGT("Srovnat podlozku")
#define MSG_UBL_SIDE_POINTS                 _UxGT("Postranni body")
#define MSG_UBL_MAP_TYPE                    _UxGT("Typ site bodu")
#define MSG_UBL_OUTPUT_MAP                  _UxGT("Exportovat sit")
#define MSG_UBL_OUTPUT_MAP_HOST             _UxGT("Exportovat do PC")
#define MSG_UBL_OUTPUT_MAP_CSV              _UxGT("Exportovat do CSV")
#define MSG_UBL_OUTPUT_MAP_BACKUP           _UxGT("Zaloha do PC")
#define MSG_UBL_INFO_UBL                    _UxGT("Info o UBL do PC")
#define MSG_UBL_EDIT_MESH_MENU              _UxGT("Upravit sit dobu")
#define MSG_UBL_FILLIN_AMOUNT               _UxGT("Hustota mrizky")
#define MSG_UBL_MANUAL_FILLIN               _UxGT("Rucni hustota")
#define MSG_UBL_SMART_FILLIN                _UxGT("Chytra hustota")
#define MSG_UBL_FILLIN_MESH                 _UxGT("Zaplnit mrizku")
#define MSG_UBL_INVALIDATE_ALL              _UxGT("Zrusit vsechno")
#define MSG_UBL_INVALIDATE_CLOSEST          _UxGT("Zrusit posledni")
#define MSG_UBL_FINE_TUNE_ALL               _UxGT("Upravit vsechny")
#define MSG_UBL_FINE_TUNE_CLOSEST           _UxGT("Upravit posledni")
#define MSG_UBL_STORAGE_MESH_MENU           _UxGT("Uloziste siti")
#define MSG_UBL_STORAGE_SLOT                _UxGT("Pametovy slot")
#define MSG_UBL_LOAD_MESH                   _UxGT("Nacist sit bodu")
#define MSG_UBL_SAVE_MESH                   _UxGT("Ulozit sit bodu")
#define MSG_MESH_LOADED                     _UxGT("Sit %i nactena")
#define MSG_NO_STORAGE                      _UxGT("Nedostatek mista")
#define MSG_MESH_SAVED                      _UxGT("Sit %i ulozena")
#define MSG_UBL_SAVE_ERROR                  _UxGT("Err: Ulozit UBL")
#define MSG_UBL_RESTORE_ERROR               _UxGT("Err: Obnovit UBL")
#define MSG_UBL_Z_OFFSET_STOPPED            _UxGT("Konec Z-Offsetu")
#define MSG_UBL_STEP_BY_STEP_MENU           _UxGT("UBL Postupne")

#define MSG_LED_CONTROL                     _UxGT("LED Nastaveni")
#define MSG_LEDS_ON                         _UxGT("Svetla Zap")
#define MSG_LEDS_OFF                        _UxGT("Svetla Vyp")
#define MSG_LED_PRESETS                     _UxGT("Svetla Predvolby")
#define MSG_SET_LEDS_RED                    _UxGT("Svetla Cervena")
#define MSG_SET_LEDS_ORANGE                 _UxGT("Svetla Oranzova")
#define MSG_SET_LEDS_YELLOW                 _UxGT("Svetla Zluta")
#define MSG_SET_LEDS_GREEN                  _UxGT("Svetla Zelena")
#define MSG_SET_LEDS_BLUE                   _UxGT("Svetla Modra")
#define MSG_SET_LEDS_INDIGO                 _UxGT("Svetla Indigo")
#define MSG_SET_LEDS_VIOLET                 _UxGT("Svetla Fialova")
#define MSG_SET_LEDS_WHITE                  _UxGT("Svetla Bila")
#define MSG_SET_LEDS_DEFAULT                _UxGT("Svetla Vychozi")
#define MSG_CUSTOM_LEDS                     _UxGT("Vlastni svetla")
#define MSG_INTENSITY_R                     _UxGT("Cervena intenzita")
#define MSG_INTENSITY_G                     _UxGT("Zelena intezita")
#define MSG_INTENSITY_B                     _UxGT("Modra intenzita")
#define MSG_INTENSITY_W                     _UxGT("Bila intenzita")
#define MSG_LED_BRIGHTNESS                  _UxGT("Jas")

#define MSG_USER_MENU                       _UxGT("Vlastni prikazy")
#define MSG_MOVING                          _UxGT("Posouvani...")
#define MSG_FREE_XY                         _UxGT("Uvolnit XY")
#define MSG_MOVE_X                          _UxGT("Posunout X")
#define MSG_MOVE_Y                          _UxGT("Posunout Y")
#define MSG_MOVE_Z                          _UxGT("Posunout Z")
#define MSG_MOVE_E                          _UxGT("Extruder")
#define MSG_MOVE_01MM                       _UxGT("Posunout o 0,1mm")
#define MSG_MOVE_1MM                        _UxGT("Posunout o 1mm")
#define MSG_MOVE_10MM                       _UxGT("Posunout o 10mm")
#define MSG_SPEED                           _UxGT("Rychlost")
#define MSG_BED_Z                           _UxGT("Vyska podl.")
#define MSG_NOZZLE                          _UxGT("Tryska")
#define MSG_BED                             _UxGT("Podlozka")
#define MSG_FAN_SPEED                       _UxGT("Rychlost vent.")
#define MSG_EXTRA_FAN_SPEED                 _UxGT("Rychlost ex. vent.")
#define MSG_FLOW                            _UxGT("Prutok")
#define MSG_CONTROL                         _UxGT("Ovladani")
#define MSG_MIN                             _UxGT(" ") LCD_STR_THERMOMETER _UxGT(" Min")
#define MSG_MAX                             _UxGT(" ") LCD_STR_THERMOMETER _UxGT(" Max")
#define MSG_FACTOR                          _UxGT(" ") LCD_STR_THERMOMETER _UxGT(" Fakt")
#define MSG_AUTOTEMP                        _UxGT("Autoteplota")
#define MSG_ON                              _UxGT("Zap")
#define MSG_OFF                             _UxGT("Vyp")
#define MSG_PID_P                           _UxGT("PID-P")
#define MSG_PID_I                           _UxGT("PID-I")
#define MSG_PID_D                           _UxGT("PID-D")
#define MSG_PID_C                           _UxGT("PID-C")
#define MSG_SELECT                          _UxGT("Vybrat")
#define MSG_ACC                             _UxGT("Zrychl")
#define MSG_JERK                            _UxGT("Jerk")
#define MSG_VX_JERK                         _UxGT("Vx-jerk")
#define MSG_VY_JERK                         _UxGT("Vy-jerk")
#define MSG_VZ_JERK                         _UxGT("Vz-jerk")
#define MSG_VE_JERK                         _UxGT("Ve-jerk")
#define MSG_VELOCITY                        _UxGT("Rychlost")
#define MSG_VMAX                            _UxGT("Vmax ")
#define MSG_VMIN                            _UxGT("Vmin")
#define MSG_VTRAV_MIN                       _UxGT("VTrav min")
#define MSG_ACCELERATION                    _UxGT("Akcelerace")
#define MSG_AMAX                            _UxGT("Amax ")
#define MSG_A_RETRACT                       _UxGT("A-retrakt")
#define MSG_A_TRAVEL                        _UxGT("A-prejezd")
#define MSG_STEPS_PER_MM                    _UxGT("Kroku/mm")
#define MSG_XSTEPS                          _UxGT("Xkroku/mm")
#define MSG_YSTEPS                          _UxGT("Ykroku/mm")
#define MSG_ZSTEPS                          _UxGT("Zkroku/mm")
#define MSG_ESTEPS                          _UxGT("Ekroku/mm")
#define MSG_E1STEPS                         _UxGT("E1kroku/mm")
#define MSG_E2STEPS                         _UxGT("E2kroku/mm")
#define MSG_E3STEPS                         _UxGT("E3kroku/mm")
#define MSG_E4STEPS                         _UxGT("E4kroku/mm")
#define MSG_E5STEPS                         _UxGT("E5kroku/mm")
#define MSG_TEMPERATURE                     _UxGT("Teplota")
#define MSG_MOTION                          _UxGT("Pohyb")
#define MSG_FILAMENT                        _UxGT("Filament")
#define MSG_VOLUMETRIC_ENABLED              _UxGT("E na mm3")
#define MSG_FILAMENT_DIAM                   _UxGT("Fil. Prum.")
#define MSG_ADVANCE_K                       _UxGT("K pro posun")
#define MSG_CONTRAST                        _UxGT("Kontrast LCD")
#define MSG_STORE_EEPROM                    _UxGT("Ulozit nastaveni")
#define MSG_LOAD_EEPROM                     _UxGT("Nacist nastaveni")
#define MSG_RESTORE_FAILSAFE                _UxGT("Obnovit vychozi")
#define MSG_INIT_EEPROM                     _UxGT("Inic. EEPROM")
#define MSG_REFRESH                         _UxGT("Obnovit")
#define MSG_WATCH                           _UxGT("Info obrazovka")
#define MSG_PREPARE                         _UxGT("Priprava tisku")
#define MSG_TUNE                            _UxGT("Doladeni tisku")
#define MSG_PAUSE_PRINT                     _UxGT("Pozastavit tisk")
#define MSG_RESUME_PRINT                    _UxGT("Obnovit tisk")
#define MSG_STOP_PRINT                      _UxGT("Zastavit tisk")
#define MSG_CARD_MENU                       _UxGT("Tisknout z SD")
#define MSG_NO_CARD                         _UxGT("Zadna SD karta")
#define MSG_DWELL                           _UxGT("Uspano...")
#define MSG_USERWAIT                        _UxGT("Cekani na uziv...")
#define MSG_PRINT_PAUSED                    _UxGT("Tisk pozastaven")
#define MSG_RESUMING                        _UxGT("Obnovovani tisku")
#define MSG_PRINT_ABORTED                   _UxGT("Tisk zrusen")
#define MSG_NO_MOVE                         _UxGT("Zadny pohyb.")
#define MSG_KILLED                          _UxGT("PRERUSENO. ")
#define MSG_STOPPED                         _UxGT("ZASTAVENO. ")
#define MSG_CONTROL_RETRACT                 _UxGT("Retrakt mm")
#define MSG_CONTROL_RETRACT_SWAP            _UxGT("Vymena Re.mm")
#define MSG_CONTROL_RETRACTF                _UxGT("Retraktovat  V")
#define MSG_CONTROL_RETRACT_ZLIFT           _UxGT("Zvednuti Z mm")
#define MSG_CONTROL_RETRACT_RECOVER         _UxGT("UnRet mm")
#define MSG_CONTROL_RETRACT_RECOVER_SWAP    _UxGT("S UnRet mm")
#define MSG_CONTROL_RETRACT_RECOVERF        _UxGT("UnRet  V")
#define MSG_CONTROL_RETRACT_RECOVER_SWAPF   _UxGT("S UnRet V")
#define MSG_AUTORETRACT                     _UxGT("AutoRetr.")
#define MSG_FILAMENTCHANGE                  _UxGT("Vymenit filament")
#define MSG_INIT_SDCARD                     _UxGT("Nacist SD kartu")
#define MSG_CNG_SDCARD                      _UxGT("Vymenit SD kartu")
#define MSG_ZPROBE_OUT                      _UxGT("Sonda Z mimo podl")
#define MSG_SKEW_FACTOR                     _UxGT("Faktor zkoseni")
#define MSG_BLTOUCH                         _UxGT("BLTouch")
#define MSG_BLTOUCH_SELFTEST                _UxGT("BLTouch Self-Test")
#define MSG_BLTOUCH_RESET                   _UxGT("BLTouch Reset")
#define MSG_BLTOUCH_DEPLOY                  _UxGT("BLTouch Vysunout")
#define MSG_BLTOUCH_STOW                    _UxGT("BLTouch Zasunout")
#define MSG_HOME                            _UxGT("Domu")  // Used as MSG_HOME " " MSG_X MSG_Y MSG_Z " " MSG_FIRST
#define MSG_FIRST                           _UxGT("prvni")
#define MSG_ZPROBE_ZOFFSET                  _UxGT("Z ofset")
#define MSG_BABYSTEP_X                      _UxGT("Babystep X")
#define MSG_BABYSTEP_Y                      _UxGT("Babystep Y")
#define MSG_BABYSTEP_Z                      _UxGT("Babystep Z")
#define MSG_ENDSTOP_ABORT                   _UxGT("Endstop abort")
#define MSG_HEATING_FAILED_LCD              _UxGT("Chyba zahrivani")
#define MSG_ERR_REDUNDANT_TEMP              _UxGT("REDUND. TEPLOTA")
#define MSG_THERMAL_RUNAWAY                 _UxGT("TEPLOTNI SKOK")
#define MSG_ERR_MAXTEMP                     _UxGT("VYSOKA TEPLOTA")
#define MSG_ERR_MINTEMP                     _UxGT("NIZKA TEPLOTA")
#define MSG_ERR_MAXTEMP_BED                 _UxGT("VYS. TEPL. PODL.")
#define MSG_ERR_MINTEMP_BED                 _UxGT("NIZ. TEPL. PODL.")
#define MSG_ERR_Z_HOMING                    _UxGT("G28 Z ZAKAZANO")
#define MSG_HALTED                          _UxGT("TISK. ZASTAVENA")
#define MSG_PLEASE_RESET                    _UxGT("Provedte reset")
#define MSG_SHORT_DAY                       _UxGT("d")
#define MSG_SHORT_HOUR                      _UxGT("h")
#define MSG_SHORT_MINUTE                    _UxGT("m")
#define MSG_HEATING                         _UxGT("Zahrivani...")
#define MSG_HEATING_COMPLETE                _UxGT("Zahrati hotovo.")
#define MSG_BED_HEATING                     _UxGT("Zahrivani podl.")
#define MSG_BED_DONE                        _UxGT("Podlozka hotova.")
#define MSG_DELTA_CALIBRATE                 _UxGT("Delta Kalibrace")
#define MSG_DELTA_CALIBRATE_X               _UxGT("Kalibrovat X")
#define MSG_DELTA_CALIBRATE_Y               _UxGT("Kalibrovat Y")
#define MSG_DELTA_CALIBRATE_Z               _UxGT("Kalibrovat Z")
#define MSG_DELTA_CALIBRATE_CENTER          _UxGT("Kalibrovat Stred")
#define MSG_DELTA_SETTINGS                  _UxGT("Delta nastaveni")
#define MSG_DELTA_AUTO_CALIBRATE            _UxGT("Autokalibrace")
#define MSG_DELTA_HEIGHT_CALIBRATE          _UxGT("Nast.vysku delty")
#define MSG_DELTA_DIAG_ROD                  _UxGT("Diag rameno")
#define MSG_DELTA_HEIGHT                    _UxGT("Vyska")
#define MSG_DELTA_RADIUS                    _UxGT("Polomer")
#define MSG_INFO_MENU                       _UxGT("O tiskarne")
#define MSG_INFO_PRINTER_MENU               _UxGT("Info o tiskarne")
#define MSG_3POINT_LEVELING                 _UxGT("3-bodove rovnani")
#define MSG_LINEAR_LEVELING                 _UxGT("Linearni rovnani")
#define MSG_BILINEAR_LEVELING               _UxGT("Bilinearni rovnani")
#define MSG_UBL_LEVELING                    _UxGT("Unified Bed Leveling")
#define MSG_MESH_LEVELING                   _UxGT("Mrizkove rovnani")
#define MSG_INFO_STATS_MENU                 _UxGT("Statistika")
#define MSG_INFO_BOARD_MENU                 _UxGT("Info o desce")
#define MSG_INFO_THERMISTOR_MENU            _UxGT("Termistory")
#define MSG_INFO_EXTRUDERS                  _UxGT("Extrudery")
#define MSG_INFO_BAUDRATE                   _UxGT("Rychlost")
#define MSG_INFO_PROTOCOL                   _UxGT("Protokol")
#define MSG_CASE_LIGHT                      _UxGT("Osvetleni")
#define MSG_CASE_LIGHT_BRIGHTNESS           _UxGT("Jas svetla")

#if LCD_WIDTH >= 20
  #define MSG_INFO_PRINT_COUNT              _UxGT("Pocet tisku")
  #define MSG_INFO_COMPLETED_PRINTS         _UxGT("Dokonceno")
  #define MSG_INFO_PRINT_TIME               _UxGT("Celkovy cas")
  #define MSG_INFO_PRINT_LONGEST            _UxGT("Nejdelsi tisk")
  #define MSG_INFO_PRINT_FILAMENT           _UxGT("Celkem vytlaceno")
#else
  #define MSG_INFO_PRINT_COUNT              _UxGT("Tisky")
  #define MSG_INFO_COMPLETED_PRINTS         _UxGT("Hotovo")
  #define MSG_INFO_PRINT_TIME               _UxGT("Cas")
  #define MSG_INFO_PRINT_LONGEST            _UxGT("Nejdelsi")
  #define MSG_INFO_PRINT_FILAMENT           _UxGT("Vytlaceno")
#endif

#define MSG_INFO_MIN_TEMP                   _UxGT("Teplota min")
#define MSG_INFO_MAX_TEMP                   _UxGT("Teplota max")
#define MSG_INFO_PSU                        _UxGT("Nap. zdroj")
#define MSG_DRIVE_STRENGTH                  _UxGT("Buzeni motoru")
#define MSG_DAC_PERCENT                     _UxGT("Motor %")
#define MSG_DAC_EEPROM_WRITE                _UxGT("Ulozit do EEPROM")
#define MSG_FILAMENT_CHANGE_HEADER          _UxGT("PRINT PAUSED")
#define MSG_FILAMENT_CHANGE_OPTION_HEADER   _UxGT("RESUME OPTIONS:")
#define MSG_FILAMENT_CHANGE_OPTION_EXTRUDE  _UxGT("Jeste vytlacit")
#define MSG_FILAMENT_CHANGE_OPTION_RESUME   _UxGT("Obnovit tisk")
#define MSG_FILAMENT_CHANGE_MINTEMP         _UxGT("Min. teplota je ")
#define MSG_FILAMENT_CHANGE_NOZZLE          _UxGT("  Tryska: ")
#define MSG_ERR_HOMING_FAILED               _UxGT("Parkovani selhalo")
#define MSG_ERR_PROBING_FAILED              _UxGT("Kalibrace selhala")

#if LCD_HEIGHT >= 4
  // Up to 3 lines allowed
  #define MSG_FILAMENT_CHANGE_INIT_1          _UxGT("Cekejte prosim")
  #define MSG_FILAMENT_CHANGE_INIT_2          _UxGT("na zahajeni")
  #define MSG_FILAMENT_CHANGE_INIT_3          _UxGT("vymeny filamentu")
  #define MSG_FILAMENT_CHANGE_UNLOAD_1        _UxGT("Cekejte prosim")
  #define MSG_FILAMENT_CHANGE_UNLOAD_2        _UxGT("na vysunuti")
  #define MSG_FILAMENT_CHANGE_UNLOAD_3        _UxGT("filamentu")
  #define MSG_FILAMENT_CHANGE_INSERT_1        _UxGT("Vlozte filament")
  #define MSG_FILAMENT_CHANGE_INSERT_2        _UxGT("a stisknete")
  #define MSG_FILAMENT_CHANGE_INSERT_3        _UxGT("tlacitko...")
  #define MSG_FILAMENT_CHANGE_HEAT_1          _UxGT("Kliknete pro")
  #define MSG_FILAMENT_CHANGE_HEAT_2          _UxGT("nahrati trysky")
  #define MSG_FILAMENT_CHANGE_HEATING_1       _UxGT("Cekejte prosim")
  #define MSG_FILAMENT_CHANGE_HEATING_2       _UxGT("na nahrati tr.")
  #define MSG_FILAMENT_CHANGE_LOAD_1          _UxGT("Cekejte prosim")
  #define MSG_FILAMENT_CHANGE_LOAD_2          _UxGT("na zavedeni")
  #define MSG_FILAMENT_CHANGE_LOAD_3          _UxGT("filamentu")
  #define MSG_FILAMENT_CHANGE_EXTRUDE_1       _UxGT("Cekejte prosim")
  #define MSG_FILAMENT_CHANGE_EXTRUDE_2       _UxGT("na vytlaceni")
  #define MSG_FILAMENT_CHANGE_EXTRUDE_3       _UxGT("filamentu")
  #define MSG_FILAMENT_CHANGE_RESUME_1        _UxGT("Cekejte prosim")
  #define MSG_FILAMENT_CHANGE_RESUME_2        _UxGT("na pokracovani")
  #define MSG_FILAMENT_CHANGE_RESUME_3        _UxGT("tisku")
#else // LCD_HEIGHT < 4
  // Up to 2 lines allowed
  #define MSG_FILAMENT_CHANGE_INIT_1          _UxGT("Cekejte...")
  #define MSG_FILAMENT_CHANGE_UNLOAD_1        _UxGT("Vysouvani...")
  #define MSG_FILAMENT_CHANGE_INSERT_1        _UxGT("Vlozte, kliknete")
  #define MSG_FILAMENT_CHANGE_HEATING_1       _UxGT("Nahrivani...")
  #define MSG_FILAMENT_CHANGE_LOAD_1          _UxGT("Zavadeni...")
  #define MSG_FILAMENT_CHANGE_EXTRUDE_1       _UxGT("Vytlacovani...")
  #define MSG_FILAMENT_CHANGE_RESUME_1        _UxGT("Pokracovani...")
#endif // LCD_HEIGHT < 4

#endif // LANGUAGE_CZ_H


