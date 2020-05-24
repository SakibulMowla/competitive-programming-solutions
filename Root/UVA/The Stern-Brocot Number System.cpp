// _n = numerator && _d = denominator
#include <stdio.h>
#include <string.h>

int need_n, need_d , indx;
char path[10000];

void func(int cur_n,int cur_d,int L_n,int L_d,int R_n,int R_d)
{
    if(need_d == cur_d && need_n == cur_n)
        return;
    else if(need_n*cur_d < cur_n*need_d)
        path[indx++] = 'L' , func(cur_n+L_n , cur_d+L_d , L_n , L_d , cur_n , cur_d);
    else if(need_n*cur_d > cur_n*need_d)
        path[indx++] = 'R' , func(cur_n+R_n , cur_d+R_d , cur_n , cur_d , R_n , R_d);
}

int main()
{
    while(scanf("%d %d",&need_n,&need_d) == 2)
    {
        if(need_d == 1 && need_n == 1)break;
        indx = 0;
        func(1,1,0,1,1,0);
        path[indx] = '\0' ;
        printf("%s\n",path);
    }
    return 0;
}
