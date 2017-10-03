/*
 * Logan Davis
 * CSCI 112
 * Program 3
 * April 21, 2017
 */

#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 25		//global definiton of NAME_SIZE at 25

typedef struct student{				//Student record enum
 int std_id;	//student id number
 char firstName[NAME_SIZE];
 char lastName[NAME_SIZE];
 float gpa;				//grade point average variable
 float *grades;		//list of grades
 }student;


float calculateGPA(student s, int totgrades)	//calculates students gpa based off of their record
{
	float sum =0;	//gpa starts at 0 for no classes
	for(int i =0; i < totgrades; i++)
	{
		sum+= s.grades[i];
	}
	float gpa = sum/(totgrades);
	return(gpa);//returns calculated gpa
}


student populate(int totgrades)					//Responsible for inputting information pertaining to a single student and storing that information in that student's record
{
	student r;	//new student record
	scanf("%d %s %s ", &r.std_id, r.lastName, r.firstName);

	r.grades = (float *)calloc(totgrades, sizeof(float));

	for(int i =0; i < totgrades; i++)	//can be a seperate scanf command because scanf will delineate input based on white space.
	{
		scanf("%f", &r.grades[i]);
	}

	r.gpa = calculateGPA(r,totgrades);
	return(r);//return student record
}





void printRecords(student *s, int students, int grades)			//print a student's records in the format asked for in example outputs
{
	for(int i =0; i < students; i++)
	{
		printf("ID: %d, Name: %s %s, GPA: %.2f\n", s[i].std_id, s[i].firstName, s[i].lastName, s[i].gpa);
		printf("Grades: ");
		
		for(int j =0; j < grades; j++)
		{
			printf("%.1f " , s[i].grades[j]);
		}
		printf("\n");
	}
}



void releaseMemory(student *s, int students)	//frees all of the memory allocated to a student record 
{
 for(int i = 0; i < students; i++)
 {
 	free(s->grades);
 	s->grades =NULL;
 }
 free(s);
 s = NULL;
}



int main()  //main function
{
	int numStudents;
	int numGrades;

	scanf("%d", &numStudents);		//scans in number of students

	scanf("%d", &numGrades);		//scans in the number of grades
	printf("Number of students: %d\n", numStudents);	//print line for number of students to be entered
	printf("Number of grades (each): %d\n", numGrades);	//print line for number of grades to be entered

	student *ptr =(student *)calloc(numStudents, sizeof(student));
	
	for(int i = 0; i < numStudents; i++)	//calling populate for the total number of students so each gets populated
	{
		ptr[i] = populate(numGrades);
	}
	
	printRecords(ptr, numStudents, numGrades);		
	
	releaseMemory(ptr, numStudents);
	return(0);
}
