#include<stdio.h>
#include<string.h>

int main(void)
{
    char arr[10],z;
    long long int n,i,j,m,k,sum,c;
    scanf("%lld",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lld%c",&m,&z);
        sum=0;

        c=0;
        for(k=0; k<m; k++)
        {
            scanf("%s",arr);

            if(strcmp("donate",arr)==0)
            {
                scanf("%lld",&j);
                sum+=j;
            }

            else if(strcmp("report",arr)==0)
            {
                if(c==0)
                    printf("Case %lld:\n",i+1);
                printf("%lld\n",sum);
                c++;
            }
        }
    }

    return 0;
}
