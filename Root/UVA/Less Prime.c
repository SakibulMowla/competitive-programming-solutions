#include <stdio.h>
#include <math.h>

int arr[10010];
int main()
{
    int n,m,i,j,l;
    arr[0]=arr[1]=1;
    for(i=2;i<10010;i+=2)
        arr[i]=1;
    for(i=3;i<=sqrt(10010);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<10010;j+=i*2)
                arr[j]=1;
        }
    }
    scanf("%d",&n);
    for(l=0;l<n;l++)
    {
        scanf("%d",&m);
        for(i=(m/2)+1;i<10010;i++)
        {
            if(arr[i]==0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }

    return 0;
}
