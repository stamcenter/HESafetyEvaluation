#include <stdio.h>

using namespace std;

bool is_dec_char(char c)
{
	return c >= '0' && c <= '9';
}

int get_dec_value(char c)
{
	return c - '0';
}
        
int get_coeff_power(unsigned char *poly, unsigned int *power_length)
{
	int length = 0;
	if (*poly == '\0')
    {
        *power_length = 0;
        return 0;
    }
    if (*poly != 'x')
    {
        return -1;
    }
    poly++;
    length++;

    if (*poly != '^')
    {
        return -1;
    }
    poly++;
    length++;

    int power = 0;
    while (is_dec_char(*poly) && length <4)
    {
        power *= 10;
        power += get_dec_value(*poly);
        poly++;
        length++;
    }
    *power_length = length;
    return power;
}
