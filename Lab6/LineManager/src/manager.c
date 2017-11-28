#include "manager.h"
#include <ctype.h>  // dla funkcji toupper i tolower




void LineManager(char* input, char* mod)
{
    int i = mod[1];
    switch(i)
    {
    case 'l': case 'L':
        change2LowerCase(input);
        break;
    case 's': case 'S':
        switchCase(input);
        break;
    case 'n': case 'N':
        makeNames(input);
        break;
    default:
        change2UpperCase(input);
        break;
    }
};
