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
 * leds.cpp - Marlin RGB LED general support
 */

#include "MarlinConfig.h"

#if HAS_COLOR_LEDS

#include "leds.h"

#if ENABLED(BLINKM)
  #include "blinkm.h"
#endif

#if ENABLED(PCA9632)
  #include "pca9632.h"
#endif

#if ENABLED(LED_COLOR_PRESETS)
  const LEDColor LEDLights::defaultLEDColor = MakeLEDColor(
    LED_USER_PRESET_RED,
    LED_USER_PRESET_GREEN,
    LED_USER_PRESET_BLUE,
    LED_USER_PRESET_WHITE,
    LED_USER_PRESET_BRIGHTNESS
  );
#endif

#if ENABLED(LED_CONTROL_MENU)
  LEDColor LEDLights::color;
  bool LEDLights::lights_on;
#endif

LEDLights leds;

void LEDLights::setup() {
  #if ENABLED(NEOPIXEL_LED)
    setup_neopixel();
  #endif
  #if ENABLED(LED_USER_PRESET_STARTUP)
    set_default();
  #endif
}

void LEDLights::set_color(const LEDColor &incol
  #if ENABLED(NEOPIXEL_LED)
    , bool isSequence/*=false*/
  #endif
) {

  #if ENABLED(NEOPIXEL_LED)

    const uint32_t neocolor = pixels.Color(incol.r, incol.g, incol.b, incol.w);
    static uint16_t nextLed = 0;

    pixels.setBrightness(incol.i);
    if (!isSequence)
      set_neopixel_color(neocolor);
    else {
      pixels.setPixelColor(nextLed, neocolor);
      pixels.show();
      if (++nextLed >= pixels.numPixels()) nextLed = 0;
      return;
    }

  #endif

  #if ENABLED(BLINKM)

    // This variant uses i2c to send the RGB components to the device.
    blinkm_set_led_color(incol);

  #endif

  #if ENABLED(RGB_LED) || ENABLED(RGBW_LED)

    // This variant uses 3-4 separate pins for the RGB(W) components.
    // If the pins can do PWM then their intensity will be set.
    WRITE(RGB_LED_R_PIN, incol.r ? HIGH : LOW);
    WRITE(RGB_LED_G_PIN, incol.g ? HIGH : LOW);
    WRITE(RGB_LED_B_PIN, incol.b ? HIGH : LOW);
    analogWrite(RGB_LED_R_PIN, incol.r);
    analogWrite(RGB_LED_G_PIN, incol.g);
    analogWrite(RGB_LED_B_PIN, incol.b);

    #if ENABLED(RGBW_LED)
      WRITE(RGB_LED_W_PIN, incol.w ? HIGH : LOW);
      analogWrite(RGB_LED_W_PIN, incol.w);
    #endif

  #endif

  #if ENABLED(PCA9632)
    // Update I2C LED driver
    pca9632_set_led_color(incol);
  #endif

  #if ENABLED(LED_CONTROL_MENU)
    // Don't update the color when OFF
    lights_on = !incol.is_off();
    if (lights_on) color = incol;
  #endif
}

void LEDLights::set_white() {
  #if ENABLED(RGB_LED) || ENABLED(RGBW_LED) || ENABLED(BLINKM) || ENABLED(PCA9632)
    set_color(LEDColorWhite());
  #endif
  #if ENABLED(NEOPIXEL_LED)
    set_neopixel_color(pixels.Color(NEO_WHITE));
  #endif
}

#if ENABLED(LED_CONTROL_MENU)
  void LEDLights::toggle() { if (lights_on) set_off(); else update(); }
#endif

#endif // HAS_COLOR_LEDS


