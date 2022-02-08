#include "test_semafor.h"
#include <iostream>

int main() {
	int status = 0; // test cu succes

	bool expected_ew[16] = {1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1};
	bool expected_ns[16] = {0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0};

	bool ew[16], ns[16];

	int stg = false, d = true, s = true, j = true;
	int k =0;
	for (int i = 0; i < 16; i++) {
		if (i < 8)
			stg = false;
		else
			stg = true;
		if (i % 4 == 0)
			d = !d;
		if (i % 2 == 0)
			s = !s;
		j = !j;
		topFunction(stg, d, s, j, &ew[k], &ns[k]);
		k++;
	}

	for (int i = 0; i < 16; i++) {
		if (expected_ew[i] != ew[i] || expected_ns[i] != ns[i]) {
			std::cout << "Eroare la " << i << " unde ew = " << ew[i] << " si expected_ew = " << expected_ew[i] <<
					" si ns = " << ns[i] << " si expected_ns = " << expected_ns[i] << '\n';
			status = -1;
			break;
		}
	}
	if (status == 0)
		std::cout << "SUCCES!\n";

	return status;
}
