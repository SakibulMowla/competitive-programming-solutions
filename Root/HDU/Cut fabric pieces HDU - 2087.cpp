#include "stdio.h"
#include "string.h"

#define SZ  1010
#define SZ1 2010

char pat[SZ];
char txt[SZ];
char str[SZ1];
int par[SZ1];

int kmp()
{
    int i, k, n, len, ans;

    strcpy(str, pat);
    strcat(str, "#");
    strcat(str, txt);

    n = strlen(str);
    k = 0;
    ans = 0;
    memset(par, 0, sizeof(int)*(n+2));
    len = strlen(pat);

    for(i=1; i<n; i++) // always starts from 1
    {
        while(k>0 && str[i] != str[k])
            k = par[k-1];
        if(str[i] == str[k]) k++;

        if(k == len)
            k = 0, ans++;

        par[i] = k;
    }

    return ans;
}


int main()
{
    while(scanf("%s",txt) == 1)
    {
        if(strcmp(txt,"#") == 0) break;
        scanf("%s",pat);

        printf("%d\n",kmp());
    }

    return 0;
}
