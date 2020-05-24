#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    long int n,i,j,k,a[3],temp;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld %ld %ld",&a[0],&a[1],&a[2]);
        for(j=0;j<2;j++)
        {
            for(k=j+1;k<3;k++)
            {
                if(a[j]>a[k])
                {
                    temp=a[j];
                    a[j]=a[k];
                    a[k]=temp;
                }
            }
        }
        if(a[0]==1 && a[1]==1 && a[2]==1)
            printf("Case %ld: no\n",i+1);
        else if((a[0]*a[0]) + (a[1]*a[1]) == (a[2]*a[2]))
            printf("Case %ld: yes\n",i+1);
        else
            printf("Case %ld: no\n",i+1);
    }

    return 0;
}
