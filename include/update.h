#ifndef UPDATE_H_INCLUDED_
#define UPDATE_H_INCLUDED_


#include <stdint.h>


typedef uint32_t _time_t;


extern const _time_t update_delay;


/**
 * Main update function.
 */
void update(int value);

/**
 * Run main update loop.
 */
void runUpdateLoop(void);


#endif  /* UPDATE_H_INCLUDED_ */
