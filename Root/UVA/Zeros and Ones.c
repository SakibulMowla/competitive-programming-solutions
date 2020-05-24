#include <stdio.h>
#include <string.h>

int check[1000010];
int main(void)
{
    int i,j,k,l,n,m,len,c,t;
    char arr[1000010];

    l=0;
    while(scanf("%s",arr)!=EOF)
    {
        len=strlen(arr);
        if(len==1 && arr[0]=='\n')
            break;

        for(i=1;i<len;i++)
        {
            if(arr[i]!=arr[i-1])
                check[i]=check[i-1]+1;
            else
                check[i]=check[i-1];
        }
        scanf("%d",&k);
        printf("Case %d:\n",l+1);
        for(i=0;i<k;i++)
        {
            scanf("%d %d",&n,&m);
            if(check[n]==check[m])
                printf("Yes\n");
            else
                printf("No\n");
        }
        for(i=0;i<1000010;i++)
            check[i]=0;

        l++;
    }
    return 0;
}
