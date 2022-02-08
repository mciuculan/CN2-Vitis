#ifndef __alarma_test_h__
#define __alarma_test_h__

#include <ap_int.h>

void alarma(bool SW12, bool SW13, bool SW14, bool SW15, // code
			bool SW0, bool SW1, bool SW2, // windows
			bool SW6, bool SW7, // movement
			ap_uint<8> code7segment[3], ap_uint<4> anodes[3]);

#endif
