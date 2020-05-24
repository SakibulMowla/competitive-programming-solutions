#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char a[10000];
    char b;
    char c[20];
} data;
int main(void)
{
    data arr;
    long i;
    char div[100000];
    long long int k,j,l,n,m,p,l1;

    while(scanf("%s %c %s",arr.a,&arr.b,arr.c)==3)
    {
        i=atol(arr.c);
        l=strlen(arr.a);
        l1=strlen(arr.c);
        if(arr.b=='%')
        {
            k=0;
            for(j=0; j<l; j++)
            {
                k=((k*10)+(arr.a[j]-'0'))%i;
            }
            printf("%lld\n",k);
        }
        else if(arr.b=='/')
        {
            p=atol(arr.a);
            k=0;
            n=0;
            if(l<=l1 && p<i)
            {
                printf("0\n");
            }
            else
            {
                for(j=0; j<l; j++)
                {
                    k=(k*10)+(arr.a[j]-'0');
                    if(k/i>0)
                    {
                        div[n]=(k/i)+'0';
                        n++;
                    }
                    k=k%i;
                    if(n==1)
                        break;
                }
                for(m=j+1; m<l; m++)
                {
                    k=(k*10)+(arr.a[m]-'0');
                    div[n]=(k/i)+'0';
                    n++;
                    k=k%i;
                }
                div[n]='\0';
                printf("%s\n",div);
            }
        }
    }

    return 0;
}
