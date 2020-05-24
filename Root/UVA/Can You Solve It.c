//Assistance Outsbook http://www.outsbook.com/uva/?page=problem_hints&category=106&id=10642
#include <stdio.h>
#include <math.h>

int main()
{
    long i,up1,down1,up2,down2,n1,m1,max1,n2,m2,max2,test;
    int k=0;
    scanf("%ld",&test);
    while(test--)
    {
        scanf("%ld %ld %ld %ld",&up1,&down1,&up2,&down2);

        ++up1;++down1;++up2;++down2;

        m1=up1+down1-1;
        max1=m1*(m1+1)/2;
        n1=max1-down1+1;

        m2=up2+down2-1;
        max2=m2*(m2+1)/2;
        n2=max2-down2+1;

        printf("Case %ld: %ld\n",++k,n2-n1);
    }

    return 0;
}
