/*
 * trace.h
 *
 *  Created on: 2020. 2. 11.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_REACTOR_TRACE_H_
#define OPEN_REACTOR_REACTOR_TRACE_H_

#include <iostream>

#ifndef reactor_trace
#define reactor_trace std::cout << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << ":" << ": "
#endif

#endif /* OPEN_REACTOR_REACTOR_TRACE_H_ */
