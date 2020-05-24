#include "stdio.h"
#include "string.h"

#define SZ 50010

char pat[SZ], txt[SZ];
int par[SZ];

void pre_process()
{
    int i, k, n;

    n = strlen(pat);
    k = 0;
    par[0] = 0;

    for(i=1; i<n; i++)
    {
        while(k>0 && pat[i] != pat[k])
            k = par[k-1];
        if(pat[i] == pat[k])
            k++;
        par[i] = k;
    }

    return ;
}

int KMP_search()
{
    pre_process();
    int i, k, n, len;

    n = strlen(txt);
    len = strlen(pat);
    k = 0;
    par[0] = 0;


    for(i=0; i<n; i++)
    {
        while(k > 0 && txt[i] != pat[k])
            k = par[k-1];
        if(txt[i] == pat[k])
            k++;
        if(k == len && i != n-1)
            k = par[k-1];
    }

    return k;
}


int main()
{
    int i, k;

    while(~scanf("%s %s",pat, txt))
    {
        k = KMP_search();
        if(!k)
            printf("0\n");
        else
        {
            for(i=0; i<k; i++)
                printf("%c",pat[i]);
            printf(" %d\n",k);
        }
    }

    return 0;
}


/*
aa aaa
ans = aa 2
*/

