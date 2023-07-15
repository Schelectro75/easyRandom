#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE* dataCycles;
FILE* dataSeed;

long int randomNumber;
unsigned long long int randCycle;
unsigned long long int randCycleDeadzone;
unsigned int seed;
long int iRand;
bool bRand;

long int easyrandom(long int minimumnumber, long int maximumnumber, bool verbose) {

	randomNumber = 101;
	bRand = false;

	//file opening in read mode
	dataCycles = fopen("./easyRand/cycles.txt", "r"); 	//file that stores the cycles to ignore 
	dataSeed = fopen("./easyRand/seed.txt", "r");		//file that stores the current srandom(3) seed

	//file opening check, basically if the pointers are blank than do not proceede
	if (dataCycles == NULL || dataSeed == NULL) {
		printf("There was an error while loading the stored data, the program will now halt with an error\n");
		return 1;
	}

	
	fscanf(dataCycles, "%llu", &randCycleDeadzone); //load stored cycles value into variables
	fscanf(dataSeed, "%u", &seed);					//load stored seed value into variables

	//close the open files
	fclose(dataCycles);
	fclose(dataSeed);
	
	srandom(seed);	//generate the number sequence 

	//cycle throught the number sequence and find the right number according to the crierias
	while (!bRand) {
		randCycle++;
		randomNumber = random();
		if (randCycle > randCycleDeadzone) {
			if (randomNumber <= maximumnumber && randomNumber >= minimumnumber) {
				iRand = randomNumber;
				bRand = true;
			}
		}
	}

	if (verbose) {
		printf("The generator returned %ld after %llu cycles", iRand, randCycle);
	}
	randCycleDeadzone = randCycle;

	//open the previously opened files, but in write mode
	dataCycles = fopen("./easyRand/cycles.txt", "w");
	dataSeed = fopen("./easyRand/seed.txt", "w");

	if (dataCycles == NULL || dataSeed == NULL) {
		printf("There was an error while loading the stored data, the program will now halt with an error\n");
		return 1;
	}

	fprintf(dataCycles, "%llu", randCycleDeadzone);	// save cycles value

	//determine the correct seed value
	if (randCycleDeadzone == 18446744073709551615) {
		seed++;	
	}
	if (seed == 4294967295) {
		seed = 0;
	}

	fprintf(dataSeed, "%u", seed); //save the seed value

	//close the open files
	fclose(dataCycles);
	fclose(dataSeed);
		
	return iRand;
}