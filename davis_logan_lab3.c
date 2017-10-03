/*
 * Logan Davis 
 * Lab 3, CSCI 112
 * 2/6/2017
 */

#include <stdio.h>
#include <math.h>

double get_input(void)
{
	double inputvalue;

	printf("Enter a value > "); 
	scanf("%lf", &inputvalue);

	return(inputvalue);
}

int get(void)
{
	int n = -1;
	while(n < 0)
	{
		printf("Enter a value for n that is >= 0: ");
		scanf("%d", &n);

		if(!(n>=0))
		{
			printf("Error, that value is nto greater than or equal to zero \n");
		}
		
	}

	return(n);
}

int main(void)
{
	int n = get();
	double lowest = 9999999;
	double highest = -1;
	int i = 0;
	double sum = 0;
	double average;
	double sum_squares = 0;
	double std_dev;
	double range;
	
	
	for(i; i < n; i++)
	{
		double current = get_input();
		
		if(current < lowest)
		{
			lowest = current;
		}

		if(current > highest)
		{
			 highest = current;
		}

		sum = sum + current;
		sum_squares = sum_squares + (current*current); 		
	}

	range = highest - lowest;

	if(n == 0)
	{
		average = 0;
		std_dev = 0;
		lowest = 0;
		highest = 0;
		range = 0;
	}
	else
	{

		average = sum/n;
		std_dev = (double)sqrt ((sum_squares/n) - (average*average));

	}

	printf("The highest is: %.3lf \n", highest);
	printf("The Lowest is: %.3lf \n", lowest);
	printf("The Average is: %.3lf \n", average);
	printf("The Range is: %.3lf \n", range);
	printf("The Standard deviation is: %.3lf \n", std_dev);

	
}
