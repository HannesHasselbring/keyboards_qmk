/* Copyright 2021 Hannes Hasselbring
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

// #include "config_common.h"

// /* USB Device descriptor parameter */
// #define VENDOR_ID       0xFEED
// #define PRODUCT_ID      0x0815
// #define DEVICE_VER      0x0001
// #define MANUFACTURER    3D Print
// #define PRODUCT         Banana Macropad

// /* key matrix size */
// #define MATRIX_ROWS 1
// #define MATRIX_COLS 8

// /* pin-out */
// #define MATRIX_ROW_PINS { B2 }
// #define MATRIX_COL_PINS { D1, D0, D4, C6, D7, E6, B4, B5 }

// DIRECT_PINS if you connect your switch without diode, eg.
/*
#define DIRECT_PINS { \
     { D1, D0, D4, C6, D7, E6, B4, B5 }, \
 }
*/
#define UNUSED_PINS


// Rotary encoder setup
#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_DIRECTION_FLIP

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

