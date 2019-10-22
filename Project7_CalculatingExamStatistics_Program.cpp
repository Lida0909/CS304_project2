#include<iostream>
#include<fstream>		//libraries header
#include<cmath>
#include<iomanip>

using namespace std;

	//prototype functions

int numberOfGrade(string fileName);           
float calculateAverageGrade(string fileName);
float calculateHighestGrade(string fileName);
float calculateLowestGrade(string fileName);
int calculateAboveAverage(string fileName);
int calculateBelowAverage(string fileName);

int main()
{
	//print out results
	
	string fileName = "grade.txt";						// declare file name 
	
	cout << "The number of grades is " << numberOfGrade(fileName) << endl; 			
	cout << "The average grade is " << calculateAverageGrade(fileName) << endl;
	cout << "The highest grade is " << calculateHighestGrade(fileName) <<endl;
	cout << "The lowest grade is " << calculateLowestGrade(fileName) << endl;
	cout << "The number of grades above the average is " << calculateAboveAverage(fileName) << endl;
	cout << "The number of grades belowe the average is " << calculateBelowAverage(fileName) << endl;

	return 0;		
}

int numberOfGrade(string fileName)		//numberOfGrade function
{
	ifstream inFile;			
	inFile.open("grade.txt");		//open file
	int counter = 0;				//counter starts from 0
	while(inFile)
	{					
		float grade;
		inFile >> grade;			
		if(inFile)
		{
			counter++;			//adding all the grades from the file one by one until it's done	
		}
	}
	return counter;
	
}

float calculateAverageGrade(string fileName) 	//calculateAverageGrade funcion
{
	float total=0;								//float total empty when it begins
	ifstream inFile;
	inFile.open("grade.txt");					//open file
	float counter = 0;							//counter starts from 0
	while(inFile)
	{
		float grade;
		inFile >> grade;
		if(inFile)
		{
			total += grade;						//sum all the grades that in the file
			counter++;
		}
	}
	total = total / counter;					//divide the sum of the grades by number of grades to find the average
	return total;
	
}

float calculateHighestGrade(string fileName)  //calculateHighestGrade function
{
	ifstream inFile;
	inFile.open("grade.txt");				//open file
	float highest = 0;						//declare highest grade equals to 0 
	int counter = 0;
	while(inFile)
	{
		float grade;
		inFile >> grade;
		if(inFile)
		{
			counter++;
			if (grade > highest)			//declare grade is higher than highest grade
			{			
				highest = grade;			//since the grade is higher than hightest, declare highest equals grade to find the higest grade
			}
		}
	}
	return highest;
	
}

float calculateLowestGrade(string fileName) //calculateLowestGrade function
{
	ifstream inFile;
	inFile.open("grade.txt");			//open file
	float lowest = 0;					//declare lowest grade equals to 0 
	int counter = 0;
	while(inFile)
	{
		float grade;
		inFile >> grade;
		if(inFile)
		{
			counter++;
			if (grade < lowest)			//declare grade is lower than lowest grade
			{
				lowest = grade;			//since the grade is lower than lowest grade, declare lowest grade equals to grade to find the lowest grade
			}
		}
	}
	return lowest;
	
}

int calculateAboveAverage(string fileName)		//calculateAboveAverage function
{
	ifstream inFile;
	inFile.open("grade.txt");					//open file
	float average = calculateAverageGrade(fileName);  //declare average equals to function calculateAverageGrade that we already find the result
	int counter = 0;
	while(inFile)
	{
		float grade;
		inFile >> grade;
		if(inFile)
		{
			if (grade > average)		//grade is higher than average
			{			
				counter++;				//counter each grade one by one  to find all the grades that higher than average
			}
		}
	}
	return counter;	
}

int calculateBelowAverage(string fileName) 	//calculateBelowAverage function
{
	ifstream inFile;
	inFile.open("grade.txt");				//open file
	float average = calculateAverageGrade(fileName);
	int counter = 0;
	while(inFile)
	{
		float grade;
		inFile >> grade;
		if(inFile)
		{
			if (grade < average)		//grade is lower than average
			{
				counter++;			//counter each grade one by one to find all the grades that lower than average
			}
		}
	}
	return counter;
	
}






