#ifndef CALLBACK_H_INCLUDED_
#define CALLBACK_H_INCLUDED_


#include <stdint.h>


typedef int32_t _width_t;
typedef int32_t _height_t;

typedef int32_t _mouse_button_t;
typedef int32_t _mouse_button_state_t;

typedef uint8_t _key_t;
typedef int32_t _special_key_t;


/* Sets defined callback functions */
void initCallbacks(void);

/* Current window display callback function */
void display(void);

/* Current window reshape callback */
void reshape(_width_t width, _height_t height);

/* Mouse callback function */
void mouse(
    _mouse_button_t button,
    _mouse_button_state_t state,
    int32_t x, int32_t y
);

/* Keyboard callback function */
void keyboard(_key_t key, int32_t x, int32_t y);

/* Special keyboard callback function */
void specialKeyboard(
    _special_key_t key,
    int32_t x, int32_t y
);


#endif  /* CALLBACK_H_INCLUDED_ */
