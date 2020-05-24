#include <stdio.h>

int main()
{
    int a,b,c,p,deg,deg1,deg2,deg3;
    while(scanf("%d%d%d%d",&p,&a,&b,&c)==4)
    {
        if(!p && !a && !b && !c) break;
        deg1=(a>p ? (40-a)+p : p-a)*9;
        deg2=(b<a ? (40-a)+b : b-a)*9;
        deg3=(c>b ? (40-c)+b : b-c)*9;
        deg=720+360+deg1+deg2+deg3;
        printf("%d\n",deg);
    }
    return 0;
}
