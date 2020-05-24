#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x)
{
    scanf("%d",&x);
}
void RD(ll &x)
{
    scanf("%I64d",&x);
}
void RD(double &x)
{
    scanf("%lf",&x);
}
void RD(int &x,int &y)
{
    scanf("%d%d",&x,&y);
}
void RD(ll &x,ll &y)
{
    scanf("%I64d%I64d",&x,&y);
}
void RD(double &x,double &y)
{
    scanf("%lf%lf",&x,&y);
}
void RD(char *s)
{
    scanf("%s",s);
}
void RD(char &s)
{
    scanf("%c",&s);
}
void RD(string &s)
{
    cin>>s;
}

void PR(int x)
{
    printf("%d\n",x);
}
void PR(int x,int y)
{
    printf("%d %d\n",x,y);
}
void PR(ll x)
{
    printf("%I64d\n",x);
}
void PR(char x)
{
    printf("%c\n",x);
}
void PR(char *x)
{
    printf("%s\n",x);
}
void PR(string x)
{
    cout<<x<<endl;
}

int dp[125];

int main()
{
    int i, j, n;

    dp[0] = 1;
    for(i=1; i<=120; i++)
        for(j=i; j<=120; j++)
            dp[j] = dp[j] + dp[j-i];

    while(scanf("%d",&n) == 1)
    {
        PR(dp[n]);
    }


    return 0;
}

















