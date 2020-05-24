#include <stdio.h>
#include <string.h>

#define N 110
#define max(a,b) a>b?a:b

int arr1[N],arr2[N],str[N][N];
int main()
{
    int t,n1,n2,i,j;
    t=1;
    while(scanf("%d %d",&n1,&n2)==2 && n1 && n2)
    {
        for(i=0;i<n1;i++)
            scanf("%d",&arr1[i]);
        for(j=0;j<n2;j++)
            scanf("%d",&arr2[j]);
        for(i=1;i<=n1;i++)
        {
            for(j=1;j<=n2;j++)
            {
                if(arr1[i-1]==arr2[j-1])
                    str[i][j]=str[i-1][j-1]+1;
                else
                    str[i][j]=max(str[i-1][j],str[i][j-1]);
            }
        }
        printf("Twin Towers #%d\n",t);
        printf("Number of Tiles : %d\n",str[n1][n2]);
        printf("\n");
        t++;
        memset(str,0,sizeof str);
    }

    return 0;
}
