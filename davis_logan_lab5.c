/* 
 * Logan Davis
 * CSCI 112, Inlab5
 * February 24, 2017
 *
 */

#include <stdio.h>

#define MAXSIZE 12            // defining the max size possible for the barcode
int barcode[12];	      // declaraiton of the barcode array

/* Function Prototypes */
int sumodd(void);
int sumeven(void);

int main(void)
{
	int i = 0;
	int totalodd = 0;
	int totaleven = 0;		//all variables used in the program 
	int totalsum = 0;		// for holding values
	int checkdigit = 0;


	//print and scan funtions for storing the user input values into an array

	printf("Enter a barcode to check. seperate digits with a space >\n");	
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &barcode[0], &barcode[1], &barcode[2], &barcode[3], &barcode[4], &barcode[5], &barcode[6], &barcode[7], &barcode[8], &barcode[9], &barcode[10], &barcode[11]);
	
	//loop prints out the array after it was inputed
	printf("\nYou entered the code: ");
	for(i; i < MAXSIZE; i++)
	{
		printf("%d ", barcode[i]);
	}
	printf("\n");
	
	//calling sumodd method to calulate step 1

	totalodd = sumodd();
	printf("Step 1: Sum of odds times 3 is %d \n", totalodd);

	//calling sumeven to calculate step 2

	totaleven = sumeven();
	printf("Step 2: Sum of the even digits is %d \n", totaleven);

	//adding the calculated values from step 1 and step 2 to get a new 
	//varibale, totalsum (step 3)

	totalsum = (totalodd + totaleven);
	printf("Step 3: Total sum is %d \n", totalsum);



	if(totalsum%10 == 0)		// if else statement for caluclating the 
	{				// check digit of the barcode array
		checkdigit = 0;
	}
	else
	{
		checkdigit = (10 - totalsum%10);
	}
	printf("Step 4: Calculated check digit is %d \n", checkdigit);

	

	//if else statement for determining if the barcode is valid or invalid
	if(checkdigit != barcode[11])
	{
		printf("Step 5: Check digit and last digit do not match\n");
		printf("Barcode is INVALID. \n");	
	}
	else
	{
		printf("Step 5: Check digit and last digit match\n");
		printf("Barcode is VALID. \n");	
	}

}


int sumodd(void)	//Method for suming up the odd placements numbers in the
{			//barcode array
	int i = 0;
	int temp = 0;

	for(i; i < MAXSIZE; i += 2)
	{
		temp += barcode[i];	//for loop for the math in adding up the
					//sums of the odd placement numbers
	}
	temp = temp * 3;
	
	return(temp);			//returns the calculated sum
}

int sumeven(void)	//method for calculating the sum of the even placement
{			//numbers in the barcode array
	int i = 1;
	int temp = 0;

	for(i; i < (MAXSIZE - 2); i += 2)
	{
		temp += barcode[i];	//math for suming the values of evens
	}

	return(temp);			//returns calculated sum
}






