#include <stdio.h>
#include <string.h>

int main()
{
    long long int a,b,fibo[50],num[1000];
    int i,j,k,l,n,m,len,c;
    char line[1000],code[1000],z;

    fibo[0]=a=1;
    fibo[1]=b=2;
    for(i=2; i<46; i++)
    {
        fibo[i]=a+b;
        a=b;
        b=fibo[i];
    }

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        l=0;
        for(j=0; j<m; j++)
        {
            scanf("%lld",&num[j]);
            if(num[j]>l)
                l=num[j];
        }

        scanf("%c",&z);
        gets(line);
        len=strlen(line);
        for(j=0; j<100; j++)
        {
            if(l==fibo[j])
            {
                c=j;
                break;
            }
        }
        for(k=0,l=0; k<len ;)
        {
            if(line[k]>='A' && line[k]<='Z')
            {
                for(j=0; j<=c; j++)
                {
                    if(fibo[j]==num[l])
                    {
                        code[j]=line[k];
                        l++;
                        k++;
                        break;
                    }
                    else if(j==c)
                    {
                        l++;
                    }

                }
            }
            else k++;
            if(l==m) break;
        }
        for(k=0; k<=c; k++)
        {
            if(!(code[k]>='A' && code[k]<='Z'))
                code[k]=' ';
        }
        code[c+1]='\0';
        printf("%s\n",code);
        for(j=0; j<1000; j++)
            code[j]='\0';
    }

    return 0;
}
