/*
 * csv.h
 *
 * Created on: 3 Apr 2012
 *     Author: tamer
 */

#include <string.h>
#include <stdlib.h>

void read(char *path, double *arr, int size) {
	FILE *stream = fopen(path, "r");

	if (stream == 0) {
		perror("error opening file\n");
		return;
	}

	int i = 0;
	while (!feof(stream)) {
		char line[1000];
		fscanf(stream, "%s\n", &line);

		printf("line=%s\n", line);

		// Split by ","
		char *value = strtok(line, ",");
		printf("value=%s\n", value);

		while (value != NULL && i < size) {
			char *end;
			double number;

			// Convert string to double
			number = strtod(value, &end);
			printf("%lf\n", number);

			// Save it in array if not 0
			if (number == (double) 0)
				i--;
			else
				arr[i] = number;

			printf("arr[%d]=%lf\n", i, arr[i]);

			value = strtok(NULL, ",");
			i++;
		}
		if (value != NULL)
			i++;
	}

}
