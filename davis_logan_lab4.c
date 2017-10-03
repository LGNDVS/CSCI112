/* 
 * Logan Davis
 * CSCI 112, Inlab4
 * 2/22/2107
 *
 */ 
 
#include <stdio.h>
#include <math.h>


typedef enum 	//declaring the enum for variables sine, cosine, tangent, and quit
{
	sine, 
	cosine, 
	tangent, 
	quit
}menu_t;

#define PI 3.14159		//decalring global variables pi and LOOP_LIMIT
#define LOOP_LIMIT 90


int main(void)
{
	menu();
	return(0);
}

int menu(void)
{
	menu_t input = 0; 	//new varibale input is of type enum menu_t
	
	while(input != quit)
	{	
		//menu options for each calcualtion selected by the user		

		printf("Please chose an option: (0) Sine (1) Cosine (2) Tangent (3) Quit \n");
		printf("Enter your choice > ");
		scanf("%u", &input);
		
		double count = 0;
		switch(input)		//switch statement for all the options in the menu
		{
			//tangent case
			case tangent:	
				for(count; count <= LOOP_LIMIT; count += 15)
				{
					double radians = PI * (count / 180);
					double temp = tan(radians);

					if(temp > 10000)
					{
						printf("\ttan(%.0f)is undefined \n", count);
					}
					else
					{
						printf("\ttan(%.0f) = %.4f \n", count, temp);
					}
				}
	
				break;
 
			case cosine:	//cosine case
				for(count; count <= LOOP_LIMIT; count += 15)
				{
					double radians = PI *(count / 180);
					double temp = cos(radians);

					printf("\tcos(%.0f) = %.4f \n", count, temp);
				}
				break;

			case sine:	//sine case
				for(count; count <= LOOP_LIMIT; count += 15)
				{
					double radians = PI * (count / 180);
					double temp = sin(radians);

					printf("\tsin(%.0f) = %.4f \n", count, temp);
				}
				break;

			case quit:	//quit case to exit program
				printf("You chose QUIT. Thank you, come again! \n"); 
				break;

			default: printf("%d is an invalid option \n", input); //case if the number seleted is not 
									      // 0, 1, 2, or 3
		}
	}
}

