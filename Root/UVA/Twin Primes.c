#include <stdio.h>
#include <math.h>

typedef struct{
        long int tp1,tp2;
} data;

long int arr[20000010];
int main()
{
    data tp[100100];
    long int i,j,n,c;
    for(i=3;i<=sqrt(20000010);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<20000010;j+=i*2)
                arr[j]=1;
        }
    }

    c=0;

    for(i=3;i<20000010 && c < 100000;i+=2)
    {
        if(arr[i]==0 && arr[i+2]==0)
        {
            tp[c].tp1=i;
            tp[c].tp2=i+2;
            c++;
        }
    }

    while(scanf("%ld",&n)==1)
    {
        i=n-1;
        printf("(%ld, %ld)\n",tp[i].tp1,tp[i].tp2);
    }

    return 0;
}
