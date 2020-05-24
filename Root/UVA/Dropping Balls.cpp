            // 679 - Dropping Balls
#include <stdio.h>
#include <math.h>
int main()
{
    int D,I,pos,bin,test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&D,&I);
        I--;
        pos = pow(2,D-1);
        bin = pos / 2;
        while(I)
        {
            if(I%2 == 1)
                pos += bin;
            I /= 2;
            bin /= 2;
        }
        printf("%d\n",pos);
    }
    scanf("%d",&test);
    return 0;
}
