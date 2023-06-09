/* Copyright 2021 gtips, HannesHasselbring
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
#include QMK_KEYBOARD_H


enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

#define CT_Q  LCTL_T(KC_Q)
#define CT_CM RCTL_T(KC_COMM)
#define SF_Z  LSFT_T(KC_Z)
#define SF_ESC LSFT_T(KC_ESC)
#define SF_F11 LSFT_T(KC_F11)
#define SF_SS RSFT_T(KC_SLSH)
#define AL_X  LALT_T(KC_X)
#define AL_DT RALT_T(KC_DOT)
#define RA_SP LT(RAISE, KC_SPC)
#define LO_EN LT(LOWER, KC_ENTER)
#define LO_BSP LT(LOWER, KC_BSPC)
#define LO_SFT LT(LOWER, OSM(MOD_LSFT)) # todo: not working
#define WIN_SWT LGUI(KC_TAB)
#define IN_WIN_SWT LGUI(KC_GRV)
#define LALT_TAB LALT_T(KC_TAB)
#define LGUI_ENT LGUI_T(KC_ENT)
#define LGUI_QUOT  LGUI_T(KC_QUOT)
#define SRN_SHT LSFT(LCTL(LGUI(KC_4))) //Shift-Command-4


const uint16_t PROGMEM esc_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM ctrl_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_U, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(ctrl_combo, OSM(MOD_LCTL)),
    COMBO(ent_combo, KC_ENT),
    COMBO(quot_combo, CW_TOGG)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung34(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,          KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
    SF_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_K,    KC_M,    KC_COMM, KC_DOT,  SF_SS,
                           LGUI_QUOT,  LO_EN,          RA_SP,  LALT_TAB
  ),

  [_LOWER] = LAYOUT_reviung34(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN,
    SF_ESC, KC_LCTL,  KC_LALT, KC_LGUI, KC_QUOT,       KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_BSPC,
                               _______, _______,       _______, OSM(MOD_LCTL)
  ), 
  
  [_RAISE] = LAYOUT_reviung34(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,       LGUI(KC_GRV), XXXXXXX, KC_GRV,  KC_TILD, KC_COLN,
    SF_ESC, KC_RCTL,  KC_RALT, KC_RGUI, KC_DQUO,       KC_TAB,  XXXXXXX, KC_RCTL, KC_RALT, KC_ENTER,
                               OSM(MOD_LCTL), _______,       _______, _______
  ),
  
  [_ADJUST] = LAYOUT_reviung34(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, XXXXXXX,
    SF_F11,  KC_F12,  XXXXXXX, XXXXXXX, SRN_SHT,       WIN_SWT, IN_WIN_SWT, XXXXXXX, XXXXXXX, MAGIC_TOGGLE_CTL_GUI,
                               _______, _______,       _______, _______
  ),
};


const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 2, HSV_RED}
    // {4, 4, HSV_RED},
    // {8, 1, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // {0, 4, HSV_PURPLE},
    // {4, 4, HSV_YELLOW},
    {7, 2, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // {0, 4, HSV_GREEN},
    // {4, 4, HSV_WHITE},
    {7, 2, HSV_TEAL}
);

const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 2, HSV_PINK}
);
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,    
    my_layer2_layer,    
    my_layer3_layer,
    my_layer4_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    
    return state;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }