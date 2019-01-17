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

	//get the year, Usage as needed.
	int year = -1;
	puts("CALENDAR");
	if(argc<2)
	{
		puts("Enter a year");
		scanf("%d",&year);
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	else
	{
		char* ptr=0;
		long year_l = strtol(argv[1],&ptr,10);
		year = (int)year_l;
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	if(!done)
	{

		for (int month = 0; month <= 11; month++){
			switch(month){
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
			default:
				printf("You done goofed somewhere\n");
				done = true;
			}
			printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
			for (int day = 1; day <= calculate_days_in_month(year,month);day++){

				if (day/10 == 0){
					printf("  %d  ",day);
				}
				else{
					printf(" %d  ",day);
				}

				if (day % 7 == 0 || day == calculate_days_in_month(year,month)){
					printf("\n");
				}

			}

		}



	}
	if(!done)
	{
		results=true;
	}
	return results;
}

/** Calculates how many days are in a given month for a given year.
 * @param year The year we are checking.
 * @param month The month we are checking. Range 0 through 11, where January = 0.
 * @return An integer for the number of days in the month.
 *         -1 if invalid input (e.g., year < 1752, month out of range).
 */
int calculate_days_in_month(int year, int month)
{
	int answer = -3;
	bool done = false;

	if (year < 1752){
		answer = -1;
	}
	else {
		switch(month){

		case 0:
			answer = 31;
			break;

		case 1:
			if (is_leap_year(year)){
				answer = 29;
			}
			else {
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

		default:
			answer = -1;
			break;
		}
	}

	return(answer);
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

	if (year < 1752){
		ans = -1;
	}
	else if (year % 100 == 0 && year % 400 == 0){
		ans = 1;
	}
	else if (year % 100 == 0){
		ans = 0;
	}
	else if (year % 4 == 0){
		ans = 1;
	}
	else {
		ans = 0;
	}

	return ans;

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
	int ans = -1;
	bool done = false;

	int lastTwoDigits = year % 100;
	int firstTwoDigits = year / 100;
	int shiftedMonth = 0;
	double part1A;
	int part1 = 0;
	double part2A = 0;
	int part2 = 0;
	double part3A = 0;
	int part3 = 0;
	int part4 = 0;
	int week = 0;

	switch(month){

	case 0:
		shiftedMonth = 11;
		lastTwoDigits--;
		break;

	case 1:
		shiftedMonth = 12;
		lastTwoDigits--;
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

	default:
		shiftedMonth = -1;
		return ans;
	}

	if (year < 1752 || day < 1 || day > 31){
		return ans;
	}
	else {

		part1A = (2.6*shiftedMonth)-0.2;
		part1 = floor(part1A);
		part2A = lastTwoDigits/4;
		part2 = floor(part2A);
		part3A = firstTwoDigits/4;
		part3 = floor(part3A);
		part4 = 2*firstTwoDigits;

		week = day + part1 + lastTwoDigits + part2 + part3 - part4;
		ans = week % 7;

		if (ans < 0){
			ans = ans + 7;
		}

		//Offset by 6 for the year 2000
		if (year == 2000){
			ans = ans + 6;
		}

	}

	return ans;
}

