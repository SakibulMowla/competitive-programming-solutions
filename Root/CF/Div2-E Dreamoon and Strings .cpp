#include "bits/stdc++.h"

using namespace std;

#define SZ 2010
#define mem(a, b) memset(a, b, sizeof a)

int nxt[SZ];
char txt[SZ], pat[SZ];
int txtsz, patsz;

void pre_process()
{
    mem(nxt, -1);
    for(int i = 0; i < txtsz; i++)
    {
        int k = 0, cnt = 0;
        for(int j = 0; i + j < txtsz && k < patsz; j++)
        {
            if(txt[i+j] == pat[k])
                k++;
            else
                cnt++;
        }
        if(k == patsz)
            nxt[i] = cnt;
    }
    return;
}

int dp[SZ][SZ];

int solve(int pos, int left)
{
    int &ret = dp[pos][left];
    if(~ret) return ret;

    if(pos == txtsz)
    {
        if(!left) return ret = 0;
        return ret = -1e9;
    }
    if(left < 0) return ret = -1e9;

    ret = max(solve(pos+1, left), solve(pos+1, left-1));
    if(nxt[pos] != -1)
        ret = max(ret, 1 + solve(pos+nxt[pos]+patsz, left-nxt[pos]));

    return ret;
}

int main()
{
    while(scanf("%s %s", txt, pat) == 2)
    {
        txtsz = strlen(txt);
        patsz = strlen(pat);
        pre_process();

        mem(dp, -1);
        for(int i = 0; i <= txtsz; i++)
            printf("%d ", solve(0, i));
        puts("");
    }
    return 0;
}
