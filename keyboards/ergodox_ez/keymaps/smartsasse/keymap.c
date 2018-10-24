#include QMK_KEYBOARD_H
#include QMK_KEYBOARD_CONFIG_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_swedish.h"

#define BASE 0 // basic layer
#define SHFT 1 // shifted layer
#define NAV1 2 // navigation layer 1
#define NAV2 3 // navigation layer 2
#define NUMB 4 // number and function layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   @  |   [  |   {  |   (  |   $  |   %  |           |   &  |   =  |   )  |   }  |   ]  |   #  |    ´   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | L-NAV2 |   -  |   ,  |   .  |   p  |   y  |   \  |           |   /  |   f  |   g  |   c  |   r  |   l  | L-NAV2 |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | L-NAV1 |   a  |   o  |   e  |   u  |   i  |------|           |------|   d  |   h  |   t  |   n  |   s  | L-NAV1 |
 * |--------+------+------+------+------+------|   !  |           |   ?  |------+------+------+------+------+--------|
 * | L-SHFT |   '  |   q  |   j  |   k  |   x  |      |           |      |   b  |   m  |   w  |   v  |   z  | L-SHFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |L-NUMB| Shift| Ctrl |  Alt |  Cmd |                                       |   ;  |   Å  |   Ä  |   Ö  |L-NUMB|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|  Tab |------|       |------| Back-| Enter|
 *                                 |      |      |      |       |  Del | space|      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
       // left hand
       KC_ESC,    NO_AT,     NO_LBRC,  NO_LCBR_MAC,  NO_LPRN,  NO_DLR,   KC_PERC,
       MO(NAV2),  NO_MINS,   KC_COMM,  KC_DOT,       KC_P,     KC_Y,     NO_BSLS_MAC,
       MO(NAV1),  KC_A,      KC_O,     KC_E,         KC_U,     KC_I,
       MO(SHFT),  NO_APOS,   KC_Q,     KC_J,         KC_K,     KC_X,     KC_EXLM,
       MO(NUMB),  KC_LSFT,   KC_LCTL,  KC_LALT,      KC_LGUI,
                                                               KC_NO,    KC_NO,
                                                                         KC_NO,
                                                     KC_SPC,   KC_TAB,   KC_NO,
       // right hand
       NO_AMPR,    NO_EQL,   NO_RPRN,  NO_RCBR_MAC,  NO_RBRC,  KC_HASH,  NO_ACUT,
       NO_SLSH,    KC_F,     KC_G,     KC_C,         KC_R,     KC_L,     MO(NAV2),
                   KC_D,     KC_H,     KC_T,         KC_N,     KC_S,     MO(NAV1),
       NO_QUES,    KC_B,     KC_M,     KC_W,         KC_V,     KC_Z,     MO(SHFT),
                             NO_SCLN,  NO_AA,        NO_AE,    NO_OSLH,  MO(NUMB),
       KC_NO,      KC_NO,
       KC_NO,
       KC_DELT,    KC_BSPC,  KC_ENT
),

/* Keymap 1: Shifted layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ..   |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   *  |      |    `   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   _  |   <  |   >  |   P  |   Y  |   ~  |           |   |  |   F  |   G  |   C  |   R  |   L  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |        |
 * |--------+------+------+------+------+------|   ^  |           |   +  |------+------+------+------+------+--------|
 * |   ..   |   "  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |   ..   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  ..  |  ..  |  ..  |  ..  |                                       |   :  |   Å  |   Ä  |   Ö  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  ..  |  ..  |------|       |------|  ..  | S(..)|
 *                                 |      |      |      |       |  ..  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SHFT] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,      KC_1,     KC_2,         KC_3,         KC_4,     KC_5,        KC_6,
       KC_NO,        NO_UNDS,  NO_LESS_MAC,  NO_GRTR_MAC,  S(KC_P),  S(KC_Y),     NO_TILD,
       KC_NO,        S(KC_A),  S(KC_O),      S(KC_E),      S(KC_U),  S(KC_I),
       KC_TRNS,      NO_QUO2,  S(KC_Q),      S(KC_J),      S(KC_K),  S(KC_X),     NO_CIRC,
       KC_NO,        KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,
                                                                     KC_NO,       KC_NO,
                                                                                  KC_NO,
                                                           KC_TRNS,  KC_TRNS,     KC_NO,
       // right hand
       KC_7,         KC_8,     KC_9,         KC_0,         NO_ASTR,  KC_NO,       NO_GRV,
       NO_PIPE_MAC,  S(KC_F),  S(KC_G),      S(KC_C),      S(KC_R),  S(KC_L),     KC_NO,
                     S(KC_D),  S(KC_H),      S(KC_T),      S(KC_N),  S(KC_S),     KC_NO,
       NO_PLUS,      S(KC_B),  S(KC_M),      S(KC_W),      S(KC_V),  S(KC_Z),     KC_TRNS,
                               NO_COLN,      S(NO_AA),     S(NO_AE), S(NO_OSLH),  KC_NO,
       KC_NO,        KC_NO,
       KC_NO,
       KC_TRNS,      KC_TRNS,  S(KC_ENT)
),

/* Keymap 2: Navigation Layer 1
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Ctrl-§ | Ctl1 | Ctl2 | Ctl3 | Ctl4 | Ctl5 | Ctl6 |           | Ctl7 | Ctl8 | Ctl9 |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Cut  | Copy | Paste| MsUp |      |      |      |           |      |      | Home |  UP  |  End |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   ..   |      |MsLeft|MsDown|MsRght|      |------|           |------| Alt-L| LEFT | DOWN | RIGHT| Alt-R|   ..   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | LClk | RClk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VRSN | EPRM |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Shift|      |------|       |------|  CMD |  ALT |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV1] = LAYOUT_ergodox(
       // left hand
       LCTL(KC_NUBS),  LCTL(KC_1),     LCTL(KC_2),  LCTL(KC_3),  LCTL(KC_4),  LCTL(KC_5),     LCTL(KC_6),
       LGUI(KC_X),     LGUI(KC_C),     LGUI(KC_V),       KC_MS_U,     KC_NO,       KC_WH_U,        KC_NO,
       KC_TRNS,        KC_NO,          KC_MS_L,     KC_MS_D,     KC_MS_R,     KC_WH_D,
       KC_NO,          KC_NO,          KC_NO,       KC_NO,       KC_NO,       KC_NO,          KC_NO,
       KC_NO,          KC_NO,          KC_NO,       KC_BTN1,     KC_BTN2, 
                                                                              VRSN,           EPRM,
                                                                                              KC_NO,
                                                                 KC_LSFT,     KC_NO,          KC_NO,
       // right hand
       LCTL(KC_7),     LCTL(KC_8),     LCTL(KC_9),  KC_NO,       KC_NO,       KC_NO,          KC_NO,
       KC_NO,          KC_NO,          KC_HOME,     KC_UP,       KC_END,      KC_NO,          KC_NO,
                       LALT(KC_LEFT),  KC_LEFT,     KC_DOWN,     KC_RGHT,     LALT(KC_RGHT),  KC_TRNS,
       KC_NO,          KC_NO,          KC_NO,       KC_NO,       KC_NO,       KC_NO,          KC_NO,
                                       KC_NO,       KC_NO,       KC_NO,       KC_NO,          KC_NO,
       KC_NO,          KC_NO,
       KC_NO,
       KC_NO,          KC_RGUI,        KC_RALT
),

/* Keymap 3: Navigation Layer 2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Cmd-0 | Cmd1 | Cmd2 | Cmd3 | Cmd4 | Cmd5 | Cmd6 |           | Cmd7 | Cmd8 | Cmd9 |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ..   |      |      |      |      |      |      |           |      |      |      | CmdUp|      |      |   ..   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |CmdLft|CmdDwn|CmdRgh|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV2] = LAYOUT_ergodox(
       // left hand
       LGUI(KC_0),  LGUI(KC_1),  LGUI(KC_2),     LGUI(KC_3),     LGUI(KC_4),     LGUI(KC_5),     LGUI(KC_6),
       KC_TRNS,     KC_NO,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
       KC_NO,       KC_NO,       KC_NO,          KC_NO,          KC_NO,          KC_NO,
       KC_NO,       KC_NO,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
       KC_NO,       KC_NO,       KC_NO,          KC_NO,          KC_NO, 
                                                                                 KC_NO,          KC_NO,
                                                                                                 KC_NO,
                                                                 KC_NO,          KC_NO,          KC_NO,
       // right hand
       LGUI(KC_7),  LGUI(KC_8),  LGUI(KC_9),     KC_NO,          KC_NO,          KC_NO,          KC_NO,
       KC_NO,       KC_NO,       KC_NO,          LGUI(KC_UP),    KC_NO,          KC_NO,          KC_TRNS,
                    KC_NO,       LGUI(KC_LEFT),  LGUI(KC_DOWN),  LGUI(KC_RGHT),  KC_NO,          KC_NO,
       KC_NO,       KC_NO,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
       KC_NO,       KC_NO,
       KC_NO,
       KC_NO,       KC_NO,        KC_NO
),

/* Keymap 3: Number and Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |      |      |      |   /  |   *  |      |  Lock  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |           |      |      |   7  |   8  |   9  |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |   0  |   ,  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  ..  |  ..  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMB] = LAYOUT_ergodox(
       // left hand
       KC_NO,    KC_F1,    KC_F2,  KC_F3,    KC_F4,    KC_F5,    KC_F6,
       KC_NO,    KC_F7,    KC_F8,  KC_F9,    KC_F10,   KC_F11,   KC_F12,
       KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,    KC_NO,
       KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_TRNS,  KC_NO,    KC_NO,  KC_NO,    KC_NO, 
                                                       KC_NO,    KC_NO,
                                                                 KC_NO,
                                             KC_NO,    KC_NO,    KC_NO,
       // right hand
       KC_NO,    KC_NO,    KC_NO,  NO_SLSH,  NO_ASTR,  KC_NO,    LGUI(LCTL(KC_Q)),
       KC_NO,    KC_NO,    KC_7,   KC_8,     KC_9,     NO_MINS,  KC_NO,
                 KC_NO,    KC_4,   KC_5,     KC_6,     NO_PLUS,  KC_NO,
       KC_NO,    KC_NO,    KC_1,   KC_2,     KC_3,     KC_NO,    KC_NO,
                           KC_NO,  KC_0,     KC_COMM,  KC_NO,    KC_TRNS,
       KC_NO,    KC_NO,
       KC_NO,
       KC_NO,    KC_TRNS,  KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SHFT)                // FN1 - Momentary Layer 1 (Symbols)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case 0:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            break;
    }

    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
        case NUMB:
            ergodox_right_led_1_on();
            break;
        default:
            break;
    }
};
