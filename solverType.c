#include "solverType.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

double findY(char *problemType, size_t length, double args[], double x);

double BiSec(char *problemType, size_t length, double args[], double boundsA, double boundsB);
double FalsePos(char *problemType, size_t length, double args[], double boundsA, double boundsB);
double Newton1(char *problemType, size_t length, double args[], double boundsA, double boundsB);
double Newton2(char *problemType, size_t length, double args[], double boundsA, double boundsB);
double BracketNewton1(char *problemType, size_t length, double args[], double boundsA, double boundsB);
double BracketNewton2(char *problemType, size_t length, double args[], double boundsA, double boundsB);

double horner(size_t length, double arr[], double x) {

	double s = arr[0];
	for (size_t i = 1; i < length ; i++) {
		s = s * x + arr[i];
	}

	return s;
}

double findY(char *problemType, size_t length, double args[], double x){
	double y;
	if (strcmp("POLY", problemType) == 0) {
		y = horner(length, args, x);
	} else if (strcmp("COS", problemType) == 0) {
		y = cos(x);
	} else if (strcmp("SIN", problemType) == 0) {
		y = sin(x);
	} else if (strcmp("TAN", problemType) == 0) {
		y = tan(x);
	} else if (strcmp("EXP", problemType) == 0) {
		y = exp(x);
	} else if (strcmp("LOG", problemType) == 0) {
		y = log(x);
	}

	return y;
}
