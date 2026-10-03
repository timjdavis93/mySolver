#include "horner.h"
#include <stdio.h>

// NOTE: Array is passed <C_N> <C_N-1> <C_N-2> .... <C_0>
double horner(size_t length, double arr[], double x) {

	double s = arr[0];
	for (size_t i = 1; i < length ; i++) {
		s = s * x + arr[i];
	}

	return s;
}
