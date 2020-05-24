#include "stdio.h"
#define SZ 110

int arr[SZ];
char s[12];

int p, q, sum;

int fast()
{
    scanf("%s",s);
    sum = p = 0;
    q = 1;
    if(s[0] == '-') p++, q=-1;
    for(; s[p]; p++)
        sum = (sum * 10) + s[p] - '0';
    return sum*q;
}

int main()
{
    int t=0, test, tmp, i, j, n, m;
    char ch;

    scanf("%d",&test);

    while(test--)
    {
        n = fast();
        m = fast();
        for(i=0; i<n; i++)
            arr[i] = fast();
        while(m--)
        {
            scanf(" %c",&ch);
            if(ch == 'S')
            {
                j = fast();
                for(i=0; i<n; i++)
                    arr[i] += j;
            }
            else if(ch == 'M')
            {
                j = fast();
                for(i=0; i<n; i++)
                    arr[i] *= j;
            }
            else if(ch == 'D')
            {
                j = fast();
                for(i=0; i<n; i++)
                    arr[i] /= j;
            }
            else if(ch == 'R')
                for(i=0; i<n/2; i++)
                {
                    j = arr[i];
                    arr[i] = arr[n-i-1];
                    arr[n-i-1] = j;
                }
            else if(ch == 'P')
            {
                i = fast();
                j = fast();
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        printf("Case %d:\n%d",++t,arr[0]);
        for(i=1; i<n; i++)
            printf(" %d",arr[i]);
        printf("\n");
    }

    return 0;
}
