#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c,temp,r,rc,v,y,k,t,af;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3)
    {
        k=(a+b+c)/2;
        t=sqrt(k*(k-a)*(k-b)*(k-c));
        rc=t/k;
        r=acos(-1)*rc*rc;
        v=t-r;
        af=acos(-1)*(a*b*c)*(a*b*c)/sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c))/sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c));
        y=af-v-r;
        printf("%.4lf %.4lf %.4lf\n",y,v,r);
    }
    return 0;
}
