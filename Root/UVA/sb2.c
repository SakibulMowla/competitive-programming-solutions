#include<stdio.h>
int k=0;
void func(int n);

int main()
{
    int i;
    for(i=0;i<6;i++)
        func(k);
}

void func(int n)
{
    static int p=0;
    k+=2;
    printf("%d",k);
    if(k==k)
        printf("%d",++n);
    p+=n;
    printf("%d\n",p);
}
