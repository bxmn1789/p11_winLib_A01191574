// P9_MallocLib.c : Defines the exported functions for the DLL application.
//

//Carlo Borgo
//A01191574
//9/24/2016

//Malloc

#include "P9_malloc.h"

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//gets large string using pointers
char* getExtremelyLargeString() {
	int iPnt = 0;
	int iBytes = 1000;
	int iKBytes = 1;
	char chAdd=' ';
	char* cpS = malloc((sizeof(char))*iKBytes * 1000);

	while (chAdd != '$') { //escape character is $
		if (iPnt >= (iBytes*iKBytes - 1)) {
			iKBytes++;
			cpS = realloc(cpS, sizeof(char)*iKBytes*iBytes);
		}
		chAdd = getchar();
		if (chAdd == '$') {
			*(cpS + iPnt) = '\0';
		}
		else {
			*(cpS + iPnt) = chAdd;
			iPnt++;
		}
	}
	return cpS;
}


