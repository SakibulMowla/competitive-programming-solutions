//From https://sites.google.com/site/programinggconcept/algorithm
//Trying to find out in how many ways I can make money from 1 to 8 having two coins of 2 & 4 taka


#include <stdio.h>
#include <string.h>

int main()
{
    int coins[5]={2,4};
    int cent,total,i,j,k;
    int nways[10];

    memset(nways,0,sizeof(nways));
    nways[0]=1;
    for(i=0;i<2;i++)//because I have 2 coins so the loop is iterating for 2 times
    {
        for(j=coins[i],k=0;j<=8;j++,k++)//for counting ways to make 1 to 8 taka loop is iterating for 8 times
        {
            nways[j]=nways[j]+nways[k];
        }
    }

    while(scanf("%d",&cent)==1)
    {
        printf("Ways = %d\n",nways[cent]);
    }

    return 0;
}
