#include <stdio.h>
#include <string.h>

#define max 10000
#define maximum(a,b) a>b?a:b

int arr1[max];
int arr2[max];
int str[max][max];

int main()
{
    int n,i,j,pos;
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        scanf("%d",&pos);
        arr1[pos]=i;
    }

    while(scanf("%d",&pos)==1)
    {
        arr2[pos]=1;
        for(i=2; i<=n; i++)
        {
            scanf("%d",&pos);
            arr2[pos]=i;
        }

        for(i=2; i<=n+1; i++)
        {
            for(j=2; j<=n+1; j++)
            {
                if(arr1[i-1]==arr2[j-1])
                    str[i][j]=str[i-1][j-1] + 1;
                else
                    str[i][j]=maximum( str[i-1][j] , str[i][j-1] );
            }
        }

        printf("%d\n",str[n+1][n+1]);
    }
    return 0;
}
