#include <stdio.h>
#include <string.h>

int r,c,count;
char h;
typedef struct{
        char ch;
        int num;
} data;

int func(int n,int m,char str[60][60]);
int main()
{
    data arr[2600],temp;
    int i,j,k,l,n,m;
    char str[60][60],z;
    l=1;
    while(scanf("%d %d%c",&r,&c,&z)==3)
    {
        if(r==0 && c==0) break;
        for(i=0;i<r;i++)
            gets(str[i]);
        k=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(str[i][j]>='A' && str[i][j]<='Z')
                {
                    count=1;
                    h=arr[k].ch=str[i][j];
                    str[i][j]='0';
                    func(i,j,str);
                    arr[k].num=count;
                    k++;
                }
            }
        }
        memset(str,0,sizeof str);
        for(i=0;i<k-1;i++)
        {
            for(j=i+1;j<k;j++)
            {
                if(arr[i].num < arr[j].num)
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
                else if(arr[i].num==arr[j].num)
                {
                    if(arr[i].ch>arr[j].ch)
                    {
                        temp=arr[i];
                        arr[i]=arr[j];
                        arr[j]=temp;
                    }
                }
            }
        }
        printf("Problem %d:\n",l);
        for(i=0;i<k;i++)
        {
            printf("%c %d\n",arr[i].ch,arr[i].num);
        }
        l++;
    }

    return 0;
}

int func(int n,int m,char str[60][60])
{
    if(n<0 || n>=r || m<0 || m>=c)
        return;
    if(str[n][m-1]==h)
    {
        count++;
        str[n][m-1]='0';
        func(n,m-1,str);
    }
    if(str[n][m+1]==h)
    {
        count++;
        str[n][m+1]='0';
        func(n,m+1,str);
    }
    if(str[n-1][m]==h)
    {
        count++;
        str[n-1][m]='0';
        func(n-1,m,str);
    }
    if(str[n+1][m]==h)
    {
        count++;
        str[n+1][m]='0';
        func(n+1,m,str);
    }

    return;
}
