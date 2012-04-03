/*
 * main.c
 *
 *  Created on: 3 Apr 2012
 *      Author: tamer
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define arrSize 10000

int size(double *arr) {
	return sizeof(arr);
}

double mean(double *arr) {
	int i, len = size(arr);
	double mean = 0.0;
	for (i = 0; i < len; i++)
		mean += (double) arr[i];
	mean /= len;
	return mean;
}

double std(double *arr) {
	int i, len = size(arr);
	double std = 0.0, m = mean(arr);
	for (i = 0; i < len; i++)
		std += ((double) arr[i] - m) * ((double) arr[i] - m);
	std /= len;
	std = sqrt(std);
	return std;
}

double max(double *arr) {
	int i, len = size(arr);
	double max;
	for (i = 0; i < len; i++) {
		if (i == 0)
			max = arr[i];
		else {
			if (max < arr[i])
				max = arr[i];
		}
	}
	return max;
}

double min(double *arr) {
	int i, len = size(arr);
	double min;
	for (i = 0; i < len; i++) {
		if (i == 0)
			min = arr[i];
		else {
			if (min > arr[i])
				min = arr[i];
		}
	}
	return min;
}

double standarizeOne(double element, double *arr) {
	return (element - mean(arr)) / (std(arr));
}

void standarize(double *arr) {
	int i, len = size(arr);
	for (i = 0; i < len; i++)
		arr[i] = standarizeOne(arr[i], arr);
}

int copy(double *arr1, double *arr2) {
	int i, len1 = size(arr1), len2 = size(arr2);
	if (len1 != len2)
		return 0;
	for (i = 0; i < len1; i++)
		arr2[i] = arr1[i];
	return 1;
}

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

	puts("Quantity\t\tValue");
	printf("Mean\t\t\t%lf\n", mean(raw));
	printf("Min\t\t\t%lf\n", min(raw));
	printf("Max\t\t\t%lf\n", max(raw));
	printf("Standard Deviation\t%lf\n", std(raw));

	if (copy(raw, standard))
		standarize(standard);
	else
		return 1;

	puts("Standarized data:");
	for (i = 0; i < arrLen; i++) {

		printf("%lf", standard[i]);
		if (i < (arrLen - 1))
			printf(", ");
		else if (i == (arrLen - 1))
			printf("\n");
	}

	puts("Quantity\t\tValue");
	printf("Mean\t\t\t%lf\n", mean(standard));
	printf("Min\t\t\t%lf\n", min(standard));
	printf("Max\t\t\t%lf\n", max(standard));
	printf("Standard Deviation\t%lf\n", std(standard));

	// Histogram Part

	int *freq;

	for (i = 0; i < 10; i++) {
		freq[i] = 0;
	}

	float smax = max(standard), smin = min(standard);

	float hsize = (smax - smin) / 10;
	for (i = 0; i < 10; i++) {
		int interval = (int) ((standard[i] - smin) / hsize) % 10;
		freq[interval]++;
	}

	for (i = 0; i < 10; i++) {
		int j;
		for (j = 0; j < freq[i]; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
