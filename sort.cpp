//preproccessing (calling Used libraries)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//initialize size of random array 
#define size_of_arr 100000

//declaring our random array
int random_array[size_of_arr];

//function to randomize array elements 
void rand(int random_array[]) {
	srand(time(NULL));
	for (int i = 0; i < size_of_arr; i++) {
		random_array[i] = rand() % 100000 + 1;
	}
}

//function to implement insertion sort algorithm
void insertion_sort(int* arr, int length) {
	for (int i = 1; i < length; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	printf("The array is sorted using insertion sort in %u seconds\n", clock());
}

//function to swap elements of array by each other in quick sort algorithm
void swap(int* x, int* z) {
	int temp = *x;
	*x = *z;
	*z = temp;
}

//function to implement quick sort algorithm
void quick_sort(int start, int end) {
	if (start >= end)return;
	int key = start, i = start + 1, j = end;
	while (i <= j) {
		while (i <= end && random_array[i] <= random_array[key]) i++;
		while (j > start && random_array[j] >= random_array[key])j--;
		if (i > j) swap(&random_array[key], &random_array[j]);
		else swap(&random_array[i], &random_array[j]);
	}
	quick_sort(start, j - 1);
	quick_sort(j + 1, end);
}

//our main function 
int main() {
	int arr[size_of_arr];
	srand(time(NULL));
	for (int i = 0; i < size_of_arr; i++) {
		arr[i] = rand() % 100000 + 1;
	}
	printf("Array of 100,000 random numbers is initialized\n");
	rand(random_array);
	quick_sort(0, size_of_arr - 1);
	printf("\nThe array is sorted using quick sort in %u seconds\n", clock());
	insertion_sort(arr, size_of_arr);
	return 0;
}
