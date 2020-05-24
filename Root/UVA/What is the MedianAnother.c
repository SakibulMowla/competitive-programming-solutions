#include <stdio.h>

long arr[10010];
int main()
{
    long m,res;
    int i,k=1;
    while(scanf("%ld",&m)==1)
    {
        for(i=k++;m<arr[i-1];i--)
        {
            arr[i]=arr[i-1];
        }
        arr[i]=m;
        if(k%2)
            res=(arr[k/2]+arr[k/2+1])/2;
        else
            res=arr[k/2];
        printf("%ld\n",res);
    }
    return 0;
}
