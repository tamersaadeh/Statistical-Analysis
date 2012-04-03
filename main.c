/*
 * main.c
 *
 *  Created on: 3 Apr 2012
 *      Author: tamer
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "analysislib.h"

int main() {

	double raw[arrSize], standard[arrSize];

	int arrLen;
	do {
		printf("Please enter the number of data "
			"sets you are going to use (max 10000, min 0): ");
		scanf("%d", &arrLen);
	} while (arrLen > arrSize || arrLen <= 0);

	int i;
	for (i = 0; i < arrLen; i++) {
		printf("%d. Enter sample data: ", i + 1);
		scanf("%lf", &raw[i]);
	}

	// Table of raw data

	double rmean = mean(raw, arrLen);
	double rmin = min(raw, arrLen);
	double rmax = max(raw, arrLen);
	double rstd = std(raw, arrLen, rmean);

	/*
	 printf("\nRaw data: ");
	 print_table(raw, arrLen, rmean, rmin, rmax, rstd);

	 histogram(raw, arrLen, rmax, rmin);

	 */

	// Copy raw to standard, before editing it

	copy(raw, standard, arrLen);
	standarize(standard, arrLen, rmean, rstd);

	// Table of standard data

	double smean = mean(standard, arrLen);
	double smin = min(standard, arrLen);
	double smax = max(standard, arrLen);
	double sstd = std(standard, arrLen, smean);

	printf("\nStandarized data: ");
	print_table(standard, arrLen, smean, smin, smax, sstd);

	histogram(standard, arrLen, smax, smin);

	return 0;
}
