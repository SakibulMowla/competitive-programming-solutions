#include "stdio.h"
#include "string.h"

#define SZ  1000010
#define SZ1 2000010

char str[SZ1];
char txt1[SZ], txt2[SZ];
int par[SZ1];


void kmp()
{
    int i, j, k, n, len, ans;

    len = strlen(txt1);

    for(i=0; i<len; i++)
        txt2[i] = txt1[len-i-1];
    txt2[i] = '\0';

    strcpy(str, txt1);
    strcat(str, "$");
    strcat(str, txt2);

    n =strlen(str);
    k = 0;
    par[0] = 0;
    ans = -1;

    for(i=1; i<=n; i++)
    {
        while(k>0 && str[i] != str[k])
            k = par[k-1];

        if(str[i] == str[k]) k++;

        par[i] = k;

        if(k > ans && i-k>=len)
            ans = k;
    }

    if(k > ans && i-k>=len)
        ans = k;

    for(i=ans-1;ans;i--,ans--)
        printf("%c",txt1[i]);
    printf("\n");
}


int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",txt1);
        kmp();
    }

    return 0;
}


/*
1
abcabc
ans = a
*/
