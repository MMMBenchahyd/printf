#include "main.h"


int printnumbr(int num)
{
    int h = 0, i = 0;
    int temp = num; 
	char a_of_d[1024];
    if (temp < 0)
    {
        temp *= -1; 
	write(1, "-", 1);
    }
    while (temp > 0)
    {
        a_of_d[i++] = (temp % 10) + '0';
        temp /= 10;
        h++;
    }
    while (i >= 0)
	    write(1, &a_of_d[--i], 1);

    return (h);
}
