#include "stdio.h"
#include "string.h"

#define SZ  100010
#define SZ1 200010

char pat[SZ];
char str[SZ1];
int par[SZ1];

int kmp()
{
    int i, j, k, n, len;

    len = strlen(pat);

    for(i=0; i<len; i++)
        str[i] = pat[len-i-1];
    str[i] = '$';
    str[i+1] = '\0';
    strcat(str, pat);

    n = strlen(str);
    k = 0;
    memset(par, 0, sizeof(int)*(n+2));

    for(i=1;i<n;i++)
    {
        while(k>0 && str[i] != str[k])
            k = par[k-1];
        if(str[i] == str[k]) k++;
        par[i] = k;
    }

    return par[n-1];
}



int main()
{
    int i, j, len;

    while(~scanf("%s",&pat))
    {
        len = strlen(pat);
        j = kmp();
//        printf("j %d\n",j);

        printf("%s",pat);
        for(i=len-1-j;i>=0;i--)
            printf("%c",pat[i]);
        printf("\n");
    }

    return 0;
}
