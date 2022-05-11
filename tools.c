#include "main.h"
/**
 *
 *
 *
 */
int isnum(char *integer)
{
        int i = 0;
        
        for(i = 0; integer[i]; i++)
        {
                if (integer[i] < 48 || integer[i] > 57)
                        return (-1);
        }
        return (0);     
}

