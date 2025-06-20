#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10


void mergesort (double a[], int left, int right);

void merge (double a[], int left, int center, int right);

int main () {
	
	srand(time(NULL));
	
	size_t dim = 0;
	int errflag = 0;
	
	do {
		printf("Select array size: ");
		scanf("%d", &dim);
	} while (dim == 0);
	
	double* a = malloc(dim*sizeof(double));
	
	for (int i = 0; i < dim; i++) {
		a[i] = (double) rand() / RAND_MAX;
		a[i] *= 100.0;
	}
	
	/*
	for (int i = 0; i < dim; i++) {
		printf("a[%d] = %.2f\n", i, a[i]);
	}
	*/
	mergesort(a, 0, dim-1);
	/*
	printf("\nSorted:\n");
	for (int i = 0; i < dim; i++) {
		printf("a[%d] = %.2f\n", i, a[i]);
	}
	*/
	printf("\nChecking for errors:\n");
	for (int i = 1; i < dim; i++) {
		if (a[i] < a[i-1]) {
			printf("Error: a[%d] = %.2f > %.2f = a[%d]\n", i-1, a[i-1], a[i], i);
			errflag = 1;
		}
	}
	if (errflag) {
		return 1;
	}
	printf("\nNo errors found.\n");
	return EXIT_SUCCESS;
}

void mergesort (double a[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		mergesort(a, left, center);
		mergesort(a, center+1, right);
		merge(a, left, center, right);
	}
}

void merge (double a[], int left, int center, int right) {
	
	int i = left;
	int j = center+1;
	int k = 0;
	double* b = malloc((right-left+1)*sizeof(double));

	
	while (i <= center && j <= right) {
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
		}
		else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
	
	
	while (i <= center) {
		b[k] = a[i];
		i++;
		k++;
	}
	
	while (j <= right) {
		b[k] = a[j];
		j++;
		k++;
	}
	
	for (int c = left; c <= right; c++) {
		a[c] = b[c-left];
	}
}
