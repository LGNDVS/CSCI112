/*
 * Logan Davis
 * CSCI 112, Lab 8
 * March 31, 2017 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 80

/* Function Protoypes */
void reverse(char *line);

int main(int argc, char * argv[])
{
	//check for correct number of args
	if(argc != 2)
	{
		printf("Please provide an integer greater than or equal to 0 \n");			//error if no value is entered
		return 0;
	}
	
	//convert arg to int and check that it is within range
	int N = (int) strtol(argv[1], NULL, 10);
	if(N < 0)
	{
		printf("ERROR: Please provide an integer greater than or equal to 0\n");	//error message if N is less than 0
		return 0;
	}

	int i = 0;
	for(i; i < N; i++)
	{
		char str[SIZE];					//for loop for fgets function getting string
		if(fgets(str, SIZE, stdin))
		{
			//input was successful
		}
		reverse(str);
		printf("%s\n", str); 
	}
	return(0);
}

void reverse(char *line)
{
	char temp[SIZE], word[SIZE];					//decalration of temp array and word array of size "SIZE"

	int index = strlen(line) - 2;					//string length of line
	int word_len = 0;								//word length

	//scan through characters one by one
	while(index >= 0)
	{
		if(line[index] == ' ' && word_len > 0)
		{
			strncpy(word, &line[index + 1], word_len);
			strcat(temp, word);
			strcat(temp, " ");
			memset(word, '\0', SIZE);
			word_len = 0;
		}
		else if(isalnum(line[index]))
		{
			memset(word, '\0', SIZE);
			word_len += 1;
		}
		index--;
	}

	//copy over the last word after the loop (if any)
	if(word_len > 0)
	{
		strncpy(word, line, word_len);
		strcat(temp, word);
	}

	//copy temp back into line
	strncpy(line, temp, strlen(line));
}
