#include QMK_KEYBOARD_H

#define _PFK_NUM_KEYS 23
#define _BASE_LAYER 0
#define _SYM_LAYER 1
#define _NUM_LAYER 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT_pfk(
        /* LEFT */
        KC_ESC , KC_Q , KC_W    , KC_E     , KC_R      , KC_T           ,
        KC_TAB , KC_A , KC_S    , KC_D     , KC_F      , KC_G           ,
                 KC_Z , KC_X    , KC_C     , KC_V      , KC_B           ,
                        KC_LALT , KC_LCTRL , KC_LSHIFT , TT(_SYM_LAYER) ,
        /* RIGHT */
        KC_Y           , KC_U      , KC_I     , KC_O     , KC_P     , KC_BSPACE ,
        KC_H           , KC_J      , KC_K     , KC_L     , KC_ENTER , KC_NO     ,
        KC_N           , KC_M      , KC_SPC   , KC_COMMA , KC_DOT   ,
        TT(_NUM_LAYER) , KC_RSHIFT , KC_RCTRL , KC_RALT  ,
        /* padding */
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    /*
         ! @ # $ %   ^ & * + |
       ' " { [ ( <   > ) ] } : ;
         ~ - = _ `   \ / ? , .
     */
    [_SYM_LAYER] = LAYOUT_pfk(
        /* LEFT */
        RESET    , LSFT(KC_1)     , LSFT(KC_2)        , LSFT(KC_3)  , LSFT(KC_4)     , LSFT(KC_5)     ,
        KC_QUOTE , LSFT(KC_QUOTE) , LSFT(KC_LBRACKET) , KC_LBRACKET , LSFT(KC_9)     , LSFT(KC_COMMA) ,
                   LSFT(KC_GRAVE) , KC_MINUS          , KC_EQUAL    , LSFT(KC_MINUS) , KC_GRAVE       ,
                                    KC_TRNS           , KC_TRNS     , KC_TRNS        , KC_TRNS        ,
        /* RIGHT */
        LSFT(KC_6)   , LSFT(KC_7) , LSFT(KC_8)     , LSFT(KC_EQUAL)    , LSFT(KC_BSLASH) , KC_DELETE ,
        LSFT(KC_DOT) , LSFT(KC_0) , KC_RBRACKET    , LSFT(KC_RBRACKET) , LSFT(KC_SCOLON) , KC_SCOLON ,
        KC_BSLASH    , KC_SLASH   , LSFT(KC_SLASH) , KC_COMMA          , KC_DOT          ,
        KC_TRNS      , KC_TRNS    , KC_TRNS        , KC_TRNS           ,
        /* padding */
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_NUM_LAYER] = LAYOUT_pfk(
        /* LEFT */
        KC_F1    , KC_F2         , KC_F3   , KC_F4   , KC_F5     , KC_F6   ,
        KC_PAUSE , KC_SCROLLLOCK , KC_HOME , KC_PGUP , KC_PGDOWN , KC_END  ,
                   KC_1          , KC_2    , KC_3    , KC_4      , KC_5    ,
                                   KC_TRNS , KC_TRNS , KC_TRNS   , KC_TRNS ,
        /* RIGHT */
        KC_F7   , KC_F8   , KC_F9   , KC_F10   , KC_F11    , KC_F12     ,
        KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_INSERT , KC_PSCREEN ,
        KC_6    , KC_7    , KC_8    , KC_9     , KC_0      ,
        KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  ,
        /* padding */
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
};

extern uint8_t matrix_num_keys;
uint8_t matrix_num_keys = _PFK_NUM_KEYS;
