/*
 * Logan Davis 
 * Lab 6, CSCI 112
 * March 6, 2017
 *
 */

#include <stdio.h>
#include <math.h>

/* Function Prototypes */
int user_menu(void); 		//displays user menu, reads input, and validates input

void equation1(float *);
void equation2(float *);
void equation3(float *);	//each equation for the calulations to be done
void equation4(float *);

float get_position_initial(void); 	//prompts user for x0
float get_position_final(void);   	//prompts user for xf
float get_velocity_initial(void);	//prompts user for v0
float get_velocity_final(void);		//prompts user for vf
float get_acceleration(void);		//prompts user for a
float get_time(void);			//prompts user for t
 


int main(void)
{
		
	// Print welcome message
	printf("Welcome to the MOTION EQUATION CALCULATOR \n\n");

	//Variable for the user choice menu
	int user_choice;

	do
	{
		user_choice = user_menu(); 
		//print menu, validate choice between 1 and 5

		float result; //variable to hold calcualted result

		//Handle menu choice selected by user
		switch(user_choice)
		{
			case 1:
				
				equation1(&result);				//calls equation 1 when selected
	
				printf("Your result is %.4f. \n\n", result);
				break;

			case 2:
				
				equation2(&result);				//calls equation 2 when selected

				printf("Your result is %.4f. \n\n", result);
				break;

			case 3:
				
				equation3(&result);				//calls equation 3 when selected

				printf("Your result is %.4f. \n\n", result);
				break;

			case 4:
				
				equation4(&result);				//calls equation 4 when selected
	
				printf("Your result is %.4f. \n\n", result);
				break;

			case 5:
				// exit program if user selected QUIT
				printf("Thank you for using the MOTION EQUATION CALCUALTOR. Goodbye. \n");
				return(0);
				break;

			default: 
				//when a number that isnt 1-5 is inputted, error message is displayed
				printf("Invalid Option. Please try again.\n\n");
				break;
		} 
	}while(user_choice != 5);

	return(0); // exit with no error
}

int user_menu(void)
{	
	//menu funtion that is iinputte dinto the switch statement in main
	int user_choice = 0;

	printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
	scanf("%d", &user_choice);
	return(user_choice);
}

void equation1(float *vf)
{
	float v0 = get_velocity_initial();
	float a = get_acceleration();
	float t = get_time();

	*vf = v0 + (a * t);         //math calcualtion for equation 1 

	
}

void equation2(float *xf)
{
	float x0 = get_position_initial();
	float v0 = get_velocity_initial();
	float t = get_time();
	float a = get_acceleration();

	*xf = x0 + (v0 * t) + (.5 * a * powf(t,2));		//math calculation for equation 
}

void equation3(float *vf2)
{
	float v0 = get_velocity_initial();
	float a = get_acceleration();
	float xf = get_position_final();
	float x0 = get_position_initial();

	*vf2 = sqrt((v0 * v0) + (2 * a * (xf - x0)));		//math equation for equation 3
}

void equation4(float *xf2)
{
	float x0 = get_position_initial();
	float vf = get_velocity_final();
	float v0 = get_velocity_initial();
	float t = get_time();

	*xf2 = (x0 + (.5 * (vf + v0) * t));			// math calcualtion for equation 4


}

float get_position_initial(void)				//get initial position from user	
{
	float pos_initial;
	
	printf("    Enter initial postion > ");
	scanf("%f", &pos_initial);
	return(pos_initial);
}

float get_position_final(void)					//get final position from user
{
	float pos_final;

	printf("    Enter final postion > ");
	scanf("%f", &pos_final);
	return(pos_final);
}

float get_velocity_initial(void)				//get initial velocity from user
{
	float vel_initial;

	printf("    Enter initial velocity > ");
	scanf("%f", &vel_initial);
	return(vel_initial);
}

float get_velocity_final(void)					//get final velocity from user
{
	float vel_final;

	printf("    Enter final velocity > ");
	scanf("%f", &vel_final);
	return(vel_final);
}

float get_acceleration(void)					//get acceleration from user
{
	float accel;
	
	printf("    Enter acceleration > ");
	scanf("%f", &accel);
	return(accel);
}

float get_time(void)						//get time from user
{
	float time;
	
	printf("    Enter time > ");
	scanf("%f", &time);
	return(time);
}
