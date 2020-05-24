#include<stdio.h>

int ugly[1500];
int a,b,c,A,B,C;
int i=1;

int main(void)
{
    ugly[0]=1;
    while(ugly[1499]==0)
    {
        A=ugly[a]*2;
        B=ugly[b]*3;
        C=ugly[c]*5;
        if(A<B && A<C)
        {
            ugly[i]=A;
            i++;a++;
        }
        else if(B<A && B<C)
        {
            ugly[i]=B;
            i++;b++;
        }
        else if(C<B && C<A)
        {
            ugly[i]=C;
            i++;c++;
        }
        else if(A==B)
        {
            a++;
        }
        else if(C==B)
        {
            b++;
        }
        else if(A==C)
        {
            c++;
        }
    }
    printf("The 1500'th ugly number is %d.\n",ugly[1499]);

    return 0;
}
