/* 
 * Logan Daivs
 * InLab 9, CSCI 112
 * April 7, 2017
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 20

typedef struct element{
	int atomic_num;			//typedef enum for all varibale in an element
	char name[20];
	char chem_sym[20];
	char class[20];
	double weight;
	int shell[7];
}element_t;

element_t e[MAX_ELEMENTS];	//new array "e" of type element_t with a size of MAX ELEMENTS



void scan_elements(element_t *e)	//scan function for all variables to be inputted
{
	
	scanf("%d%s%s%s%lf%d%d%d%d%d%d%d", &e->atomic_num, &e->name, &e->chem_sym, &e->class, &e->weight, &e->shell[0], &e->shell[1], &e->shell[2], &e->shell[3], &e->shell[4], &e->shell[5], &e->shell[6], &e->shell[7]);
}

void print_elements(element_t *e)	//print fuction, prints the correct element, in the correct box layout
{
	printf("---------------\n");
	printf("|%d\t%.4f\n|%s\t%s\n|", e->atomic_num, e->weight, e->chem_sym, e->name);
	for(int i = 0; i < 7; i++)		
	{
		if(e->shell[i] != 0)		//drops all the zero shell elctrons when printed 
		{
			printf("%d ", e->shell[i]);
		}
	}
	printf("\n---------------\n");
}

int main(int argc, char *argv[])		//main function
{
	int N = 0;
	//check for correct number of args
	if(argc != 2)
	{
		//error if no value is entered
		printf("ERROR: You must provide exactly one argument ot this program. \n");	
		return 0;
	}

	N = (int) strtol(argv[1], NULL, 10);
	if(N > MAX_ELEMENTS || N < 0)
	{
		//convert string argumrnt to an int
		
		if(N <= 0 || N > 20)
		{
			//if given an int less than 0, error
			printf("ERROR: You must provide an integer greater than 0 and less than 20 \n");
		}
		//end program early
		return 0;
	}
	
	element_t e[N];
	for(int i = 0; i < N; i++)		//for loop to scan in input to arrar e
	{
		element_t *eptr = &e[i];	
		scan_elements(eptr);
	}
	printf("%d total elements.\n", N);	//prints the total number of elements "N"

	int smallest = 999999;			//had to set smallest to a high number to ensure that it will be resest to the real smallest number
	int largest = 0;
	element_t e_largest;			//e_largest variable of type element_t
	element_t e_smallest;			//e_smallest varibale of type element_t

	for(int i = 0; i < N; i++)			//for loop to dtermine largest inputted element(atomic numer)
	{
		if(e[i].atomic_num > largest)
		{
			largest = e[i].atomic_num;		
			e_largest = e[i];
		}
	}
	printf("%s had the highest atmoic number.\n", e_largest.name);	//prints the element with the highest atomic number
	
	for(int i = 0; i < N; i++)			//for loop to determine the smallest inputed element(atomic numer)
	{
		if(e[i].atomic_num < smallest)
		{
			smallest = e[i].atomic_num;
			e_smallest = e[i];
		}
	}
	printf("%s had the smallest atmoic number.\n", e_smallest.name);	//prints the element with smallest atomic number
	
	for(int i = 0; i < N; i++)		//for loop that allow all the elements inputted to be printed out in the correct format
	{
		element_t *eptr = &e[i];
		print_elements(eptr);
	}	
	
}
