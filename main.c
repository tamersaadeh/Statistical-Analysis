/*
 * main.c
 *
 *  Created on: 3 Apr 2012
 *      Author: tamer
 */

#include <stdio.h>
#include <math.h>

#define DEBUG 0

#include "analysislib.h"

#include "csv.h"

int main() {

	/*int size = 100;
	 double arr[size];
	 int i;

	 // Zero arr
	 for (i = 0; i < size; i++) {
	 arr[i] = 0;
	 }

	 read("test.csv", arr, size);

	 */

	double raw[arrSize], standard[arrSize];

	int i;

	// Zero raw and standard
	for (i = 0; i < arrSize; i++) {
		raw[i] = 0;
		standard[i] = 0;
	}

	int arrLen = arrSize;

	read("data.csv", raw, arrLen);
	if (DEBUG) {
		for (i = 0; i < arrLen; i++) {
			printf("%d: %lf\n", i, raw[i]);
		}
	}

	/*
	// Or use this:
	int arrLen;
	do {
		printf("Please enter the number of data "
			"sets you are going to use (max 10000, min 0): ");
		scanf("%d", &arrLen);
	} while (arrLen > arrSize || arrLen <= 0);

	for (i = 0; i < arrLen; i++) {
		printf("%d. Enter sample data: ", i + 1);
		scanf("%lf", &raw[i]);
	}
	*/

	// Table of raw data

	double rmean = mean(raw, arrLen);
	double rmin = min(raw, arrLen);
	double rmax = max(raw, arrLen);
	double rstd = std(raw, arrLen, rmean);

	if (DEBUG) {
		printf("\nRaw data: ");
		table(raw, arrLen, rmean, rmin, rmax, rstd);

		histogram(raw, arrLen, rmax, rmin);
	}

	// Copy raw to standard, before editing it

	copy(raw, standard, arrLen);
	standarize(standard, arrLen, rmean, rstd);

	// Table of standard data

	double smean = mean(standard, arrLen);
	double smin = min(standard, arrLen);
	double smax = max(standard, arrLen);
	double sstd = std(standard, arrLen, smean);

	printf("\nStandarized data: ");
	table(standard, arrLen, smean, smin, smax, sstd);

	histogram(standard, arrLen, smax, smin);

	return 0;
}
