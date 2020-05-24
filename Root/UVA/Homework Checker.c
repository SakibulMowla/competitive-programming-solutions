 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int a,b,c=0,d,l;
    char h1,h[100];
    while(scanf("%d%c%d=%s",&a,&h1,&b,h)==4)
    {
        l=strlen(h);
        if(l==1 && h[0]=='?')
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
