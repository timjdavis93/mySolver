#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "problemType.h"
#include "solverType.h"

void printUsage(void);

// ./mysolver [problem type] [solver type] [args] [range start] [range end]
int main(int argc, char *argv[]) {

	size_t lengthOfCoefficients = argc - 3 - 2; // first three and last two, example shows last two are a range
	int max = 20; //arbitrary max of function. Could go bigger. 

	if (argc < 4) {
		printf("Not enough arguements given\n");
		printUsage();
		return 0;
	} else if (argc > max) {
		printf("Too many arguements: Max: %d, Max Coefficients: %zu", max, lengthOfCoefficients);
		return 0;
	}

	double output;

	char *problemType = argv[1];
	char *solverType = argv[2];
	double coefficients[lengthOfCoefficients];
	double newPoly[lengthOfCoefficients];
	double bounds[2] = {atof(argv[argc - 2]), atof(argv[argc - 1])};
	
	if (argc > max) {
		printf("Too many Arguements to handle");
		return 0;
	}

	for (int i = 3; i < argc - 2; i++){
		coefficients[i-3] = atof(argv[i]);
	}
	
	
	// TODO: I think it may be easiest to turn them all into poly then handle with the solver,
	if (strcmp("POLY", problemType) == 0){
		memcpy(newPoly, coefficients, lengthOfCoefficients * sizeof(double));
	} else if (strcmp("COS", problemType) == 0) {
		cosToPoly(coefficients);
	} else if (strcmp("SIN", problemType) == 0) {
		sinToPoly(coefficients);
	} else if (strcmp("TAN", problemType) == 0) {
		tanToPoly(coefficients);
	} else if (strcmp("EXP", problemType) == 0) {
		expToPoly(coefficients);
	} else if (strcmp("LOG", problemType) == 0) {
		logToPoly(coefficients);
	} else { 
		printf("Error: Not a known Problem Type: \n");
		printf("<POLY> <COS> <SIN> <TAN> <EXP> <LOG>\n");
	}

	
	// TODO: each of these might look something like output = BiSec(length, newPolyArray, range start, range end) output would be the answer after recursive resolution
	// Calls would need to call themselves recursively until a solution is found
	if (strcmp("BiSec", solverType)){
		output = BiSec();
	} else if (strcmp("FalsePos", solverType)){
		output = FalsePos();
	return 0;
	} else if (strcmp("Newton1", solverType)){
		output = Newton1();
	return 0;
	} else if (strcmp("Newton2", solverType)){
		output = Newton2();
	return 0;
	} else if (strcmp("Bracket-Newton1", solverType)){
		output = BracketNewton1();
	return 0;
	} else if (strcmp("Bracket-Newton2", solverType)){
		output = BracketNewton2();
	return 0;
	} else {
	printf("Error: Not a known Solver Type: \n");
	printf("<BiSec> <FalsePos> <Newton1> <Newton2> <Bracket-Newton1> <Bracket-Newton2>\n");
	return 0;
	};
	printf("Output: %g\n", output);
	return 0;
}

void printUsage(void) {
	printf("=====================================================================================\n");
	printf("<./mySolver> <Problem Type> <Solver Type> <Coefficients> <Range Start> <Range End>\n");
	printf("=====================================================================================\n");
	printf("Known Problem Types: \n");
	printf("<POLY> <COS> <SIN> <TAN> <EXP> <LOG>\n");
	printf("Known Solver Types: \n");
	printf("<BiSec> <FalsePos> <Newton1> <Newton2> <Bracket-Newton1> <Bracket-Newton2>\n");
	printf("=====================================================================================\n");
}
