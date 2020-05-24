#include <stdio.h>
#include <string.h>

int count,l,len;
char arr[30][30];
void func(int i,int j,char arr[30][30])
{
    int n,m;
    count++;
    arr[i][j]='0';
    if(i>l || i<1 || j>len || j<0)
        return;
    for(n=i-1;n<=i+1;n++)
    {
        for(m=j-1;m<=j+1;m++)
        {
            if(arr[n][m]=='1')
            {
                func(n,m,arr);
            }
        }
    }
    return;
}

int main()
{
    int n,m,i,j,k,r,c,hc;
    char z,ch,line[30];
    scanf("%d",&n);
    getchar();
    getchar();
    for(k=0; k<n; k++)
    {
        l=1;
        while(gets(line))
        {
            if(strcmp(line,"")==0)
                break;
            strcpy(arr[l++],line);
        }
        len=strlen(arr[1]);
        hc=0;
        for(i=1;i<=l;i++)
        {
            for(j=0;j<len;j++)
            {
                if(arr[i][j]=='1')
                {
                    func(i,j,arr);
                    if(count>hc)
                        hc=count;
                    count=0;
                }
            }
        }
        printf("%d\n",hc);
        if(k<n-1)
            printf("\n");

    }

    return 0;
}
