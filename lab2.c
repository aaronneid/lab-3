#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorial (unsigned short in);
void leapYear (int year);
void maximum (float max1, float max2);
void division (int numer, int denom);

int main (void){
	char choice = 'a';
	unsigned short in = 0;
	int year;
	float max1;
	float max2;
	int numer,denom;

	//loops the menu until zero is entered
	while(choice != 0){
		printf("Please choose an option from the menu below:\n1) Factorial of a Number \n2) Leap Year Calculator \n3) Maximum Number \n4) Division Operation \n>");
		scanf("%c",&choice);
		//fixes issues with scanf picking up the \n
		while(choice == '\n')
			scanf("%c",&choice);


		switch(choice){
			//exits if zero is entered
			case '0' :
				return;
			break;

			case '1' :
				printf("\nPlease enter a number to be factorialized: ");
				scanf("%hu",&in);
				factorial(in);
			break;

			case '2' :
				printf("\nPlease input a year (4 digit format) to determine if it is a leap year: ");
				scanf("%d",&year);
				leapYear(year);
			break;	
		
			case '3' :
				printf("\nPlease enter a number to be compared for maximum input: ");
				scanf("%f",&max1);
				printf("\nPlease enter the second number to be compared for maximum input: ");
				scanf("%f",&max2);
				maximum(max1,max2);	
			break;
	
			case '4' :
				printf("\nPlease input the numerator for division: ");
				scanf("%d",&numer);
				printf("\nPlease input the denominator for division: ");
				scanf("%d",&denom);
				division(numer,denom);
			break;
			
			//default case for if selection is not recognized
			default :
				printf("\nThat input was not valid, the menu will now reloop.  Input 0 to exit the program.\n\n");
		}
	}
}

void factorial (unsigned short in){
	unsigned long factorial = 1;
	int i;

	//makes sure the input is not too large
	//this will also be triggered if a negative number was input
	if(in > 13){
		printf("\nThe input is too high to be factorized! Please input a number between 1 and 13 next time.\n\n");
		return;
	}

	//calculates the factorial
	for(i = 1; i <= in; i++){
		factorial = factorial * i;	
	}

	//prints the factorial
	printf("\nThe factorial of %hu = %lu\n\n",in,factorial);

	return;
}

void leapYear(int year){
	int result = 0;

	//checks if year input was 0

	printf("The value of the input is: %hu",in);
	printf("There needs to be a way here to test for negative input -- test comment for lab 3");

	if(year == 0){
		printf("\nYear can not equal 0!\n\n");
		return;
	}

	//makes sure the input is 4 digits long
	//gets triggered if letters are input
	int numDigits = floor (log10 (abs(year))) + 1;
	if(numDigits != 4){
		printf("\nThe format for year was not correct! Please input a 4 digit year (0001 - 9999) next time.\n\n");
		return;
	}

	//checks if leap year through modulus
	result = year % 4;

	//displays result
	if(result == 0)
		printf("\nThe year %d is a leap year!\n\n",year);
	if(result != 0)
		printf("\nThe year %d is not a leap year!\n\n",year);

	return;
}

void maximum(float max1, float max2){

	//checks special case inputs are the same
	if(max1 == max2){
		printf("\n%.2f = %.2f\n",max1,max2);
		return;
	}
	
	//checks for the max input and displays the correct result
	(max1 > max2)?printf("\n%.2f > %.2f\n\n",max1,max2):printf("\n%.2f > %.2f\n\n",max2,max1);
	return;
}

void division(int numer, int denom){
	float result = 0;
	
	//checks for special case divisor is zero
	if(denom == 0){
		printf("Can't divide by zero! The denominator can not be zero.\n\n");
		return;
	}

	//caluculates division
	result = (float)numer / (float)denom;
	
	//prints result
	printf("\nThe result of %d / %d = %.2f\n\n",numer,denom,result);

	return;
}
