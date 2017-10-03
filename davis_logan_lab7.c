/*
 * Logan Davis
 * CSCI 112, InLab 7
 * March 27, 2017
 */
 
#include <stdio.h>
#include <string.h>
 
/* Function Prototypes */
char *my_strncpy(char *dest, char *source, int n);
char *my_strncat(char *dest, char *source, int n);
 
 
char *my_strncpy(char *dest, char *source, int n)	//implementation function of strncpy
{
	
	int i = 0;
	
	for(i; i < n; i++)		//for loop assigning elements from dest to source
	{
		dest[i] = source[i];	//assigns the first n elements of dest to the first n elements of source
	}	

	dest[n] = '\0';			//null character appeneded to dest at index n
	return(dest);			//returns pointer(dest) to a char
}

char *my_strncat(char *dest, char *source, int n)	//implementation function of strncat
{
	int i = strlen(dest);
	int j = 0;
	int max = i + n;
	for(i; i < max; i++)			//for loop to assign elements of dest to source
	{
		dest[i] = source[j];		//assigns the first n elements of dest to the first n elements of source
		j++; 				//incrament j to the next index point
	}	
	dest[i + n] = '\0';			

	return(dest);				//returns pointer(dest) to a char
}
 
int main() {
   // Test your function with various source strings and values of n

   char testSrc[] = "Hello";
   char testDest[40] = "world";
   int n = 5;

   my_strncat(testDest, testSrc, n);
   printf("CAT: %s \n", testDest);

   my_strncpy(testDest, testSrc, n);
   printf("CPY: %s \n", testDest);

   printf("%s \n", testDest);
   return 0;
}
 
