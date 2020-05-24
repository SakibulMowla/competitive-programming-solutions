#include "stdio.h"
#include "string.h"

int power[30] , alice[30] , bob[30];

int main()
{
    int i,j,k,n,m,t,sum1,sum2;
    char str[110] , arr1[110] , arr2[110];
    scanf("%d %s",&t,str);
    for(i=0;str[i];i++)
    {
        power[str[i]-'a'] = i;
    }
    while(t--)
    {
        memset(alice,0,sizeof(alice));
        memset(bob,0,sizeof(bob));
        scanf("%s %s",arr1,arr2);
        for(i=0;arr1[i];i++)
            alice[arr1[i]-'a']++;
        for(i=0;arr2[i];i++)
            bob[arr2[i]-'a']++;
        sum1 = sum2 = 0;
        for(i=0;i<26;i++)
        {
            if(alice[i] > bob[i]) alice[i] -= bob[i] , bob[i] = 0;
            else bob[i] -= alice[i] , alice[i] = 0;
        }
        for(i=0;i<26;i++)
            if(alice[i] && bob[i] == 0)
                sum1 += power[i];
        for(i=0;i<26;i++)
            if(bob[i] && alice[i] == 0)
                sum2 += power[i];
        if(sum1 == sum2) printf("TIE\n");
        else if(sum1 > sum2) printf("ALICE\n");
        else printf("BOB\n");
    }

    return 0;
}
