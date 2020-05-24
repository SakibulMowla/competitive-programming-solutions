#include <stdio.h>
#include <string.h>
#include <math.h>
int check(int n,int m)
{
    int i;
    char arr[10];
    memset(arr,0,sizeof(arr));
    if(n<=9999)arr[0]++;
    if(m<=9999)arr[0]++;
    if(arr[0]>1)return 0;
    while(n)
    {
        i=n%10;
        n/=10;
        arr[i]++;
        if(arr[i] > 1)
            return 0;
    }
    while(m)
    {
        i=m%10;
        m/=10;
        arr[i]++;
        if(arr[i] > 1)
            return 0;
    }
    return 1;
}
int main()
{
    int i,p,flag,blank=0;
    while(scanf("%d",&p) == 1 && p)
    {
        if(blank) printf("\n");
        blank = 1;
        flag = 0;
        for(i=1111;i<=99999;i++)
        {
                if(p*i <= 99999 && check(i,p*i))
                {
                    flag = 1;
                    printf("%05d / %05d = %d\n",p*i,i,p);
                }
        }
        if(!flag)
            printf("There are no solutions for %d.\n",p);
    }

    return 0;
}
