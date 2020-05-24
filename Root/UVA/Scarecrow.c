#include <stdio.h>
#include <string.h>

int main()
{
    int n,m,i,j,count,flag;
    char arr[110];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d\n",&m);
        gets(arr);
        flag=3;count=0;
        for(j=0;j<m;j++)
        {
            if(flag>=3)
            {
                if(arr[j]=='.')count++,flag=0;
            }
            flag++;
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}
