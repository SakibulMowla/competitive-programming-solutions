#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define SZ 1000010

int dp[SZ][2];
char arr[SZ];

int main() {
    int i, j, k, test, n, l, d;

    scanf("%d",&test);

    while(test--){
        scanf("%d %d %d",&n,&l,&d);
        scanf("%s",arr);

        reverse(arr, arr+l);
        for(i=l; i<=n; i++) arr[i] = '0';

        for(i=0; i<=n; i++) dp[i][0] = dp[i][1] = 0;

        ///*************************************///

        /// Marking the road to ans in this chunk

        dp[0][0] = 1;

        for(i=0; i<n; i++)
            for(j=0; j<=1; j++)
                if(dp[i][j]){
                     k = j + arr[i] - '0';
                     if(k == 0) dp[i+1][0] = 1;
                     else if(k == 1) dp[i+1][0] = dp[i+1][1] = 1;
                     else if(k == 2) dp[i+1][1] = 1;
                }


        ///*************************************///

        /// Retrieving the ans from the marked part in this chunk

        dp[n][0] = 1;
        dp[n][1] = 0;

        for(i=n-1; i>=0; i--)
            for(j=0; j<=1; j++)
                if(dp[i][j]){
                     k = j + arr[i] - '0';
                     if(k == 0) dp[i][j] = dp[i+1][0];
                     else if(k == 1) dp[i][j] = (dp[i+1][0] + dp[i+1][1]) % d;
                     else if(k == 2) dp[i][j] = dp[i+1][1];
                }

        ///*************************************///

        printf("%d\n",dp[0][0]);
    }


    return 0;
}














