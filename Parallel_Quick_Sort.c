#include <stdio.h>
#include <omp.h>
#include<stdlib.h>
#include<string.h>
// Function to swap two numbers a and b
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// Function to perform the partitioning
// of array arr[]
int partition(int arr[], int start, int end)
{
	// Declaration
	int pivot = arr[end];
	int i = (start - 1);

	// Rearranging the array
	for (int j = start; j <= end - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[end]);

	// Returning the respective index
	return (i + 1);
}

// Function to perform QuickSort Algorithm
// using openmp
void quicksort(int arr[], int start, int end)
{
	// Declaration
	int index;

	if (start < end) {

		// Getting the index of pivot
		// by partitioning
		index = partition(arr, start, end);

// Parallel sections
#pragma omp parallel sections
		{
#pragma omp section
			{
				// Evaluating the left half
				quicksort(arr, start, index - 1);
			}
#pragma omp section
			{
				// Evaluating the right half
				quicksort(arr, index + 1, end);
			}
		}
	}
}
char* itoa(int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}
// Driver Code
int main()
{
	// Declaration
	int N;

	// Taking input the number of
	// elements we wants
	printf("Enter the number of elements you want to Enter\n");
	scanf("%d",&N);
	int *arr = (int*)calloc(N, sizeof(int)), count = 0;
	FILE* ptr, *writePtr;
	int a;
	ptr = fopen("input.txt", "r");
	writePtr = fopen("output.txt", "w");
	while(fscanf(ptr, "%d", &a) != EOF){
		arr[count++] = a;

	}

	// Calling quicksort having parallel
	// code implementation
	quicksort(arr, 0, N - 1);

	// Printing the sorted array
	printf("Array after Sorting is: \n");

	for (int i = 0; i < N; i++) {
		//printf("%d ",arr[i] );
		char str[16];
		char *s = itoa(arr[i], str, 10);
		// char space = ' ';
		// strncat(s, &space, 1);
		fprintf(writePtr, "%s ", s);
	}

	return 0;
}
