#include<stdio.h>
#include<string.h>

int sd(char n[]);
int main()
{
    char n[1000];

    while(gets(n))
    {
        if(strlen(n)==1 && (n[0]-'0')==0)
            break;
        sd(n);
    }
}

int sd(char n[])
{
    int len,i,sum;

     len =strlen(n);
        if(len==1)
            printf("%s\n",n[0]);
        else
        {
            sum=0;
            for(i=0;i<len;i++)
            {
                sum+=n[i];
            }
            if(sum<10)
                printf("%d\n",sum);
            else
            {
                gets(sum);
                sd(sum);
            }
        }

}
