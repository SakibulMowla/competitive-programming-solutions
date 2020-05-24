#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SZ 1000000

char txt[SZ+5] , pat[SZ+5];
int lps[SZ+5];

void pre_process()
{
    int j,len,M;
    M = strlen(pat);
    len = 0;
    lps[0] = 0;

    for(j=1;j<M;j++)
    {
        while(len > 0 && pat[len] != pat[j])
            len = lps[len-1];
        if(pat[len] == pat[j])
            len++;
        lps[j] = len;
    }
    return;
}

int KMP_search()
{
    pre_process();

    int i,j,n,m,cnt;
    n = strlen(txt);
    m = strlen(pat);
    cnt = 0;
    i = 0; //index of txt
    j = 0; //index of pat
    for(i=0;i<n;i++)
    {
        while(j > 0 && txt[i] != pat[j])
            j = lps[j-1];
        if(pat[j] == txt[i])
            j++;
        if(j == m)
        {
            cnt++;
            j = lps[j-1];
//            printf("i = %d\n",i);
        }
    }

    return cnt;
}


int main()
{
    int t,test;
    t = 0;
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        gets(txt) , gets(pat);
        printf("Case %d: %d\n",++t,KMP_search());
    }

    return 0;
}
