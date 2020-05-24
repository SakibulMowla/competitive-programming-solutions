#include <stdio.h>
#include <string.h>
#include <math.h>

int b2d(char *a)
{
    int num,i,j,len;
    len=strlen(a);
    num=0;
    for(i=0,j=len-1;i<len;i++,j--)
        if(a[i] == '1')
            num+=pow(2,j);

    return num;
}

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int i,test,num1,num2,res;
    char s1[35],s2[35];
    scanf("%d",&test);
    i=0;
    while(test--)
    {
        scanf("%s %s",s1,s2);
        num1 = b2d(s1);
        num2 = b2d(s2);
        res= gcd(num1,num2);
        if(res == 1)
            printf("Pair #%d: Love is not all you need!\n",++i);
        else
            printf("Pair #%d: All you need is love!\n",++i);
    }

    return 0;
}
