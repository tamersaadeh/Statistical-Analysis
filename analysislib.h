/*
 * statistical_analysis.h
 *
 *  Created on: 3 Apr 2012
 *      Author: tamer
 */

#define arrSize 10000

double mean(double *arr, int len) {
	int i;
	double mean = 0.0;
	for (i = 0; i < len; i++)
		mean += (double) arr[i];
	mean /= len;
	return mean;
}

double std(double *arr, int len, double mean) {
	int i;
	double std = 0.0;
	for (i = 0; i < len; i++)
		std += ((double) arr[i] - mean) * ((double) arr[i] - mean);
	std /= len;
	std = sqrt(std);
	return std;
}

double max(double *arr, int len) {
	int i;
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

double min(double *arr, int len) {
	int i;
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

double standarizeOne(double element, double mean, double std) {
	return (element - mean) / std;
}

void standarize(double *arr, int len, double mean, double std) {
	int i;
	for (i = 0; i < len; i++)
		arr[i] = standarizeOne(arr[i], mean, std);
}
/*
 * arr1 and arr2 must be of the same length len
 */
void copy(double *arr1, double *arr2, int len) {
	int i;
	for (i = 0; i < len; i++)
		arr2[i] = arr1[i];
}

void print_table(double *arr, int len, double mean, double min, double max,
		double std) {

	int i;
	for (i = 0; i < len; i++) {
		printf("%lf", arr[i]);
		if (i < (len - 1))
			printf(", ");
	}
	printf("\n");

	puts("Quantity\t\tValue");
	printf("Mean\t\t\t%lf\n", mean);
	printf("Min\t\t\t%lf\n", min);
	printf("Max\t\t\t%lf\n", max);
	printf("Standard Deviation\t%lf\n", std);
}

void histogram(double *arr, int len, int max, int min) {

	puts("Histogram");

	int freq[10];

	// Zero freq array
	int i;
	for (i = 0; i < 10; i++) {
		freq[i] = 0;
	}

	double width = (max - min) / 10;
	for (i = 0; i < len; i++) {
		int position = (int) ((arr[i] - min) / width);
		printf("arr[%d]=%d\n", i, arr[i]);
		printf("min=%d\n", min);
		printf("width=%d\n", width);
		printf("position=%d\n", position);

		freq[position]++;
	}

	// Drawing the histogram using ASCII art

	for (i = 0; i < 10; i++) {
		int j;
		printf("%d: ", i + 1);
		for (j = 0; j < freq[i]; j++) {
			printf("*");
		}
		printf("\n");
	}

}
