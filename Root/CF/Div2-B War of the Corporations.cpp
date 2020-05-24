#include "stdio.h"
#include "string.h"

#define SZ  100010
#define SZ1 100010

char pat[SZ], txt[SZ1];
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

    int i, k, n, len, ans;

    n = strlen(txt);
    len = strlen(pat);
    ans = 0;
    k = 0;

    for(i=0; i<n; i++)
    {
        while(k > 0 && txt[i] != pat[k])
            k = par[k-1];
        if(txt[i] == pat[k])
            k++;
        if(k == len)
        {
            ans++;
            k = 0;
        }
    }

    return ans;
}


int main()
{
//    int t;
//
//    scanf("%d",&t);
//
//    while(t--)
//    {
        scanf("%s %s",txt,pat);
        printf("%d\n",KMP_search());
//    }

    return 0;
}
