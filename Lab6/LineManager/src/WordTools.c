#include "WordTools.h"

void change2UpperCase(char *s)
{
    int i=0;
    while(s[i])
    {
        s[i]=toupper(s[i]);
        i++;
    }
};

void change2LowerCase(char *s)
{
    int i=0;
    while(s[i])
    {
        s[i]=tolower(s[i]);
        i++;
    }
};

void switchCase (char *s)
{
    int i=0;
    char* test;
    while(s[i])
    {
        test=tolower(s[i]);
        if(s[i]==test)
            s[i]=toupper(s[i]);
        else s[i]=tolower(s[i]);
        i++;
    }
};

void makeNames(char *s)
{
    int i=0;
    char* test=' ';
    while(s[i])
    {
        if(s[i-1]==test)
            s[i]=toupper(s[i]);
        else s[i]=tolower(s[i]);
        i++;
    }
};
