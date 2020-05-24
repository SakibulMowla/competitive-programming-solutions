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

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

#define X first
#define Y second

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

struct data
{
    int v;
    char c;
};


data arr[20];

bool comp(data p, data q)
{
    return p.v < q.v;
}

int dp[(1<<13)+10];
int path[(1<<13)+10];

int solve(int mask)
{
    if(!mask) return 0;

    int &ret = dp[mask];

    if(ret != -1) return ret;

    int i, j, tmp, tmp1, pre, ret1, cnt;

    ret = 1e9;

    for(i=0; i<13; i++)
    {
        if(mask&(1<<i))
        {
            ret1 = 1 + solve(mask&~(1<<i));

            if(ret1 < ret)
            {
                ret = ret1;
                path[mask] = 1<<i;
            }


            tmp = 1<<i;
            pre = arr[i].v;
            cnt = 1;

            for(j=i+1; j<13; j++)
            {
                if( mask&(1<<j) &&  arr[j].v == pre+1)
                {
                    cnt++;
                    pre = arr[j].v;
                    tmp |= 1<<j;

                    if(cnt >= 5)
                    {
                        ret1 = 1 + solve(mask&~tmp);

                        if(ret1 < ret)
                        {
                            ret = ret1;
                            path[mask] = tmp;
                        }
                    }
                }
            }



            if(i+1 < 13 && (mask&(1<<(i+1))) && arr[i].v == arr[i+1].v)
            {
                tmp = 1<<i;
                tmp |= 1<<(i+1);

                ret1 = 1 + solve(mask&~tmp);

                if(ret1 < ret)
                {
                    ret = ret1;
                    path[mask] = tmp;
                }

                for(j=12; j-2>i+1; j--)
                {
                    if((mask&(1<<(j))) && (mask&(1<<(j-1))) && (mask&(1<<(j-2))) && arr[j].v == arr[j-1].v && arr[j-1].v == arr[j-2].v && arr[j].v != arr[i].v)
                    {
                        tmp1 = tmp | (1<<(j)) | (1<<(j-1)) | (1<<(j-2));

                        ret1 = 1 + solve(mask&~tmp1);

                        if(ret1 < ret)
                        {
                            ret = ret1;
                            path[mask] = tmp1;
                        }
                    }
                }
            }

            if(i+2 < 13 && (mask&(1<<(i+1))) && (mask&(1<<(i+2))) && arr[i].v == arr[i+1].v && arr[i+1].v == arr[i+2].v)
            {
                tmp = 1<<i;
                tmp |= 1<<(i+1);
                tmp |= 1<<(i+2);

                ret1 = 1 + solve(mask&~tmp);

                if(ret1 < ret)
                {
                    ret = ret1;
                    path[mask] = tmp;
                }


                for(j=12; j-1>i+2; j--)
                {
                    if((mask&(1<<(j))) && (mask&(1<<(j-1))) && arr[j].v == arr[j-1].v && arr[j].v != arr[i].v)
                    {
                        tmp1 = tmp | (1<<(j)) | (1<<(j-1));

                        ret1 = 1 + solve(mask&~tmp1);

                        if(ret1 < ret)
                        {
                            ret = ret1;
                            path[mask] = tmp1;
                        }
                    }
                }
            }

            if(i+3 < 13 && (mask&(1<<(i+1))) && (mask&(1<<(i+2))) && (mask&(1<<(i+3))) && arr[i].v == arr[i+1].v && arr[i+1].v == arr[i+2].v && arr[i+2].v == arr[i+3].v)
            {
                tmp = 1<<i;
                tmp |= 1<<(i+1);
                tmp |= 1<<(i+2);
                tmp |= 1<<(i+3);

                ret1 = 1 + solve(mask&~tmp);

                if(ret1 < ret)
                {
                    ret = ret1;
                    path[mask] = tmp;
                }
            }




            break;
        }
    }

    return ret;
}


void pathdp(int mask)
{
    if(!mask) return;

    int blank = 0, i;

    for(i=0; i<13; i++)
    {
        if(path[mask]&(1<<i))
        {
            if(blank) printf(" ");
            else blank = 1;
            if(arr[i].v == 10) printf("T");
            else if(arr[i].v == 11) printf("J");
            else if(arr[i].v == 12) printf("Q");
            else if(arr[i].v == 13) printf("K");
            else if(arr[i].v == 14) printf("A");
            else printf("%d",arr[i].v);
            printf("%c",arr[i].c);
        }
    }

    printf("\n");

    return pathdp(mask&~(path[mask]));
}



//%I64d
int main()
{
    int n, m, i, j, k, t;
    char s[10];

    scanf("%d",&t);

    while(t--)
    {
        for(i=0; i<13; i++)
        {
            scanf("%s",s);
            arr[i].c = s[1];
            if(s[0] == 'A') arr[i].v = 14;
            else if(s[0] == 'T') arr[i].v = 10;
            else if(s[0] == 'J') arr[i].v = 11;
            else if(s[0] == 'Q') arr[i].v = 12;
            else if(s[0] == 'K') arr[i].v = 13;
            else arr[i].v = s[0]-'0';
        }

        sort(arr, arr+13, comp);

//        for(i=0; i<13; i++)
//            printf("%d %c\n",arr[i].v,arr[i].c);

        mem(dp, -1);

        printf("%d\n",solve((1<<13)-1));

        pathdp((1<<13)-1);
    }


    return 0;
}







/*
100

1a 2a 3a 4a 5a 6a 1q 2q 3q 4q 5q 6q Tj
2h 3c 4d 5d 6s Th Qc Qs Ad Tc Ts 9c 9d
2h 3h 4h 5h 6d 7s 8h 8d 8c 8s 9c Td Js
2a 3a 4a 5a 6a 7a 8a 9a Aa Ta Ja Ka Qa
2a 3a 4a 5a 7a 8a 9a Ta Ja Ja Ja Ja Ja
2a 3a 4a 5a 7a 8a 9a Ta Aa Aa Aa Aa Aa
2a 2a 2a 3a 3a 4a 4a 5a 5a 6a 6a 7a 7a

*/








