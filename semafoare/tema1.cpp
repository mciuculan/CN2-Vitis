bool reg1(bool stg, bool d, bool s, bool j) {
	if (stg == true && d == true) {
		return true;
	}
	return false;
}

bool reg2(bool stg, bool d, bool s, bool j) {
	if (stg == true && d == false) {
		if (s == false) {
			return true;
		} else if (s == true && j == false) {
			return true;
		}
	} else if (stg == false && d == true) {
		if (s == false) {
			return true;
		} else if (s == true && j == false) {
			return true;
		}
	}
	return false;
}

bool reg3(bool stg, bool d, bool s, bool j) {
	if (s == true && j == true) {
		if (stg == false || (stg == true && d == false)) {
			return true;
		}
	}
	return false;
}

bool reg4(bool stg, bool d, bool s, bool j) {
	if (stg == false && d == false) {
		if ((s == false && j == true) || (s == true && j == false)) {
			return true;
		}
	}
	return false;
}

bool reg5(bool stg, bool d, bool s, bool j) {
	if (stg == false && d == false && s == false && j == false) {
		return true;
	}
	return false;
}

void topFunction(bool stg, bool d, bool s, bool j, bool *ew, bool *ns) {
	#pragma HLS INTERFACE mode=ap_none port=stg
	#pragma HLS INTERFACE mode=ap_none port=d
	#pragma HLS INTERFACE mode=ap_none port=s
	#pragma HLS INTERFACE mode=ap_none port=j

	if (reg1(stg, d, s, j) == true ||  reg2(stg, d, s, j) == true || reg5(stg, d, s, j) == true) {
		*ew = true;
		*ns = false;
	} else {
		*ew = false;
		*ns = true;
	}
}
