#include <stdio.h>
#include <math.h>

int main()
{
    int test,a,b,steps,dif,plus,now;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&a,&b);
        dif = b - a;
        steps = 0;
        if(dif > 0)
        {
            now = 0;
            plus = 2;
            while(now < dif)
            {
                now += plus / 2;
                plus++;
                steps++;
            }
        }
        printf("%d\n",steps);
    }

    return 0;
}
