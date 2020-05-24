#include <stdio.h>
#include <string.h>

int rc;
int dr [] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc [] = {0, 1, 1, 1, 0, -1, -1, -1};

char arr[110][110];
void func(int i,int j)
{
    int p;
    if(i<0 || j<0 || i>=rc || j>=rc || arr[i][j]=='.')
        return;
    arr[i][j]='.';
    for(p=0;p<8;p+=2)
        func(i+dr[p],j+dc[p]);
    return;
}
int main()
{
    int i,j,k,l,count;
    char z;
    l=0;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&rc);
        for(i=0;i<rc;i++)
            scanf("%s",arr[i]);
        count=0;
        for(i=0;i<rc;i++)
        {
            for(j=0;j<rc;j++)
            {
                if(arr[i][j]=='x')
                {
                    count++;
                    func(i,j);
                }
            }
        }
        printf("Case %d: %d\n",++l,count);
    }
    return 0;
}
