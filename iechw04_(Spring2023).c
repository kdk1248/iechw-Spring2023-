//Online C compiler to run C program Online
#include <stdio.h>

/*
 function name: calculateAvg(score[])
 function task: This function will calculte the average of
    socres in array.
 paremeter: score[]
*/
float calcualteAvg(int score[]) {
	// declare variable for allocationg sum of socres.
	int totalScore = 0;
	int count = 0;
	for (int i = 0; i < 10; i++) {
		totalScore += score[i];
		// totalScore = totalScore + score[1];
		count++;
	}

	float avg = totalScore / count;
	return avg;
}

int maxscore(int maxarray[]) { //receive "maxarry" in an integer array
	int maxscore = 0; //Initialize variable named 'maxscore' to zero at the same time as declaration
	for (int i = 0; i < 10; i++)//Initialize the value of the variable "i" to "0", repeat while "i<10" is true, and output from 0 to 9

	{
		if (maxscore < maxarray[i]) maxscore = maxarray[i];
	}//If "maxarray[i]" is greater than the value of "maxscaore", then "maxscore = maxarray[i]"
	return maxscore; // Returns 'maxscore'

}

int minscore(int minarray[]) { // receive "minarry" in an integer array
	int minscore = 100; //Initialize variable named 'minscore' to 100 at the same time as declaration
	for (int i = 0; i < 10; i++) //Initialize the value of the variable "i" to "0", repeat while "i<10" is true, and output from 0 to 9
	{
		if (minscore > minarray[i]) minscore = minarray[i];
		//If 'maxarray[i]' is less than the value of 'min' then 'minscore = maxarray[i]'
	}
	return minscore; //Returns 'minscore'
}

int main(){ //Declare the "main()" function that returns the datum type "int"

	int score[10] = { 40, 35, 70, 65, 99, 42, 78, 85, 100, 5 }; //Declares an integer array and executes an initialization of the array that enters the initial value
	float result = calcualteAvg(score);//Assign a value with a variable declaration as a real number
	printf("Your score average is: %f", result);//Prints a string, where '%f' is the variable
	printf("\nYour maxscore is: %d", maxscore(score));//Prints a string, where '%d' is the variable
	printf("\nYour minscore is: %d", minscore(score)); //Prints a string, where '%d' is the variable
	return 0; //Returns an integer value
}