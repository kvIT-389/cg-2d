#ifndef UPDATE_H_INCLUDED_
#define UPDATE_H_INCLUDED_


#include <stdint.h>


extern const uint32_t update_delay;


/* Main update function */
void update(int value);

/* Run main update loop */
void runUpdateLoop(void);


#endif  /* UPDATE_H_INCLUDED_ */
