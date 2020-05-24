#include <stdio.h>
#include <math.h>

int main(void)
{
    int a,b,c,d,m;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
    {
        if(a==0 &&b==0 &&c==0 &&d==0)
            break;
        else if(a==c && b==d)
        m=0;
        else if(a==c || b==d || (abs(a-c)==abs(b-d)) )
        m=1;
        else
        m=2;
        printf("%d\n",m);
    }
    return 0;
}
