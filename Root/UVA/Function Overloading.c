#include <stdio.h>
#include <string.h>
#include <math.h>


#define max 10000000+10

int arr[max],count[max];

int main()
{
    int i,j,n,len,a,b,ans;
    char z,line[100];

    for(i=1; i<max; i++)
    {
        char p[100];
        int len,j,sum;

        len=sprintf(p,"%d",i);
        sum=0;

        for(j=0; j<len; j++)
            sum+=p[j]-'0';

        if(arr[i+sum] == 0)
            arr[i+sum]=i;
        if(arr[i] == 0)
            count[i]=count[i-1] + 1;
        else
            count[i]=count[i-1];
    }

    count[0]=0;

    scanf("%d%c",&n,&z);
    for(i=0; i<n; i++)
    {
        gets(line);

        len=sscanf(line,"%d %d",&a,&b);

        if(len==1)
        {
            if(arr[a]!=0)
                ans=arr[a];
            else
                ans=-1;
        }

        else if(len==2)
        {
            ans=count[b]-count[a-1];
        }

        printf("Case %d: %d\n",i+1,ans);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>


#define max 10000000+10

int arr[max],count[max];

int main()
{
    int i,j,n,len,a,b,ans;
    char z,line[100];

    for(i=1; i<max; i++)
    {
        char p[100];
        int len,j,sum;

        len=sprintf(p,"%d",i);
        sum=0;

        for(j=0; j<len; j++)
            sum+=p[j]-'0';

        if(arr[i+sum] == 0)
            arr[i+sum]=i;
        if(arr[i] == 0)
            count[i]=count[i-1] + 1;
        else
            count[i]=count[i-1];
    }

    count[0]=0;

    scanf("%d%c",&n,&z);
    for(i=0; i<n; i++)
    {
        gets(line);

        len=sscanf(line,"%d %d",&a,&b);

        if(len==1)
        {
            if(arr[a]!=0)
                ans=arr[a];
            else
                ans=-1;
        }

        else if(len==2)
        {
            ans=count[b]-count[a-1];
        }

        printf("Case %d: %d\n",i+1,ans);
    }

    return 0;
}
