#include <stdio.h>
#include <stdlib.h>
#include "manager.h"

int main(int argc, char * argv[])
{
    printf("argc: %d\n",argc);
    if (argc>2)
        LineManager(argv[argc-1],argv[argc-2]); // w konsoli: program /switch "text"
    else
        change2UpperCase(argv[argc-1]);
    int i = 0;
    for(i=0; argv[argc-1][i]; i++)
    {
        printf("%c",argv[argc-1][i]);
    }
    return 0;
}
