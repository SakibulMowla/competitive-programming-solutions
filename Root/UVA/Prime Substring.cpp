#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SZ 100010

int prime[SZ];

void sieve()
{
    int i,j;
    prime[0] = prime[1] = 1;
    for(i=4;i<SZ;i+=2) prime[i] = 1;
    for(i=3;i<sqrt(SZ);i+=2)
        if(prime[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                prime[j] = 1;
}

int main()
{
    sieve();
    char str[300] , tmp[300];
    int i,j,num,maxim,len;
    while(scanf("%s",str) == 1)
    {
        if(strcmp(str,"0") == 0) break;
        maxim = 0;
        len = strlen(str);
        for(i=0;i<len;i++)
        {
            for(j=i;j<len && j-i<6;j++)
            {
                tmp[j-i] = str[j];
                tmp[j-i+1] = '\0';
                if(atoi(tmp)<100000 && prime[atoi(tmp)] == 0 && atoi(tmp) > maxim )
                    maxim = atoi(tmp);
            }
        }
        printf("%d\n",maxim);
    }

    return 0;
}
