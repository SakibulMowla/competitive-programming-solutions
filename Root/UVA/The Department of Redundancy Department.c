#include <stdio.h>

typedef struct
{
    int num;
    int count;
} data;

data arr[100000];

int main()
{
    int i,k,n,m;
    m=0;
    while(scanf("%d",&n)==1)
    {
        k=0;
        for(i=0; i<m; i++)
        {
            if(arr[i].num==n)
            {
                arr[i].count++;
                k=1;
                break;
            }
        }
        if(k==0)
        {
            arr[m].num=n;
            arr[m].count=1;
            m++;
        }
    }
    for(i=0;i<m;i++)
        printf("%d %d\n",arr[i].num,arr[i].count);

    return 0;
}
