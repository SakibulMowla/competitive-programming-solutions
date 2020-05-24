#include <stdio.h>

long long arr[1000001];
void triangle(void)
{
    long long i,k=0;
    for(i=4;i<1000001;i++)
    {
        k+=(i-2)/2;
        arr[i]=k+arr[i-1];
    }
    return;
}

int main()
{
    triangle();
    int n;
    while(scanf("%d",&n)==1 && n>2)
        printf("%lld\n",arr[n]);
    return 0;
}
