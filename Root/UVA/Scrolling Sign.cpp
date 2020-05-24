#include "stdio.h"
#include "string.h"

#define SZ  10101
#define SZ1 110

char str[SZ];
char sign[SZ];
char pre[SZ1];
char arr[SZ1];

int ans;
int par[SZ];

void kmp()
{
    int i, j, k, n, len;

    len = strlen(arr);

    strcpy(str, arr);
    strcat(str, sign);

    n = strlen(str);
    k = 0;
    memset(par, 0, sizeof(int)*(n+2));

    for(i=1;i<n;i++)
    {
        while(k > 0 && str[i] != str[k])
            k = par[k-1];
        if(str[i] == str[k]) k++;
        par[i] = k;
    }

    j = par[n-1];
//    printf("j = %d\n",j);
    n = strlen(sign);

    for(i=j;i<len;i++)
        sign[n++] = arr[i];
    sign[n] = '\0';

    ans += len - j;
}


int main()
{
    int t, hudai, m;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&hudai,&m);

        scanf("%s",&pre);
        strcpy(sign, pre);
        m--;
        ans = strlen(pre);

//        printf("ans = %d\n",ans);

        while(m--)
        {
            scanf("%s",&arr);
            if(strcmp(arr, pre) == 0) continue;

            kmp();

            strcpy(pre, arr);
        }

        printf("%d\n",ans);
    }

    return 0;
}




