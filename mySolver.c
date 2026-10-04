#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solverType.h"

void printUsage(void);

// ./mysolver [problem type] [solver type] [args] [range start] [range end]
int main(int argc, char *argv[]) {
	// TODO: Stack / Heap : General rule of thumb, Heap is for memory we can't know the size of at compile time. This would include the arguements list because we don't know how big the polynomial might be. Consider changing some allocations over to the heap. -Boot.dev lessons
	size_t length = argc; // first three and last two, example shows last two are a range
	int max = 20; //arbitrary max of function. Could go bigger. 

	if (argc < 4) {
		printf("Not enough arguements given\n");
		printUsage();
		return 0;
	} else if (argc > max) {
		printf("Too many arguements: Max: %d, Max Coefficients: %zu", max, length);
		return 0;
	}

	double output;

	char *problemType = argv[1];
	char *solverType = argv[2];
	double *args = malloc(sizeof(double) * length);
	if (args == NULL) {
		printf("Error: Issue allocating memory for args");
		return 1;
	}

	double bounds[] = {atof(argv[argc - 2]), atof(argv[argc - 1])};
	
	if (argc > max) {
		printf("Too many Arguements to handle");
		return 0;
	}

	for (int i = 3; i < argc - 2; i++){
		args[i-3] = atof(argv[i]);
	}
	
	if (strcmp("POLY", problemType) == 0|| strcmp("COS", problemType) == 0
	|| strcmp("SIN", problemType) == 0 || strcmp("TAN", problemType) == 0 
	|| strcmp("EXP", problemType) == 0 || strcmp("LOG", problemType) == 0 ) {
		printf("Error: Not a known Problem Type: \n");
		printUsage();
		return 0;
	}
	
	if (strcmp("BiSec", solverType) == 0){
		output = BiSec(problemType, length, args, bounds[0], bounds[1]);
	} else if (strcmp("FalsePos", solverType) == 0){
		output = FalsePos(problemType, length, args, bounds[0], bounds[1]);
	} else if (strcmp("Newton1", solverType) == 0){
		output = Newton1(problemType, length, args, bounds[0], bounds[1]);
	} else if (strcmp("Newton2", solverType) == 0){
		output = Newton2(problemType, length, args, bounds[0], bounds[1]);
	} else if (strcmp("Bracket-Newton1", solverType) == 0){
		output = BracketNewton1(problemType, length, args, bounds[0], bounds[1]);
	} else if (strcmp("Bracket-Newton2", solverType) == 0){
		output = BracketNewton2(problemType, length, args, bounds[0], bounds[1]);
	} else {
	printf("Error: Not a known Solver Type: \n");
	printUsage();
	return 0;
	};
	
// TODO: May also need to calculate the error. 
	printf("Solver output: %g\n", output);
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
