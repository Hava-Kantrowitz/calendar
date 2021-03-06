/*
 * production.c
 *
 *  Created on: Nov 3, 2018
 *      Author: Hava Kantrowitz
 *      @author Starter code Therese Smith
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include <math.h>

/** Your production code goes in this function.
 *
 * @param argc Number of words on the command line
 * @param argv Array of pointers to character strings representing the words on the command line.
 * @return true if Program was able to print a calendar.
 *         false if User entered bad input.
 */

bool production(int argc, char* argv[])
{
	bool results = false;
	bool done = false;
	int firstDay = -1; //the day of the week of the first day of the month, 0-6, initialized to -1

	//get the year, Usage as needed.
	int year = -1;
	puts("CALENDAR");

	//If there is no value on the command line, prompt user to add a year and scan it in
	if(argc<2)
	{
		puts("Enter a year");
		scanf("%d",&year);
		//If the user provides an invalid year, let user know and end production code
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	//Else take the value on command line and use it in program
	else
	{
		char* ptr=0;
		long year_l = strtol(argv[1],&ptr,10);
		year = (int)year_l;
		//If value is an invalid year, let user know and end production code
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	//If production code hasn't ended, print out the calendar
	if(!done)
	{
		//Loop goes through each month, printing out month name, week header, and days of week
		//Terminates after the last month of the year
		for (int month = 0; month <= 11; month++){
			switch(month){//Switch is used to print out full name of each month
			case 0:
				printf("January\n");
				break;
			case 1:
				printf("February\n");
				break;
			case 2:
				printf("March\n");
				break;
			case 3:
				printf("April\n");
				break;
			case 4:
				printf("May\n");
				break;
			case 5:
				printf("June\n");
				break;
			case 6:
				printf("July\n");
				break;
			case 7:
				printf("August\n");
				break;
			case 8:
				printf("September\n");
				break;
			case 9:
				printf("October\n");
				break;
			case 10:
				printf("November\n");
				break;
			case 11:
				printf("December\n");
				break;
			default://If the default case is hit, an out-of-bounds month was given as input
				printf("You done goofed somewhere\n");
				done = true;
			}

			printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");//week header, must be printed once a month

			//for loop to loop through each day of given month and print it properly formatted
			//Terminates after the last day of each month
			for (int day = 1; day <= calculate_days_in_month(year,month);day++){

				if (day == 1){
					firstDay = calculate_day_of_week(day, month, year);
					//switch to start the first day in the correct area of calendar
					switch (firstDay){

						case 0:
							printf("  %d  ", day);
							break;
						case 1:
							printf("       %d  ", day);
							break;
						case 2:
							printf("            %d  ", day);
							break;
						case 3:
							printf("                 %d  ", day);
							break;
						case 4:
							printf("                      %d  ", day);
							break;
						case 5:
							printf("                           %d  ", day);
							break;
						case 6:
							printf("                              ");
							break;
						default:
							printf("Invalid week bound hit.");
					}
				}


				//switch on the first day to determine where the new lines should be inserted,
				//dependent on what day of the week the first day of the month falls on
				//inserts a new line at the end of the first week and every 7 days after that
				switch(firstDay){
				//First day is a Sunday
				case 0:
					//First newline printed after 7 days
					if (day == 7){
						printf("  %d\n",day);
					}
					//If last day of month, newline
					else if (day == calculate_days_in_month(year,month)){
						printf(" %d\n", day);
										}
					//Newline printed every day divisible by 7
					else if (day % 7 == 0){
						printf(" %d\n",day);
					}
					//All other days not already accounted for
					else if (day != 1){
						number_digits(day);
					}

					break;
				//First day is a Monday
				case 1:
					//First newline after 6 days
					if (day == 6){
						printf("  %d\n",day);
					}
					//Newline after last day of month
					else if (day == calculate_days_in_month(year,month)){
						printf(" %d\n", day);
					}
					//Newline every day+1 divisible by 7
					else if ((day + 1) % 7 == 0){
						printf(" %d\n",day);
					}
					//All other days not already accounted for
					else if (day != 1){
						number_digits(day);
					}

					break;
				//First day is a Tuesday
				case 2:
					//First newline after 5 days
					if (day == 5){
						printf("  %d\n",day);
					}
					//Newline after last day of month
					else if (day == calculate_days_in_month(year,month)){
						printf(" %d\n", day);
					}
					//Newline every day+2 divisible by 7
					else if ((day + 2) % 7 == 0){
						printf(" %d\n",day);
					}
					//All other days not already accounted for
					else if (day != 1){
						number_digits(day);
					}

					break;
				//First day is a Wednesday
				case 3:
					//First newline after 4 days
					if (day == 4){
						printf("  %d\n",day);
					}
					//Newline after last day of month
					else if (day == calculate_days_in_month(year,month)){
						printf(" %d\n", day);
					}
					//Newline every day+3 divisible by 7
					else if ((day + 3) % 7 == 0){
						printf(" %d\n",day);
					}
					//All other days not already accounted for
					else if (day != 1){
						number_digits(day);
					}

					break;
				//First day is a Thursday
				case 4:
					//First newline after 3rd day
					if (day == 3){
						printf("  %d\n",day);
					}
					//Newline after last day of month
					else if (day == calculate_days_in_month(year,month)){
						printf(" %d\n", day);
					}
					//Newline every day+4 divisible by 7
					else if ((day + 4) % 7 == 0){
						printf(" %d\n",day);
					}
					//All other days not already accounted for
					else if (day != 1){
						number_digits(day);
					}

					break;
				//First day is a Friday
				case 5:
					//First newline after 2 days
					if (day == 2){
						printf("  %d\n",day);
					}
					//Newline after last day of month
					else if (day == calculate_days_in_month(year,month)){
						printf(" %d\n", day);
					}
					//Newline every day+5 divisible by 7
					else if ((day + 5) % 7 == 0){
						if (day/10 == 0){
							printf("  %d\n",day);
						}
						else {
							printf(" %d\n",day);
						}

					}
					//All other days not already accounted for
					else if (day != 1){
						number_digits(day);
					}
					break;
				//First day is a Saturday
				case 6:
					//Newline every day+6 divisible by 7
					if ((day + 6) % 7 == 0){
						if (day/10 == 0){//if the day has one digit, print two spaces before it
							printf("  %d\n",day);
						}
						else {//if the day has more than one digit (2 digits), print only one space before it
							printf(" %d\n",day);
						}
					}
					//Newline after last day of month
					else if (day == calculate_days_in_month(year,month)){
							printf(" %d\n", day);
					}
					//if the day has more than one digit (2 digits), print only one space before it
					else if (day != 1){
						number_digits(day);
					}

					break;
				//If you hit the default case, you have screwed up spectacularly
				//double-check the calculate_day_of_week function
				default:
					printf("You done goofed again, mister, day breaking is %d\n", day);
				}

			}

		}

	}
	//If production code hasn't ended, change results to true
	if(!done)
	{
		results=true;
	}
	return results;
}
/**
 * Determines and prints out how many spaces should appear before the day
 * @param day The day we are checking
 * Prints out the correct number of spaces before the day
 * 1 space for 2 digits
 * 2 spaces for 1 digit
 */
void number_digits(int day){

	if (day/10 == 0){ //if the day has one digit, print two spaces before it
		printf("  %d  ",day);
	}
	else{ //if the day has more than one digit (2 digits), print only one space before it
		printf(" %d  ",day);
	}
}

/** Calculates how many days are in a given month for a given year.
 * @param year The year we are checking.
 * @param month The month we are checking. Range 0 through 11, where January = 0.
 * @return An integer for the number of days in the month.
 *         -1 if invalid input (e.g., year < 1752, month out of range).
 */
int calculate_days_in_month(int year, int month)
{
	int answer = -3; //the number of days in the month, initialized to an invalid output
	bool done = false;

	if (year < 1752){ //if year is less than 1752, return -1 for invalid input
		answer = -1;
	}
	else {
		//if year is valid (> 1752), go into switch on month which provides the number of days in
		//the month
		switch(month){

		case 0:
			answer = 31;
			break;

		case 1:
			//if the year is a leap year, Feb has 29 days
			if (is_leap_year(year)){
				answer = 29;
			}
			else {//else it has 28 days
				answer = 28;
			}
			break;

		case 2:
			answer = 31;
			break;

		case 3:
			answer = 30;
			break;

		case 4:
			answer = 31;
			break;

		case 5:
			answer = 30;
			break;

		case 6:
			answer = 31;
			break;

		case 7:
			answer = 31;
			break;

		case 8:
			answer = 30;
			break;

		case 9:
			answer = 31;
			break;

		case 10:
			answer = 30;
			break;

		case 11:
			answer = 31;
			break;

		default://default is hit for invalid input, puts answer as -1
			answer = -1;
			break;
		}
	}

	return(answer);//return the number of days in the month
}
/** Test if a given year is a leap year or not.
 * @param year The year we are testing
 * @return 1 if it is a valid leap year.
 *         0 if a valid year, but not a leap year.
 *        -1 if not a valid year (i.e. before the calendar rule changed in 1752).
 */

int is_leap_year(int year)
{
	bool done = false;
	int ans = -2; //Start with an invalid answer

	if (year < 1752){//If year is less than 1752 (invalid), answer is -1
		ans = -1;
	}
	else if (year % 100 == 0 && year % 400 == 0){//if the year is divisible by 100 and 400, it's leap year
		ans = 1;
	}
	else if (year % 100 == 0){//if the year is only divisible by 100 (NOT 400), it's NOT a leap year
		ans = 0;
	}
	else if (year % 4 == 0){//if year is divisible by 4 (but NOT 100), it's a leap year
		ans = 1;
	}
	else {//any other case, it's NOT a leap year
		ans = 0;
	}

	return ans;//return whether (1) or not (0) the given year is a leap year, -1 if invalid year

}
/** Determines what day of the week a particular date falls on.
 * @param day Day of the month, counting from 1.
 * @param month Range 0 through 11, where January = 0.
 * @param year The year.
 * @return -1 for invalid input (e.g., year < 1752, month out of range,
 *            day < 1 or > appropriate for that month & year
 *         0 through 6, where Sunday = 0.
 *
 */
int calculate_day_of_week(int day, //first day of month is 1
		int month, //uses 0 for January
		int year)
{//invalid input gets a -1 answer
	int ans = -1;//start with invalid value
	bool done = false;

	int lastTwoDigits = year % 100;//the last two digits of the given year
	int firstTwoDigits = year / 100;//the first two digits of the given year
	int shiftedMonth = 0;//the shifted month needed for the week equation, initialized to 0
	double part1A = 0;//First calculated section of week equation, initialized to 0
	int part1 = 0;//Floor of part1A, initialized to 0
	double part2A = 0;//Second calculated section of week equation, initialized to 0
	int part2 = 0;//Floor of part2A, initialized to 0
	double part3A = 0;//Third calculated section of week equation, initialized to 0
	int part3 = 0;//Floor of part3A, initialized to 0
	int part4 = 0;//Fourth calculated section of week equation, initialized to 0
	int week = 0;//The week value before taking the mod of 7, initialized to 0

	//switch to change any given month to the shifted month used in week equation
	//For cases 0 and 1 (Jan and Feb), 1 is subtracted from the year
	//as per week equation
	switch(month){

	case 0:
		shiftedMonth = 11;
		year--;
		lastTwoDigits = year % 100;
		firstTwoDigits = year / 100;
		break;

	case 1:
		shiftedMonth = 12;
		year--;
		lastTwoDigits = year % 100;
		firstTwoDigits = year / 100;
		break;

	case 2:
		shiftedMonth = 1;
		break;

	case 3:
		shiftedMonth = 2;
		break;

	case 4:
		shiftedMonth = 3;
		break;

	case 5:
		shiftedMonth = 4;
		break;

	case 6:
		shiftedMonth = 5;
		break;

	case 7:
		shiftedMonth = 6;
		break;

	case 8:
		shiftedMonth = 7;
		break;

	case 9:
		shiftedMonth = 8;
		break;

	case 10:
		shiftedMonth = 9;
		break;

	case 11:
		shiftedMonth = 10;
		break;

	default://Hits when month is an invalid value, returns the invalid marker immediately;
		return -1;
	}

	//If the year or day are invalid, immediately return the invalid answer
	if (year < 1752 || day < 1 || day > 31){
		return -1;
	}
	else {

		//calculate each part of the week equation
		part1A = (2.6*shiftedMonth)-0.2;
		part1 = floor(part1A);
		part2A = lastTwoDigits/4;
		part2 = floor(part2A);
		part3A = firstTwoDigits/4;
		part3 = floor(part3A);
		part4 = 2*firstTwoDigits;

		week = day + part1 + lastTwoDigits + part2 + part3 - part4;
		ans = week % 7;

		//if the answer is negative, add 7 to it
		if (ans < 0){
			ans = ans + 7;
		}


	}

	return ans;//Return the day of the week, 0 as Sunday - 6 as Saturday
}

