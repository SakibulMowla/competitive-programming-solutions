#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n,j,z;
    scanf("%d",&i);
    for(j=0;j<i;j++)
    {
        scanf("%d",&n);
        z=abs((((((n*567)/9)+7492)*235)/47)-498);
        printf("%d\n",((z%100)/10));
    }

    return 0;
}
