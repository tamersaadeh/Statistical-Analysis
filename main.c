/*
 * main.c
 *
 *  Created on: 3 Apr 2012
 *      Author: tamer
 */

#include <stdio.h>
#include <math.h>

double mean(double *arr) {
	int i, len = sizeof(arr);
	double mean = 0.0;
	for (i = 0; i < len; i++)
		mean += (double) arr[i];
	mean /= len;
	return mean;
}

double std(double *arr) {
	int i, len = sizeof(arr);
	double std = 0.0, m = mean(arr);
	for (i = 0; i < len; i++)
		std += ((double) arr[i] - m) * ((double) arr[i] - m);
	std /= len;
	std = sqrt(std);
	return std;
}

double max(double *arr) {
	int i, len = sizeof(arr);
	double max;
	for (i = 0; i < len; i++) {
		if (i == 0)
			max = arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

double min(double *arr) {
	int i, len = sizeof(arr);
	double min;
	for (i = 0; i < len; i++) {
		if (i == 0)
			min = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

int main() {

}
