#include<stdio.h>
#include<math.h>

int main()
{
    long long int a,b,c;

    while((scanf("%lld %lld %lld",&a,&b,&c))==3)
    {
        if(a==0 && b==0 &&c==0)
            break;
        if(a>b && a>c)
        {
            if(pow(b,2)+pow(c,2)==pow(a,2))
                printf("right\n");
            else
                printf("wrong\n");
        }

        else if(b>a && b>c)
        {
            if(pow(a,2)+pow(c,2)==pow(b,2))
                printf("right\n");
            else
                printf("wrong\n");
        }

        else if(c>a && c>b)
        {
            if(pow(a,2)+pow(b,2)==pow(c,2))
                printf("right\n");
            else
                printf("wrong\n");
        }
    }

    return 0;
}
