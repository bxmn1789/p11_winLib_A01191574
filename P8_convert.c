
#include "P8_convert.h"

//Carlo Borgo
//A01191574
//9/19/2016

//Convert

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//returns integer, corresponding to input string, that codifies a binary number; 
//string internal characters are '0' , '1', with a maximum length of 32. 
//finished by null or invalid characer.
int asciiBinaryToInt(char *s) {
	int iAcum = 0;
	while ((*s) && ((*s == '1') || (*s == '0'))) {
		iAcum *= 2;
		iAcum += (*s - '0');
		s++;
	}
	return iAcum;

}

//returns an integer, corresponding to an equivalent decimal number converted from a hexadecimal, 
//represented in sequence of characters in input string; consider that only alowed characters are from '0' to '9', from 'A' to 'F' and 
//from 'a' to 'f', with a maximum string length of 8 characters .. any invalid character will finish the conversion process, so the acumulated result 
//will be returned.
int asciiHEXToInt(char *s) {
	int iAcum = 0;

	while ((*s) && (((*s >= '0') && (*s <= '9')) || ((*s >= 'A') && (*s <= 'F')) ||
		((*s >= 'a') && (*s <= 'f')))) {
		*s = (char)toupper(*s);
		iAcum *= 16;
		if ((*s >= '0') && (*s <= '9'))
			iAcum += (*s - '0');
		else if ((*s >= 'A') && (*s <= 'F'))
			iAcum += (*s - '7');
		s++;
	}

	return iAcum;
}

//This routine returns a double precision float number, corresponding to an sequence of digit characters in the input string, 
//with the optional single appearance of the sign ('+' or '-') and decimal point ('.') to commit with a valid representation for a real number, 
//with integers and decimals; any invalid character will finish the conversion process, so the acumulated result will be returned.
double asciiToDouble(char *s) {
	int iPos = 1;
	double dAcum = 0;
	double dAft = 0.0;
	int iPow = 1;

	if (*s == '-') {
		iPos = 0;
		s++;
	}
	else if (*s == '+') {
		iPos = 1;
		s++;
	}

	while (*s != '.' || ((*s >= '0') && (*s <= '9'))) {
		dAcum *= 10;
		dAcum += (*s - '0');
		s++;
	}

	while (*s == '.' || ((*s >= '0') && (*s <= '9'))) {
		if ((*s >= '0') && (*s <= '9')) {
			dAft = dAft + ((*s - '0') / pow(10.0, iPow));
			iPow++;
		}
		s++;
	}

	dAcum = dAcum + dAft;

	if (!iPos)
		dAcum = -dAcum;

	return dAcum;
}


