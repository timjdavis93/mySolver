#include "solverType.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double findY(char *problemType, size_t length, double args[], double x);

// NOTE: Cant use pi this way unless I calculate it for each func
// static const double pi = acos(-1);
static const double pi = M_PI;

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
		y = horner(length, args, x); // NOTE: [-inf, inf]

	} else if (strcmp("COS", problemType) == 0) {
		if (0 <= x && x <= pi ) {
			y = cos(x);
		} else {
			printf("X is Out of Bounds ERROR\n");
			printf("COS: X: %g\n", x);
			return 0;
		}

	} else if (strcmp("SIN", problemType) == 0) {
		if (-1 * pi / 2 <= x && x <= pi / 2 ) {
			y = sin(x);
		} else {
			printf("X is Out of Bounds ERROR\n");
			printf("SIN: X: %g\n", x);
			return 0;
		}

	} else if (strcmp("TAN", problemType) == 0) {
		if (-1 * pi / 2 <= x && x <= pi / 2 ) {
			y = tan(x);
		} else {
			printf("X is Out of Bounds ERROR\n");
			printf("SIN: X: %g\n", x);
			return 0;
		}

	} else if (strcmp("EXP", problemType) == 0) {
		y = exp(x); // NOTE: [-inf, inf]

	} else if (strcmp("LOG", problemType) == 0) {
		if ( 0 < x ) {
			y = log(x);
		} else {
			printf("X is Out of Bounds ERROR\n");
			printf("Log: X: %g\n", x);
			return 0;
		}
	}

	return y;
}
