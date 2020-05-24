#include <stdio.h>
#include <string.h>

#define int64 long long

int main()
{
    int64 a,b,c,d,l,i,count;
    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&l) == 5)
    {
        if(a==0 && b==0 && c==0 && d==0 && l==0)
            break;
        count=0;
        for(i=0;i<=l;i++)
        {
            if((a*i*i + b*i + c) % d == 0)
                count++;
        }
        printf("%d\n",count);
    }

    return 0;
}
