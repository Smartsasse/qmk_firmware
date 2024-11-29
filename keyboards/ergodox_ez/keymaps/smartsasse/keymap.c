#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_swedish_pro_mac_ansi.h"

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
 *   |L-NUMB| Shift| Ctrl |  Alt |  Cmd |                                       |   ;  |   å  |   ä  |   ö  |L-NUMB|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |   §  |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|  Tab |------|       |------| Back-| Enter|
 *                                 |      |      | ^F4  |       |  Del | space|      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
       // left hand
       KC_ESC,              SE_AT,    SE_LBRC,  SE_LCBR,      SE_LPRN,  SE_DLR,   KC_PERC,
       LM(NAV2, MOD_LGUI),  SE_MINS,  KC_COMM,  KC_DOT,       KC_P,     KC_Y,     SE_BSLS,
       MO(NAV1),            KC_A,     KC_O,     KC_E,         KC_U,     KC_I,
       MO(SHFT),            SE_QUOT,  KC_Q,     KC_J,         KC_K,     KC_X,     KC_EXLM,
       MO(NUMB),            KC_LSFT,  KC_LCTL,  KC_LALT,      KC_LGUI,
                                                                        KC_NO,    KC_NO,
                                                                                  KC_NO,
                                                              KC_SPC,   KC_TAB,   LCTL(KC_F4),
       // right hand
       SE_AMPR,             SE_EQL,   SE_RPRN,  SE_RCBR,      SE_RBRC,  KC_HASH,  SE_ACUT,
       SE_SLSH,             KC_F,     KC_G,     KC_C,         KC_R,     KC_L,     LM(NAV2, MOD_LGUI),
                            KC_D,     KC_H,     KC_T,         KC_N,     KC_S,     MO(NAV1),
       SE_QUES,             KC_B,     KC_M,     KC_W,         KC_V,     KC_Z,     MO(SHFT),
                                      SE_SCLN,  SE_ARNG,      SE_ADIA,  SE_ODIA,  MO(NUMB),
       KC_NUBS,             KC_NO,
       KC_NO,
       KC_DEL,              KC_BSPC,  KC_ENT
),

/* Keymap 1: Shifted layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ..   |      |      |      |      |      |      |           |      |      |      |      |   *  |      |    `   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | S(Cmd) |   _  |   <  |   >  |   P  |   Y  |   ~  |           |   |  |   F  |   G  |   C  |   R  |   L  | S(Cmd) |
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
 *                                 | S(..)| S(..)|------|       |------|  ..  | S(..)|
 *                                 |      |      |      |       |  ..  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SHFT] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,      KC_NO,    KC_NO,        KC_NO,        KC_NO,      KC_NO,       KC_NO,
       S(KC_LGUI),   SE_UNDS,  SE_LABK,      SE_RABK,      S(KC_P),    S(KC_Y),     SE_TILD,
       KC_NO,        S(KC_A),  S(KC_O),      S(KC_E),      S(KC_U),    S(KC_I),
       KC_TRNS,      SE_DQUO,  S(KC_Q),      S(KC_J),      S(KC_K),    S(KC_X),     SE_CIRC,
       KC_NO,        KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,
                                                                       KC_NO,       KC_NO,
                                                                                    KC_NO,
                                                           S(KC_SPC),  S(KC_TAB),   KC_NO,
       // right hand
       KC_NO,        KC_NO,    KC_NO,        KC_NO,        SE_ASTR,    KC_NO,       SE_GRV,
       SE_PIPE,      S(KC_F),  S(KC_G),      S(KC_C),      S(KC_R),    S(KC_L),     S(KC_LGUI),
                     S(KC_D),  S(KC_H),      S(KC_T),      S(KC_N),    S(KC_S),     KC_NO,
       SE_PLUS,      S(KC_B),  S(KC_M),      S(KC_W),      S(KC_V),    S(KC_Z),     KC_TRNS,
                               SE_COLN,      S(SE_ARNG),   S(SE_ADIA), S(SE_ODIA),  KC_NO,
       KC_NO,        KC_NO,
       KC_NO,
       KC_TRNS,      KC_TRNS,  S(KC_ENT)
),

/* Keymap 2: Navigation Layer 1
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Ctrl-§ | Ctl1 | Ctl2 | Ctl3 | Ctl4 | Ctl5 | Ctl6 |           | Ctl7 | Ctl8 | Ctl9 |      |Script|      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Cut  | Copy | Paste| MsUp |      |MsWhlU|      |           |      |      | Home |  UP  |  End |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   ..   |      |MsLeft|MsDown|MsRght|MsWhlD|------|           |------| Alt-L| LEFT | DOWN | RIGHT| Alt-R|   ..   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  ..  |  ..  |  ..  |  ..  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VRSN | EPRM |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Shift|      |------|       |------|  CMD |  ALT |
 *                                 |      |      | LClk |       | RClk |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV1] = LAYOUT_ergodox(
       // left hand
       LCTL(KC_NUBS),  LCTL(KC_1),     LCTL(KC_2),    LCTL(KC_3),  LCTL(KC_4),       LCTL(KC_5),        LCTL(KC_6),
       LGUI(KC_X),     LGUI(KC_C),     LGUI(KC_V),    KC_MS_U,     KC_NO,            KC_WH_U,           KC_NO,
       KC_TRNS,        KC_NO,          KC_MS_L,       KC_MS_D,     KC_MS_R,          KC_WH_D,
       KC_NO,          KC_NO,          KC_NO,         KC_NO,       KC_NO,            KC_NO,             KC_NO,
       KC_NO,          KC_TRNS,        KC_TRNS,       KC_TRNS,     KC_TRNS, 
                                                                                     VRSN,              EPRM,
                                                                                                     KC_NO,
                                                                   KC_LSFT,          KC_NO,             KC_BTN1,
       // right hand
       LCTL(KC_7),     LCTL(KC_8),     LCTL(KC_9),    KC_NO,       LCTL(S(KC_NUBS)), KC_NO,           KC_NO,
       KC_NO,          KC_NO,          LGUI(KC_LEFT), KC_UP,       LGUI(KC_RGHT),    KC_NO,             KC_NO,
                       LALT(KC_LEFT),  KC_LEFT,       KC_DOWN,     KC_RGHT,          LALT(KC_RGHT),     KC_TRNS,
       KC_NO,          KC_NO,          KC_NO,         KC_NO,       KC_NO,            KC_NO,             KC_NO,
                                       KC_NO,         KC_NO,       KC_NO,            KC_NO,             KC_NO,
       KC_NO,          KC_NO,
       KC_NO,
       KC_BTN2,        KC_RGUI,        KC_RALT
),

/* Keymap 3: Navigation Layer 2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Cmd-0 | Cmd1 | Cmd2 | Cmd3 | Cmd4 | Cmd5 | Cmd6 |           | Cmd7 | Cmd8 | Cmd9 |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ..   | Cmd--| Cmd-,| Cmd-.| Cmd-P| Cmd-Y|      |           |      | Cmd-F| Cmd-G| Cmd-C| Cmd-R| Cmd-L|   ..   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Cmd-A| Cmd-O| Cmd-E| Cmd-U| Cmd-I|------|           |------| Cmd-D| Cmd-H| Cmd-T| Cmd-N| Cmd-S|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | S(Cmd) |      | Cmd-Q| Cmd-J| Cmd-K|      |      |           |      | Cmd-B| Cmd-M| Cmd-W| Cmd-V| Cmd-Z| S(Cmd) |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  ..  |  ..  |  ..  |  ..  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Cmd- |      |------|       |------| Cmd- | Cmd- |
 *                                 | Space|      |      |       |Cm-del| Bspc | Enter|
 *                                 `--------------------'       `--------------------'
 */
[NAV2] = LAYOUT_ergodox(
       // left hand
       KC_0,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,
       KC_TRNS,  SE_MINS,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_NO,
       KC_NO,    KC_A,     KC_O,     KC_E,     KC_U,     KC_I,
       KC_LSFT,  KC_NO,    KC_Q,     KC_J,     KC_K,     KC_X,     KC_NO,
       KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                         KC_NO,    KC_NO,
                                                                   KC_NO,
                                               KC_SPC,   KC_NO,    KC_NO,
       // right hand
       KC_7,     KC_8,     KC_9,     KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_NO,    KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_TRNS,
                 KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_NO,
       KC_NO,    KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_LSFT,
                           KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_NO,    KC_NO,
       KC_NO,
       KC_DEL,  KC_BSPC,  KC_ENT
),

/* Keymap 3: Number and Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |      |      |      |   /  |   *  |      |  Lock  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |           |      |      |   7  |   8  |   9  |  -   | ScrShot|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |  +   | ScrShot|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  | Enter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  ..  |  ..  |  ..  |  ..  |  ..  |                                       |      |   0  |   ,  |      |  ..  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   .. |  ..  |------|       |------|  ..  |  ..  |
 *                                 |      |      |      |       |  ..  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMB] = LAYOUT_ergodox(
       // left hand
       KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
       KC_NO,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
                                                         KC_NO,    KC_NO,
                                                                   KC_NO,
                                               KC_TRNS,  KC_TRNS,  KC_NO,
       // right hand
       KC_NO,    KC_NO,    KC_NO,    SE_SLSH,  SE_ASTR,  KC_NO,    LGUI(LCTL(KC_Q)),
       KC_NO,    KC_NO,    KC_7,     KC_8,     KC_9,     SE_MINS,  LGUI(LCTL(S(KC_4))),
                 KC_NO,    KC_4,     KC_5,     KC_6,     SE_PLUS,  LGUI(S(KC_4)),
       KC_NO,    KC_NO,    KC_1,     KC_2,     KC_3,     KC_ENT,   KC_NO,
                           KC_NO,    KC_0,     KC_COMM,  KC_NO,    KC_TRNS,
       KC_NO,    KC_NO,
       KC_NO,
       KC_TRNS,  KC_TRNS,  KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SHFT)                // FN1 - Momentary Layer 1 (Symbols)
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

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = get_highest_layer(layer_state);

  ergodox_board_led_off();
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
