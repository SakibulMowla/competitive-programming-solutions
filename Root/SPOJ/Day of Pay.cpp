#include "stdio.h"

char ans[10][20] = {" ","Anjan","Sufian","Alim","Shipu","Sohel","Sumon"};

int main()
{
    int n,t=0;
    while(scanf("%d",&n) == 1 && n)
        printf("Case %d: %s\n",++t,ans[(n%6)+((n%6)==0?6:0)]);

    return 0;
}
