#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    char num[1000],z,ch,prech;
    int n,i,j,k,l;
    scanf("%d%c",&n,&z);
    for(i=0;i<n;i++)
    {
        prech=' ';
        k=-1;
        while(getchar()!='\n');
        {
            ch=getchar();
            if(ch>='0' && ch<='9')
            {
                if(prech==' ')
                {
                    num[++k]=ch-'0';
                }
                else if(prech>='0' && prech<='9')
                {
                    num[k]=num[k]*10+(ch-'0');
                }
            }
            prech=ch;
        }
        for(j=0;j<=k;j++)
            printf("%d\n",num[j]);
    }
    return 0;
}
