#include <stdio.h>
#include <string.h>
#include "problemType.h"
#include "solverType.h"
#include "horner.h"

void printUsage(void);

// ./mysolver [problem type] [solver type] [arguements]
int main(int argc, char *argv[]) {

	size_t lengthOfCoefficients = 17;

	if (argc < 4) {
		printf("Not enough arguements given\n");
		printUsage();
	return 0;
	} else if (argc > 20) {
		printf("Too many arguements: Max: %d, Max Coefficients: %zu", 20, lengthOfCoefficients);
		return 0;
	}

	double output[lengthOfCoefficients];
	memset(output, 0, sizeof(output));

	char *problemType = argv[1];
	char *solverType = argv[2];
	int coefficients[lengthOfCoefficients];
	double newPoly[lengthOfCoefficients];
	
	if (argc > 20) {
		printf("Too many Arguements to handle");
		return 0;
	}

	for (int i = 3; i < argc; i++){
		poly[i-3] = (int)argv[i]; // TODO: make sure this is a valid cast
	}
	
	// TODO: I think it may be easiest to turn them all into poly then handle with the solver,
	if (strcmp("POLY", problemType)){
		memcpy(newPoly, coefficients, lengthOfCoefficients * sizeof(double));
	} else if (strcmp("COS", problemType)) {
		cosToPoly(coefficients);
	} else if (strcmp("SIN", problemType)) {
		sinToPoly(coefficients);
	} else if (strcmp("TAN", problemType)) {
		tanToPoly(coefficients);
	} else if (strcmp("EXP", problemType)) {
		tanToPoly(coefficients);
	} else if (strcmp("LOG", problemType)) {
		logToPoly(coefficients);
	} else { 
		printf("Error: Not a known Problem Type: \n");
		printf("<POLY> <COS> <SIN> <TAN> <EXP> <LOG>\n");
	}

	
	// TODO: each of these might look something like output = BiSec(newPolyArray) 
	if (strcmp("BiSec", solverType)){
		
	} else if (strcmp("FalsePos", solverType)){
	return 0;
	} else if (strcmp("Newton1", solverType)){
	return 0;
	} else if (strcmp("Newton2", solverType)){
	return 0;
	} else if (strcmp("Bracket-Newton1", solverType)){
	return 0;
	} else if (strcmp("Bracket-Newton2", solverType)){
	return 0;
	} else {
	printf("Error: Not a known Solver Type: \n");
	printf("<BiSec> <FalsePos> <Newton1> <Newton2> <Bracket-Newton1> <Bracket-Newton2>\n");
	return 0;
	};
	printf("Output: %0.5f\n", output);
	return 0;
}

void printUsage(void) {
	printf("Known Problem Types: \n");
	printf("<POLY> <COS> <SIN> <TAN> <EXP> <LOG>\n");
	printf("Known Solver Types: \n");
	printf("<BiSec> <FalsePos> <Newton1> <Newton2> <Bracket-Newton1> <Bracket-Newton2>\n");
}
