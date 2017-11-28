#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int allChars[256], i, min = 256, max = 0;
    i=0;
    for (i=0; i<256; i++) allChars[i]=0;
    i=0;
    while(argv[argc-1][i])
    {
        int c = argv[argc-1][i];
        allChars[c]++;
        i++;
//        printf("zwiekszylem wartosc %c\n",c);
        if (allChars[c]>max) max = c;
        else if (allChars[c]<min) min = c;
    };
//    for (i=0;i<256;i++) printf("%d ",allChars[i]);
    if (argc>2)
    {
        if (argv[argc-2][1]=='L')
            printf("Najmniej razy wystapilo: %c",max);
    }
    else    printf("Najwiecej razy wystapilo: %c",min);
    return 0;
}
