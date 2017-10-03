 /*
 * Logan Davis
 * Program 1, CSCI 112
 * 2/20/2017
 */

#include <stdio.h>

int get_input(void)
{
	int inputNum;
	
	// do while loop keeps looping if the value netered is returned invalid from the fucntion is_valid
	do
	{
		printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
		scanf("%d", &inputNum);
	}while(is_valid(inputNum) == 0);

	return(inputNum);

}

int is_valid(int i)
{
	// will return true if the user input is an odd number and less than 10 and greater than 0
	if(i <= 9 && i%2!= 0 && i >= 1)
	{
		return(1);
	}

	else
	{
		// these are the 3 errors that could poosibly happen if the input is invalid
		if(i%2 == 0)
		{
			printf("You have entered an even number. Please try again.\n");
		}
	
		else if(i > 9)
		{
			printf("You have enetered a number greater than 9. Please try again.\n");
		}

		else if(i < 1)
		{
			printf("You have entered a number less than 1. Please try again.\n");
		}

		return(0);
	}
			
}

void print_patterns(int j)
{
	// count is the number of numbers printed per line (incraments by 2)
	int count = 1;  
	
	for(count; count <= j; count += 2)        // pair of loops for top half of the diamond
	{
		printf("%*s", (j-count), "");         // printing j_count blank spaces

		int temp = 1;						  // variable to hold the number that needs to be printed
		while(temp <= count)
		{
			printf("%d ", temp);
			temp++;
		}
		printf("\n");	
	}
	
	count -= 4;

	for(count; count >= 0; count -= 2)		 // pair of loops for bottom half of the diamond
	{
		printf("%*s", (j-count), "");		 // printing j_count blank spaces

		int temp = 1;				
		while(temp <= count)
		{
			printf("%d ", temp);
			temp++;
		}
		printf("\n");
	}
}

int main(void)
{
	int value = get_input();
	print_patterns(value);
	
}





