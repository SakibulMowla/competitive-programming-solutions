#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    long long int a,b,n,i,count,test=1,c,m;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
        break;
        count=0;
        n=sqrt(a);
        n++;
        i=n*n;
        while(1)
        {
            if(i>=b)
            break;
            m=i;
            c=(sqrt(1+8*m)-1)/2;
            c=c*(c+1);
            c/=2;
            if(c==m)
            count++;
            n++;
            i=n*n;
        }
        printf("Case %lld: %lld\n",test++,count);
    }
    return 0;
}
