#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 2147483647

void number1(char num1[]);
void number2(char num2[]);
void result(char num1[],char num2[],char sign);

long n1,n2;

int main()
{
    int i,j,k,l;
    char num1[1000],num2[1000],sign;
    while(scanf("%s %s %s",num1,&sign,num2)==3)
    {
        printf("%s %s %s\n",num1,sign,num2);
        number1(num1);
        number2(num2);
        result(num1,num2,sign);
    }

    return 0;
}

void number1(char num1[])
{
    int len,i=0;
    len=strlen(num1);
    while(num1[i]=='0' && i<len)
        i++;
    if(i==len && num1[len-1]=='0')
    {
        n1=0;
    }
    else if(len-i>10)
    {
        printf("first number too big\n");
        n1=1;
    }
    else if(atof(num1)>max)
    {
        printf("first number too big\n");
        n1=1;
    }
    else n1=atol(num1);
    return;
}
void number2(char num2[])
{
    int len,i=0;
    len=strlen(num2);
    while(num2[i]=='0' && i<len)
        i++;
    if(i==len && num2[len-1]=='0')
    {
        n2=0;
    }
    else if(len-i>10)
    {
        printf("second number too big\n");
        n2=1;
    }
    else if(atof(num2)>max)
    {
        printf("second number too big\n");
        n2=1;
    }
    else n2=atol(num2);
    return;
}

void result(char num1[],char num2[],char sign)
{
    if((n1==0 || n2==0) && sign=='*')
        return;
    else if(n1==1 || n2==1)
        printf("result too big\n");
    else
    {
        if(sign=='+')
        {
            if(n1+n2>max)
                printf("result too big\n");
        }
        else if(sign=='*')
        {
            if(n1*n2>max)
                printf("result too big\n");
        }
    }
    return;
}
