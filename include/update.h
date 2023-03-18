#ifndef UPDATE_H_INCLUDED_
#define UPDATE_H_INCLUDED_


#include <types.h>


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
