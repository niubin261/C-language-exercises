#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    char str[] ="192.168.109.192";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," .");////-->192\0168.109.192
    while (pch != NULL)
    {
        int pchnum=atoi(pch);
        printf("%d\n",pchnum);
        printf ("%s\n",pch);
        pch = strtok (NULL, " .");

    }

    return 0;
}
