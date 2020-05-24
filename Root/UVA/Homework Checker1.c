#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,l;
    char h[100],h1;
    while(scanf("%s",h)==1)
    {
        c=0;
        l=strlen(h);
        if(l==1 && h[0]==63)
            continue;
        d=atoi(h);
        if(h1=='+')
        {
            if((a+b)==d)
                c++;
        }
        else if(h1=='-')
        {
            if((a-b)==d)
                c++;
        }
    }
    printf("%d\n",c);

    return 0;
}

