#include <stdio.h>
#include <string.h>

int dp[30][300];
bool color[30][300];
int cost[30];
int n,cap;

int knapsack(int i,int w)
{

}


int main()
{
    int test,len,i;
    char prech,ch,z,arr[200];
    scanf("%d%c",&test,&z);
    while(test--)
    {
        n=0;
        memset(color,0,sizeof(color));
        prech=' ';
        gets(arr);
        puts(arr);
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            ch=arr[i];
            printf("ch = %c\n",arr[i]);
            if(prech==' ' && ch>='0' && ch<='9')
            {
                ++n;
                arr[n]=ch-'0';
            }
            else if(ch>='0' && ch<='9' && prech>='0' && prech<='9')
            {
                arr[n]=(arr[n]*10)+ch-'0';
            }
            prech=ch;
        }
        for(i=1;i<=n;i++)
            printf("%d ",arr[i]);
    }

    return 0;
}
