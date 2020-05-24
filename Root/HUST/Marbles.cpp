#include "stdio.h"
#include "string.h"
#define SZ 510

double dp[SZ][SZ];

double solve(double red,double blue)
{
//    printf("rb = %d %d\n",(int)red,(int)blue);
    if(red >= blue) return 0.0;
    else if(red == 0.0) return 1.0;
    else if(blue == 0.0) return 0.0;
    double &ret = dp[(int)red][(int)blue];
    if(ret != -1) return ret;
    return ret = (red/(red+blue) * solve(red-1,blue-1)) + (blue/(red+blue) * solve(red,blue-2));
}

int main()
{
    int t=0,test,i,j;
    double r,b;
    for(i=0;i<SZ;i++) for(j=0;j<SZ;j++) dp[i][j] = -1;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lf %lf",&r,&b);
        printf("Case %d: %.10lf\n",++t,solve(r,b));
    }

    return 0;
}
