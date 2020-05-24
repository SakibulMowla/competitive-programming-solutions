#include<stdio.h>

int main()
{
    int sum,n,i,a,b,c,d,e,f,g;

    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        sum=0;
        scanf("%d%d%d%d%d%d%d",&d,&e,&f,&g,&a,&b,&c);
        sum=d+e+f+g;

        if(c<a && c<b)
            sum+=(a+b)/2;
        else if(b<a && b<c)
            sum+=(a+c)/2;
        else if(a<b && a<c)
            sum+=(c+b)/2;

        else if(a==b && b==c)
            sum+=(a+b)/2;

        else if(a==b)
            sum+=(a+c)/2;
        else if(a==c)
            sum+=(b+a)/2;
        else if(c==b)
            sum+=(a+c)/2;

        if(sum>=90)
            printf("Case %d: A\n",i+1);
        else if(sum>=80&&sum<90)
            printf("Case %d: B\n",i+1);
        else if(sum>=70&&sum<80)
            printf("Case %d: C\n",i+1);
        else if(sum>=60&&sum<70)
            printf("Case %d: D\n",i+1);
        else if(sum<60)
            printf("Case %d: F\n",i+1);
    }

    return 0;
}
