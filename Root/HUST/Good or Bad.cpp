#include "stdio.h"
#include "string.h"
#include "ctype.h"
#define SZ 55

enum { GOOD , BAD , MIXED };
int n , dp[SZ][5][7];
char arr[SZ];
char ans[5][10] = {"GOOD","BAD","MIXED"};

int vowel(char ch)
{
    ch = tolower(ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
    return 0;
}

int solve(int indx,int vowl,int cons)
{
    if(vowl == 3 || cons == 5) return BAD;
    if(indx == n) return GOOD;
    int &ret = dp[indx][vowl][cons];
    if(ret != -1) return ret;
    if(arr[indx] == '?')
    {
        int i,j;
        i = solve(indx+1,vowl+1,0);
        j = solve(indx+1,0,cons+1);
        if(i ^ j) ret = MIXED;
        else ret = i;
    }
    else if(vowel(arr[indx]))
        ret = solve(indx+1,vowl+1,0);
    else
        ret = solve(indx+1,0,cons+1);
    return ret;
}

int main()
{
    int t=0,test,i,j,k;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",arr);
        n = strlen(arr);
        for(i=0;i<=n;i++) for(j=0;j<=3;j++) for(k=0;k<=5;k++) dp[i][j][k] = -1;
        printf("Case %d: %s\n",++t,ans[solve(0,0,0)]);
    }

    return 0;
}
