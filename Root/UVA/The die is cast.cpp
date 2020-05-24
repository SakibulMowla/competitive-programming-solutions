#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

int r,c,cnt;
int arr[55][55];
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

void sub_dfs(int m,int n)
{
    int i;
    if(m<0 || n<0 || m>=r || n>=c || arr[m][n]!='X')
        return;
    arr[m][n] = '*';
    for(i=0; i<4; i++)
        sub_dfs(m+x[i],n+y[i]);
}

void dfs(int m,int n)
{
    if(m<0 || n<0 || m>=r || n>=c || arr[m][n]=='.')
        return;
    int i;
    if(arr[m][n] == 'X')
    {
        cnt++;
        sub_dfs(m,n);
    }

    arr[m][n] = '.';
    for(i=0; i<4; i++)
        dfs(m+x[i],n+y[i]);
}

int main()
{
    int i,j,test;
    test = 0;
    vector <int> result;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&c,&r) == 2)
    {
        if(r==0 && c==0)break;

        result.clear();

        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                scanf(" %c",&arr[i][j]);

        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(arr[i][j] != '.')
                {
                    cnt = 0;
                    dfs(i,j);
                    result.push_back(cnt);
                }
        sort(result.begin(),result.end());
        printf("Throw %d\n",++test);
        printf("%d",result[0]);
        for(i=1; i<result.size(); i++)
            printf(" %d",result[i]);
        printf("\n\n");
    }

    return 0;
}
