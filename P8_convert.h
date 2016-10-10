#pragma once
int asciiBinaryToInt(char *s);


//returns an integer, corresponding to an equivalent decimal number converted from a hexadecimal, 
//represented in sequence of characters in input string; consider that only alowed characters are from '0' to '9', from 'A' to 'F' and 
//from 'a' to 'f', with a maximum string length of 8 characters .. any invalid character will finish the conversion process, so the acumulated result 
//will be returned.
int asciiHEXToInt(char *s);

//This routine returns a double precision float number, corresponding to an sequence of digit characters in the input string, 
//with the optional single appearance of the sign ('+' or '-') and decimal point ('.') to commit with a valid representation for a real number, 
//with integers and decimals; any invalid character will finish the conversion process, so the acumulated result will be returned.
double asciiToDouble(char *s);
