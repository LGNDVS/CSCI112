/* 
 * Logan Davis
 * CSCI 112, Section 4
 * March 20, 2017
 *
 */ 

#include <stdio.h>

#define MAX_ARRAY_SIZE 50

/* Function Prototypes */

int populate_array(int array[]);			// Fill array with values from user
void print_array(int array[], int n);			// Print out the array values
void swap(int array[], int index1, int index2);		// Swap two aray elements 
void quicksort(int array[], int low, int high);		// Sorting alforithim
int partition(int array[], int low, int high);		// Find the partition point(pivot)

int main(void)
{
	int array[MAX_ARRAY_SIZE];			// Declaring a new array
	int n = 0;
	
	n = populate_array(array);
	printf("The initial array contains: \n");	
	print_array(array, n);				// prints contents of the initial array
	quicksort(array, 0, n-1);			// Call to sort the unsorted array
	printf("The array is now sorted: \n");		
	print_array(array, n);				//prints the contents of the newly sorted array
	return(0);
}

int populate_array(int array[MAX_ARRAY_SIZE])
{
	int user_input = 0;
	int i = 0;
	
	
	printf("Enter the value of n > ");		// Prompts user for the array size of n
	scanf("%d", &user_input);
	
	while(user_input < 0 || user_input > MAX_ARRAY_SIZE)		// While loop to check if the value entered is valid
	{
		if(user_input < 0)
		{
			printf("%d is less than zero. Please try again.\n\n", user_input);
		}
		else if(user_input > MAX_ARRAY_SIZE)
		{
			printf("%d exceeds the maximum array size. Please try again. \n\n", user_input);
		}
		
		printf("Enter the value of n > ");			// if the first input was invalid, prompts again for another try
		scanf("%d", &user_input);
	}
	
	printf("Enter %d integers (positive, negative, or zero) > \n", user_input);
	for(i; i < user_input; i++)
	{
		int num;
		scanf("%d", &num);				//for loop that inputs individual interger inputs into the unsorted array
		array[i] = num;
	}
	return(user_input);
	
}

void print_array(int array[MAX_ARRAY_SIZE], int n)
{
	int i = 0;
	for(i; i < n;i++)
	{
		printf("%+5d \n", array[i]);		//prints the contents of each array, one by one
	}
}

void swap(int array[MAX_ARRAY_SIZE], int index1, int index2)
{
	int temp = array[index1];
	array[index1] = array[index2];			//swaps the contents of the array passed in
	array[index2] = temp;
	
}

void quicksort(int array[MAX_ARRAY_SIZE], int low, int high)
{
	if(low < high)
	{
	int pivot = partition(array, low, high);		//sorts the passed in array from low to high
	quicksort(array, low, pivot - 1);
	quicksort(array, pivot + 1, high);

	}
}

int partition(int array[MAX_ARRAY_SIZE], int low, int high)
{
	int pivot = array[high];
	int i = low;
	int j = low;
	for(j; j < high; j++)
	{
		if(array[j] <= pivot)				//splits up the array into two seperate arrays
		{
			swap(array, i, j);
			i = i + 1;
		}
	}
	
	swap(array, i, j);
	return(i);
}
