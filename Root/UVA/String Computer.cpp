using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"

#define MAX 22
const int inf = 1<<28;

int dp[MAX][MAX] , len1 , len2;
char arr1[MAX] , arr2[MAX];
string ans;

int solve(int indx1,int indx2)
{
    int &ret = dp[indx1][indx2];

    if(indx1 == len1)
        return ret = len2 - indx2;
    if(indx2 == len2)
        return ret = len1 - indx1;

    if(ret != -1) return ret;

    ret = inf;

    if(arr1[indx1] == arr2[indx2]) ret = min(ret , solve(indx1+1 , indx2+1));
    else
    {
        ret = min( ret , 1+solve(indx1+1 , indx2+1) );//change
        ret = min( ret , 1+solve(indx1+1 , indx2) );//delete
        ret = min( ret , 1+solve(indx1 , indx2+1) );//insert
    }
    return ret;
}

void ans_path(int indx1,int indx2,int indx)
{
    if(indx1 == len1)
    {
        while(indx2 < len2)
            printf("I%c%02d",arr2[indx2] , indx) , indx2++ , indx++;
        return;
    }
    if(indx2 == len2)
    {
        while(indx1 < len1)
            printf("D%c%02d",arr1[indx1] , indx) , indx1++;
        return;
    }

    if( arr1[indx1] == arr2[indx2] )
        ans_path(indx1+1 , indx2+1, indx+1);

    else if( dp[indx1][indx2]-1 == dp[indx1+1][indx2+1] )
    {
        printf("C%c%02d",arr2[indx2] , indx);
        ans_path(indx1+1 , indx2+1 , indx+1);
    }

    else if( dp[indx1][indx2]-1 == dp[indx1+1][indx2] )
    {
        printf("D%c%02d",arr1[indx1] , indx);
        ans_path(indx1+1 , indx2 , indx);
    }

    else if( dp[indx1][indx2]-1 == dp[indx1][indx2+1] )
    {
        printf("I%c%02d",arr2[indx2] , indx);
        ans_path(indx1 , indx2+1 , indx+1);
    }

}

int main()
{
    int i,j;

    while(scanf("%s",arr1) == 1)
    {
        if(arr1[0] == '#') break;
        scanf("%s",arr2);

        len1 = strlen(arr1);
        len2 = strlen(arr2);

        for(i=0;i<=len1;i++)
            for(j=0;j<=len2;j++)
                dp[i][j] = -1;

        solve(0,0);
        ans_path(0,0,1);
        printf("E\n");
    }

    return 0;
}
