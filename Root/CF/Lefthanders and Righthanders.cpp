#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int i,n,j;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char arr[110];
    while(scanf("%d",&n) == 1)
    {
        for(i=1;i<=n;i++)
            scanf(" %c",&arr[i]);
        for(i=1;i<=n/2;i++)
        {
            j = (n/2)+i;
            if(arr[i] == 'L' && arr[j]=='L')
                printf("%d %d\n",i,j);
            if(arr[i] =='R' && arr[j] == 'R')
                printf("%d %d\n",i,j);
            if(arr[i]=='L' && arr[j] == 'R')
                printf("%d %d\n",i,j);
            if(arr[i] =='R' && arr[j]=='L')
                printf("%d %d\n",j,i);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
