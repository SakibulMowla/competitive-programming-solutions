#include <stdio.h>
#include <string.h>

#define SZ  10010
#define SZ1 1000010
#define SZ2 SZ+SZ1

char pat[SZ], txt[SZ1], str[SZ2];
int par[SZ2];

int kmp()
{
    strcpy(str, pat);
    strcat(str, "#");
    strcat(str, txt);

    int i, k, n, ans, len;

    n = strlen(str);
    len = strlen(pat);
    k = 0;
    par[0] = 0;
    ans = 0;

    for(i=1; i<n; i++) // starting from first index to prevent "pat" to match with its' own occurance in "str"
    {
        while(k>0 && str[i] != str[k])
            k = par[k-1];
        if(str[i] == str[k]) k++;
        par[i] = k;
        if(k == len)
            ans++;
    }

    return ans;
}


int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s %s",pat,txt);
        printf("%d\n",kmp());
    }

    return 0;
}
