#include <ap_int.h>

void alarma(bool SW12, bool SW13, bool SW14, bool SW15, // code
			bool SW0, bool SW1, bool SW2, // windows
			bool SW6, bool SW7, // movement
			ap_uint<8> code7segment[2], ap_uint<4> anodes[2]) {

	#pragma HLS INTERFACE mode=ap_none port=SW12
	#pragma HLS INTERFACE mode=ap_none port=SW13
	#pragma HLS INTERFACE mode=ap_none port=SW14
	#pragma HLS INTERFACE mode=ap_none port=SW15
	#pragma HLS INTERFACE mode=ap_none port=SW0
	#pragma HLS INTERFACE mode=ap_none port=SW1
	#pragma HLS INTERFACE mode=ap_none port=SW2
	#pragma HLS INTERFACE mode=ap_none port=SW6
	#pragma HLS INTERFACE mode=ap_none port=SW7

	#pragma HLS INTERFACE mode=ap_ctrl_none port=return

	bool ON = false;
	if (SW12 && SW13 && !SW14 && SW15) {
		for (int i = 0; i < 2; i++) {
			code7segment[i] = 0b11000000;
		}
		ON = true;
	}

	if (ON) {
		if (SW0 && !(SW1 || SW2 || SW6 || SW7)) {
			code7segment[0] = 0b11111001; // 1
			code7segment[1] = 0b10010010; // S
		} else if (SW1 && !(SW0 || SW2 || SW6 || SW7)) {
			code7segment[0] = 0b10100100; // 2
			code7segment[1] = 0b10010010; // S
		} else if (SW2 && !(SW0 || SW1 || SW6 || SW7)) {
			code7segment[0] = 0b10110000; // 3
			code7segment[1] = 0b10010010; // S
		} else if (SW6 && !(SW0 || SW1 || SW2 || SW7)) {
			code7segment[0] = 0b11111001; // 1
		} else if (SW7 && !(SW0 || SW1 || SW6 || SW2)) {
			code7segment[0] = 0b10100100; // 2
		}
	}

	if (!ON) {
		code7segment[0] = 0b10111111; // -
		code7segment[1] = 0b10111111; // -
	}
	anodes[0] = 0b1110;
	anodes[1] = 0b1101;
}
