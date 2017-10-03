/* 
 * Logan Davis
 * Lab 2, CSCI 112
 * 1/27/2017
 */

#include <stdio.h>

/* Function prototypes */

double get_input(void);
double get_next(double, double);
double print_result(double);


	int main(void)  //finds the 5th element and prints it out
	{
		double X1, X2, X3, X4, X5;
		/* gets the input values from the user */
		
		X1 = get_input();
		X2 = get_input();

		X3 = get_next(X1, X2);
		X4 = get_next(X2, X3);
		X5 = get_next(X3, X4);

		print_result(X5);
	}

	
	double get_input(void)
	{
		double inputvalue;
		
		// Prompts the user for a value to be entered and stored as a new variable
		// Then returns that variable back

		printf("Enter a value > ");
		scanf("%lf", &inputvalue);

		return(inputvalue);
	}

	double get_next(double valueOne, double valueTwo)
	{
		//gets the next value in the sequence from the previous 2 values
		// returns the next calculated value

		return((valueOne/2) + (3 * valueTwo));

	}

	double print_result(double answer)
	{
		//recieves a value as input and prints the answer in correct formatting
		// formating -  5 total characters with 2 character to the right of the decimal

		printf("The result is %5.2f \n", answer);
	}
