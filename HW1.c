/*
 ============================================================================
 Name        : HW1.c
 Author      : Therese Smith/Hava Kantrowitz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"

int main(int argc, char*argv[]) {
	bool ok=false;// Later will be set true if production runs OK
	//puts("!!!Hello World We're working HW1!!!");
	//If all tests pass, go into production
	if(tests())
	{
		//Runs the production code, assigning value to ok
		ok=production(argc, argv);
		//If ok is true, let reader know
		if (ok)
		{
			puts("Production seems to have worked.");
		}
		//Else if ok isn't true, let reader know that as well
		else
		{
			puts("Production seems not to have worked.");
		}
	}
	//Else if 1+ tests fail, let reader know something went wrong
	else
	{
		puts("Something went wrong in the tests.");
	}
	return EXIT_SUCCESS;
}
