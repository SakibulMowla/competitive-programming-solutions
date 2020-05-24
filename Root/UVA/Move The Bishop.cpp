#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t,test,i,a,b,c,d,limit,n;

    scanf("%d",&test);
    for(t=0;t<test;t++)
    {
        scanf("%d %d",&n,&limit);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            if(a<0 || a>limit || b<0 || b>limit || c<0 || c>limit || d<0 || d>limit )
                printf("no move\n");
            else if(a==c && b==d)
                printf("0\n");
            else if(abs(a-c)==abs(b-d))
                printf("1\n");
            else if( (abs(a-c)%2==0 && abs(b-d)%2==0) || (abs(a-c)%2==1 && abs(b-d)%2==1))
                printf("2\n");
            else
                printf("no move\n");
        }
    }

    return 0;
}
