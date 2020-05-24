#include <cstdio>
#include <cstring>

int main()
{
    long n,m,i,j,k,l,sum,len;
    char p[2010],z;
    scanf("%ld",&k);
    for(l=0;l<k;l++)
    {
        scanf("%ld%c%s",&n,&z,p);
        len=strlen(p);
        sum=0;
        for(i=0;i<len;i++)
        {
            sum=(sum*10+(p[i]-'0'))%n;
        }
        printf("%ld\n",sum);
    }

    return 0;
}
