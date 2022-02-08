#include "alarma_test.h"
#include <iostream>

int main() {
	ap_uint<8> code7segment[2];
	ap_uint<4> anodes[2];
	std::cout << "===================== Test1 =====================" << '\n';
	alarma(true, true, false, true,
				true, false, false,
				false, false,
				code7segment, anodes);
	unsigned int golden_code7segment[2] = {
									0b11111001,
									0b10010010 };
	for (int i = 1; i >= 0; i--) {
		if (golden_code7segment[i] != code7segment[i]) {
			std::cout << "The code is " << code7segment[i] << " when it should be " << golden_code7segment[i] << '\n';
			return -1;
		}
	}
	std::cout << "Test 1 (window 1 true) PASSED" << '\n';

	std::cout << "===================== Test2 =====================" << '\n';

	alarma(true, false, false, true,
				true, false, false,
				false, false,
				code7segment, anodes);

	golden_code7segment[0] = 0b10111111;
	golden_code7segment[1] = 0b10111111;

	for (int i = 1; i >= 0; i--) {
		if (golden_code7segment[i] != code7segment[i]) {
			std::cout << "The code is " << code7segment[i] << " when it should be " << golden_code7segment[i] << '\n';
			return -1;
		}
	}
	std::cout << "Test 2 (not open) PASSED" << '\n';

	std::cout << "===================== Test3 =====================" << '\n';

	alarma(true, true, false, true,
				true, true, false,
				false, false,
				code7segment, anodes);

	golden_code7segment[0] = 0b11000000;
	golden_code7segment[1] = 0b11000000;

	for (int i = 1; i >= 0; i--) {
		if (golden_code7segment[i] != code7segment[i]) {
			std::cout << "The code is " << code7segment[i] << " when it should be " << golden_code7segment[i] << '\n';
			return -1;
		}
	}
	std::cout << "Test 3 (two sensors open) PASSED" << '\n';

	std::cout << "===================== Test4 =====================" << '\n';
	alarma(true, true, false, true,
				false, true, false,
				false, false,
				code7segment, anodes);

	golden_code7segment[0] = 0b10100100;
	golden_code7segment[1] = 0b10010010;

	for (int i = 1; i >= 0; i--) {
		if (golden_code7segment[i] != code7segment[i]) {
			std::cout << "The code is " << code7segment[i] << " when it should be " << golden_code7segment[i] << '\n';
			return -1;
		}
	}
	std::cout << "Test 4 (second sensor open) PASSED" << '\n';

	std::cout << "===================== Test5 =====================" << '\n';

	alarma(true, true, false, true,
				false, false, false,
				false, true,
				code7segment, anodes);

	golden_code7segment[0] = 0b10100100;
	golden_code7segment[1] = 0b11000000;

	for (int i = 1; i >= 0; i--) {
		if (golden_code7segment[i] != code7segment[i]) {
			std::cout << "The code is " << code7segment[i] << " when it should be " << golden_code7segment[i] << '\n';
			return -1;
		}
	}
	std::cout << "Test 5 (movement 2) PASSED" << '\n';
	return 0;
}
