/* ----------------------------------------------------------------------------
 * ergoDOX layout : Crickett (modified from QWERTY)
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // layout: layer 0: default
// unused
0,
// left hand
0,  0,  0,  0,     0,       0,      0,
0, _Q, _W, _E,    _R,      _T,      0,
0, _A, _S, _D,    _F,      _G,
0, _Z, _X, _C,    _V,      _B,   _del,
0,  0,  0,  0, _altL,
                            0,      0,
                   0,       0, _ctrlL,
                   1, _shiftL,  _guiL,
// right hand
        0,  0,       0,       0,       0,          0, 0,
        0, _Y,      _U,      _I,      _O,         _P, 0,
           _H,      _J,      _K,      _L, _semicolon, 0,
      _bs, _N,      _M,  _comma, _period,     _slash, 0,
                     2,       0,       0,          0, 0,
    0,      0,
 _tab,      0,      0,
 _esc, _space, _enter ),


	KB_MATRIX_LAYER(  // layout: layer 1: function and symbol keys
// unused
0,
// left hand
  0,           0,          0,          0,          0,       0,      0,
  0,      _grave,         _2,         _3,         _4,      _5,      0,
  0,     _add_kp,    _mul_kp,    _sub_kp,     _equal,   _dash,      
  0,          _1,         _2,         _3,         _4,      _5,      0,
  0,           0,          0,          0,          0,      
                           0, 0,
                       0,  0, 0,
                       1,  0, 0,
// right hand
           0,           0,          0,          0,         0,         0, 0,
           0,          _6,  _bracketL,  _bracketR, _bracketL, _bracketR, 0,
                       _1,         _9,         _0,    _quote,    _quote, 0,      
           0,          _6,         _7,         _8,        _9,        _0, 0,
                                    2,           0,        0,         0, 0,      
           0,          0,
      _grave,          0,  0,
  _backslash, _backslash, _7 ),


	KB_MATRIX_LAYER(  // layout: layer 2: keyboard functions
// unused
0,
// left hand
  0,        0,        0,      0,  0,  0,  0,
  0,     _F11,_     F12,  _mute,  0,  0,  0,
  0, _volumeD, _volumeD,      0,  0,  0,
  0,      _F1,      _F2,    _F3,_F4,_F5,  0,
  0,        0,        0,  0,  0,
		          0,  0,
		      0,  0,  0,
		      1,  0,  0,
// right hand
      0,       0,       0,       0,       0,   0,  0,
      0,   _home,  _pageD,  _pageU,    _end,   0,  0,
	       _arrowL, _arrowD, _arrowU, _arrowR,   0,  0,
      0,     _F6,     _F7,     _F8,     _F9,_F10,  0,
	                   2,  0,  0,   0,  0,
  0,  0,
  0,  0,  0,
  0,  0,  0 ),


	KB_MATRIX_LAYER(  // layout: layer 3: numpad
// unused
0,
// left hand
0,       0, 0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0, 0,
0, _insert, 0, 0, 0,
                     0, 0,
                  0, 0, 0,
                  0, 0, 0,
// right hand
3, 0,     3, _equal_kp, _div_kp,   _mul_kp, 0,
0, 0, _7_kp,     _8_kp,   _9_kp,   _sub_kp, 0,
   0, _4_kp,     _5_kp,   _6_kp,   _add_kp, 0,
0, 0, _1_kp,     _2_kp,   _3_kp, _enter_kp, 0,
          0,         0, _period, _enter_kp, 0,
0, 0,
0, 0,     0,
0, 0, _0_kp ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  ktog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // press: layer 0: default
// unused
NULL,
// left hand
NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
NULL, kprrel, kprrel, kprrel, kprrel, kprrel,
NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
NULL,   NULL,   NULL,   NULL, kprrel,
                                                NULL,   NULL,
                                        NULL,   NULL, kprrel,
                                      lpush1, s2kcap, kprrel,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
                kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
                        lpush2,   NULL,   NULL,   NULL,   NULL,
  NULL,   NULL,
kprrel,   NULL,   NULL,
kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // press: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,sshprre,sshprre,sshprre,sshprre,sshprre,   NULL,
   NULL, kprrel, kprrel, kprrel, kprrel,sshprre,
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
   NULL,   NULL,   NULL,   NULL, ktrans,
                                                   NULL,   NULL,
                                           NULL,   NULL, ktrans,
                                         lpush1, ktrans, ktrans,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,sshprre, kprrel, kprrel,sshprre,sshprre,   NULL,
               sshprre,sshprre,sshprre,sshprre, kprrel,   NULL,
          NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
                        lpush2,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
 kprrel,   NULL,    NULL,
 kprrel,sshprre, sshprre ),


	KB_MATRIX_LAYER(  // press: layer 2: keyboard functions
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL, kprrel, kprrel, kprrel,   NULL,   NULL,   NULL,
   NULL, kprrel, kprrel,   NULL,   NULL,   NULL,
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
   NULL,   NULL,   NULL,   NULL, ktrans,
                                                   NULL,   NULL,
                                           NULL,   NULL, ktrans,
                                         lpush1, ktrans, ktrans,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL, kprrel, kprrel, kprrel, kprrel,   NULL,   NULL,
                kprrel, kprrel, kprrel, kprrel,   NULL,   NULL,
          NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
                        lpush2,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // press: layer 3: numpad
// unused
NULL,
// left hand
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, kprrel, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
       slponum, ktrans,slponum, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                        ktrans, ktrans, kprrel, kprrel, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, kprrel ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // release: layer 0: default
// unused
NULL,
// left hand
NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
NULL, kprrel, kprrel, kprrel, kprrel, kprrel,
NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
NULL,   NULL,   NULL,   NULL, kprrel,
                                                NULL,   NULL,
                                        NULL,   NULL, kprrel,
                                       lpop1, s2kcap, kprrel,
// right hand
         NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
         NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
               kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
       kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
                        lpop2,   NULL,   NULL,   NULL,   NULL,
  NULL,   NULL,
kprrel,   NULL,   NULL,
kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // release: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,sshprre,sshprre,sshprre,sshprre,sshprre,   NULL,
   NULL, kprrel, kprrel, kprrel, kprrel,sshprre,
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
   NULL,   NULL,   NULL,   NULL, ktrans,
                                                   NULL,   NULL,
                                           NULL,   NULL, ktrans,
                                          lpop1, ktrans, ktrans,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,sshprre, kprrel, kprrel,sshprre,sshprre,   NULL,
               sshprre,sshprre,sshprre,sshprre, kprrel,   NULL,
          NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
                         lpop2,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
 kprrel,   NULL,    NULL,
 kprrel,sshprre, sshprre ),


	KB_MATRIX_LAYER(  // release: layer 2: keyboard functions
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL, kprrel, kprrel, kprrel,   NULL,   NULL,   NULL,
   NULL, kprrel, kprrel,   NULL,   NULL,   NULL,
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
   NULL,   NULL,   NULL,   NULL, ktrans,
                                                   NULL,   NULL,
                                           NULL,   NULL, ktrans,
                                          lpop1, ktrans, ktrans,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL, kprrel, kprrel, kprrel, kprrel,   NULL,   NULL,
                kprrel, kprrel, kprrel, kprrel,   NULL,   NULL,
          NULL, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
                         lpop2,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // release: layer 3: numpad
// unused
NULL,
// left hand
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, kprrel, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
          NULL, ktrans,   NULL, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                        ktrans, ktrans, kprrel, kprrel, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, kprrel ),


	KB_MATRIX_LAYER(  // release: layer 3: nothing (just making sure unused
			  // functions don't get compiled out)
// unused
NULL,
// other
 kprrel, lpush8,  lpop8,   NULL,   NULL,   NULL,   NULL,   NULL,
   ktog, lpush9,  lpop9,   NULL,   NULL,   NULL,   NULL,   NULL,
 ktrans,lpush10, lpop10,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush1,  lpop1,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush2,  lpop2, dbtldr,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush3,  lpop3,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush4,  lpop4, s2kcap,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush5,  lpop5,slpunum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush6,  lpop6,slponum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush7,  lpop7,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL )

};

