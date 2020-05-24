#include<stdio.h>
#include<math.h>

int main(void)
{
    int i,j,k,n;
    long long int res,root;
    scanf("%d",&j);
    for(k=0; k<j; k++)
    {
        scanf("%d",&n);

        root=sqrt(n);
        res = 0;

        for(i = 1; i<=root ; i++)
        {
            res = res + n/i ;
        }

        res=2*res - root*root;
        printf("%lld\n",res);
    }

    return 0;
}
