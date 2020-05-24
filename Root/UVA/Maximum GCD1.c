#include<stdio.h>
#define max(a,b) (a>b)?a:b

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    char z,ch,prech;
    int num[1000],n,i,j,k,l,p;
    scanf("%d%c",&n,&z);
    for(i=0;i<n;i++)
    {
        prech=' ';
        k=-1;
        while(scanf("%c",&ch) && ch!='\n')
        {
            if(ch>='0' && ch<='9')
            {
                if(prech==' ' || prech=='\n')
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
        p=0;
        for(j=0;j<=k;j++)
        {
            for(l=j+1;l<=k;l++)
            {
                p=max(p,gcd(num[j],num[l]));
            }
        }
        printf("%d\n",p);
    }
    return 0;
}
