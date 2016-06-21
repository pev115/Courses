/* C++ Programming, Example answer, Exercise 3, Sheet 6  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 30th September 2001    */

/* This program demonstrates the function 'no_repetitions' which
   removes repeated characters from strings */

#include <iostream>
#include <cstring>
using namespace std;

const int MAXIMUM_STRING_LENGTH = 80;

/* Function to remove repetitions from a string */
void no_repetitions(char a[]);

/* Function which returns TRUE if 'character' appears in 'a' with an index 
   less than 'stop' */
bool appeared_previously(char character, char a[], int stop);

/* Function which removes the character with index 'start' from 'a'
   and then decreases the indexes of all subsequent characters in 'a'
   by 1  */
void shuffle_up(char a[], int start);


/* START OF MAIN PROGRAM */
int main()
{
	char a_string[MAXIMUM_STRING_LENGTH];
	cout << "Type in a string: ";
	cin.getline(a_string,MAXIMUM_STRING_LENGTH);
	no_repetitions(a_string);
	cout << "The string without repetitions is: " << a_string << "\n";
		
	return 0;
}
/* END OF MAIN PROGRAM */

/* DEFINITION OF FUNCTION "no_repetitions" */
void no_repetitions(char a[])
{
	for (int count = strlen(a) - 1 ; count > 0 ; count--)
		if (appeared_previously(a[count],a,count)) 
			shuffle_up(a,count);
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "appeared_previously" */
bool appeared_previously(char character, char a[], int stop)
{
	for (int count = 0 ; count < stop ; count++)
		if (a[count] == character) 
			return true;
	return false;
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "shuffle_up" */
void shuffle_up(char a[], int start)
{
	int count = start ;
	while ( a[count] != '\0')
	{
		a[count] = a[count+1];
		count++;
	}
}
/* END OF FUNCTION DEFINITION */

