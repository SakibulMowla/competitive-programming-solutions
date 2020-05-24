#include "stdio.h"
#include "string.h"

#define MAX 85

const int inf = 1<<28;
int dp[MAX][MAX] , step , len1 , len2;
char arr1[MAX] , arr2[MAX];

int min(int a,int b)
{
    return a < b ? a : b;
}

int solve(int n,int m)
{
    int &ret = dp[n][m];

    if(n == len1) return ret = len2 - m;
    if(m == len2) return ret = len1 - n;

    if(ret != -1) return ret;
    ret = inf;

    if(arr1[n] == arr2[m]) ret = solve(n+1 , m+1);

    else
    {
        ret = min(ret , 1+solve(n+1 , m+1)); // change
        ret = min(ret , 1+solve(n+1 , m)); // delete
        ret = min(ret , 1+solve(n , m+1)); // insert
    }

    return ret;
}

void print_path(int n,int m)
{
    if(n == len1)
        while(m < len2)
            printf("%d Insert %d,%c\n",++step, m, arr2[m++]);
    else if(m == len2)
        while(n < len1)
            printf("%d Delete %d\n",++step, m+1) , n++;

    else if(arr1[n] == arr2[m]) print_path(n+1, m+1);
    else if(dp[n][m] - 1 == dp[n+1][m+1])
    {
        printf("%d Replace %d,%c\n",++step, m+1, arr2[m]);
        print_path(n+1, m+1);
    }
    else if(dp[n][m] - 1 == dp[n+1][m])
    {
        printf("%d Delete %d\n",++step, m+1);
        print_path(n+1, m);
    }
    else if(dp[n][m] - 1 == dp[n][m+1])
    {
        printf("%d Insert %d,%c\n",++step, m+1, arr2[m]);
        print_path(n, m+1);
    }
}

int main()
{
    bool blank = false;
    int i,j;

    while(gets(arr1))
    {
        gets(arr2);
        if(blank) printf("\n");
        else blank = true;

        len1 = strlen(arr1);
        len2 = strlen(arr2);

        for(i=0;i<=len1;i++)
            for(j=0;j<=len2;j++)
                dp[i][j] = -1;

        printf("%d\n",solve(0,0));
        step = 0;
        print_path(0,0);
    }

    return 0;
}
