#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<double>vd;
typedef vector<string> vs;
typedef vector<vi>vvi;
typedef map<string,int> msi;
typedef map<int,int>mii;
typedef map<pii,int>mpi;

#define pb push_back
#define MP make_pair
#define popb pop_back
#define all(a) a.begin(), a.end()
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define SZ(a) ( (int)a.size() )
#define mem(a, b) memset(a, b, sizeof(a))

#define REP(i,n) for (i=0;i<n;i++)
#define REV(i,n) for (i=n;i>=0;i--)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define FOR(i,p,k) for (i=p; i<k;i++)

#define COPY(c,r)   memcpy(c,r,sizeof(r))
#define popcount(i) __builtin_popcount(i)
#define fs first
#define sc second

/// Moves ///
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[] = {-2, 2, -1, 1, -1, 1};int dy[] = {0, 0, 1, 1, -1, -1}; //Hexagonal Moves

/// Cycles ///
//#define cycl0 0
//#define cycl1 1
//#define cycl5 5
//#define cycl6 6
//int cycl2[] = {1, 2, 4, 8, 6};
//int cycl3[] = {1, 3, 9, 7, 1};
//int cycl4[] = {1, 4, 6};
//int cycl7[] = {1, 7, 9, 3, 1};
//int cycl8[] = {1, 8, 4, 2, 6};
//int cycl9[] = {1, 9, 1};

#define INF 1<<30

string s;

int dp[20][20][1010][10];

int dp_sol(int l, int r, int cur, int w);
void out_print(int l, int r, int cur, int w);

int main()
{
    int m;
    cin>>s>>m;

    int res = 0;

    mem(dp, -1);
    for (int i=0; i<10; i++)
    {
        if (s[i]=='1')
            res |= dp_sol(i+1, 0, m-1, i);
        if (res) break;
    }
    if (res)
    {
        cout<<"YES"<<endl;
        for (int i=0; i<10; i++)
        {
            if (s[i]=='1')
                if (dp_sol(i+1, 0, m-1, i))
                {
                    cout<<i+1<<" ";
                    out_print(i+1, 0, m-1, i);
                    cout<<endl;
                    break;
                }
        }
    }
    else cout<<"NO"<<endl;

    return 0;
}

int dp_sol(int l, int r, int cur, int w)
{
    if (cur==0) return 1;
    int &ret = dp[l][r][cur][w];
    if (ret != -1) return ret;

    ret = 0;
    for (int i=0; i<10; i++)
    {
        if (w==i) continue;
        if (s[i]=='1')
        {
            if (l && i+1>l) ret |= dp_sol(0, i+1-l, cur-1, i);
            else if (r && i+1>r) ret |= dp_sol(i+1-r, 0, cur-1, i);
        }
        if (ret) break;
    }
    return ret;
}

void out_print(int l, int r, int cur, int w)
{
    if (cur==0) return;
//    int &ret = dp[l][r][cur][w];
//    if (ret != -1) return ret;

//    ret = 0;
    for (int i=0; i<10; i++)
    {
        if (w==i) continue;
        if (s[i]=='1')
        {
            if (l && i+1>l && dp_sol(0, i+1-l, cur-1, i))
            {
                cout<<i+1<<" ";
                out_print(0, i+1-l, cur-1, i);
                break;
            }
            else if (r && i+1>r && dp_sol(i+1-r, 0, cur-1, i))
            {
                cout<<i+1<<" ";
                out_print(i+1-r, 0, cur-1, i);
                break;
            }
        }
    }
    return;
}
