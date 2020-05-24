#include "stdio.h"
#include "string.h"
#define SZ 55

template <class T> T max(T a, T b) { return a > b ? a : b; }
char arr1[SZ] , arr2[SZ] , arr3[SZ];
int dp[SZ][SZ][SZ] , len1 , len2 , len3;

int solve(int indx1,int indx2,int indx3)
{
    if(indx1 == len1 || indx2 == len2 || indx3 == len3) return 0;
    int &ret = dp[indx1][indx2][indx3];
    if(ret != -1) return ret;
    ret = 0;
    if(arr1[indx1] == arr2[indx2] && arr2[indx2] == arr3[indx3])
        /*printf("yes\n") ,*/ return ret = 1 + solve(indx1+1 , indx2+1 , indx3+1);
    return ret = max(solve(indx1+1,indx2,indx3) , max(solve(indx1,indx2+1,indx3) , solve(indx1,indx2,indx3+1)));
}

int main()
{
    int t=0,test,i,j,k;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s %s %s",arr1,arr2,arr3);
        len1 = strlen(arr1) , len2 = strlen(arr2) , len3 = strlen(arr3) ;
        for(i=0;i<=len1;i++) for(j=0;j<=len2;j++) for(k=0;k<=len3;k++) dp[i][j][k] = -1;
        printf("Case %d: %d\n",++t,solve(0,0,0));
    }

    return 0;
}
