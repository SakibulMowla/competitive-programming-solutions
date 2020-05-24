#include <stdio.h>
#include <string.h>

int arr[10000+10],n;
void heap(void)
{
    int i,j,k,temp;
    for(k=2; k<=n; k++)
    {
        i=k;
        temp=arr[k];
        j=(int)(i/2);

        while((i>1) && (temp > arr[j]))
        {
            arr[i]=arr[j];
            i=j;
            j=(int)(i/2);

            if(j<1)
                j=1;
        }
        arr[i]=temp;
    }
    return;
}

void heapsort(void)
{
    int i,j,k,temp,sort;
    heap();

    for(k=n; k>=2; --k)
    {
        i=1;
        j=2;
        temp=arr[1];
        arr[1]=arr[k];
        arr[k]=temp;

        sort=arr[1];
        if((j+1) < k)
        {
            if(arr[j+1] > arr[j])
            {
                j+=1;
            }
        }
        while(j<=k-1 && arr[j] > sort)
        {
            arr[i]=arr[j];
            i=j;
            j=2*i;
            if(j+1 < k)
            {
                if(arr[j+1] > arr[j])
                {
                    j+=1;
                }
                else if(j > n)
                {
                    j=n;
                }
            }
            arr[i]=sort;
        }
    }
    return;
}

int main()
{
    int i,ans;
    n=1;
    while(scanf("%d",&arr[n])==1)
    {
        heapsort();
        if(n%2==1)
            ans=arr[ (n/2) + 1 ];
        else
            ans=( arr[n/2] + arr[ (n/2) + 1 ] ) / 2;
        printf("%d\n",ans);
        ++n;
    }
    return 0;
}
