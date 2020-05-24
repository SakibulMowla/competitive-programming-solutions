#include<stdio.h>
#include<math.h>

int main()
{
    int n,c=0;
    double u,v,s,a,t;

    while((scanf("%d",&n))==1)
    {
        c++;
        if(n==0)
            break;
        else if(n==1)
        {
            scanf("%lf %lf %lf",&u,&v,&t);
            s=((u+v)/2)*t;
            a=(v-u)/t;
            printf("Case %d: %.3lf %.3lf\n",c,s,a);
        }
        else if(n==2)
        {
            scanf("%lf %lf %lf",&u,&v,&a);
            s=((v*v)-(u*u))/(2*a);
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",c,s,t);
        }
        else if(n==3)
        {
            scanf("%lf %lf %lf",&u,&a,&s);
            v=sqrt((u*u)+(2*a*s));
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",c,v,t);
        }
        else if(n==4)
        {
            scanf("%lf %lf %lf",&v,&a,&s);
            u=sqrt((v*v)-(2*a*s));
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",c,u,t);
        }
    }

    return 0;
}
