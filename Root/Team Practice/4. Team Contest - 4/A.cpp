//BISMILLAHIRRAHMANIRRAHIM

//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:0x800000")
//#define _CRT_SECURE_NO_WARNINGS 1

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int _log10(int k) {
    int r=0;
    while(k) {
        r++;
        k/=10;
    }
    return r;
}

char ln[120];
bool vis[120][120];
int dp[120][120];

int dfs(int st,int fn) {
    if(st==fn) return 1;
    if(vis[st][fn]) return dp[st][fn];
    vis[st][fn]=1;
    //cerr<<' '<<st<<' '<<fn<<'\n';
    int r=fn-st+1,t,i,j,k,c;
    for(i=st+1;i<=fn;i++) r=min(r,dfs(st,i-1)+dfs(i,fn));
    for(i=st;i<fn;i++) if(!((fn-st+1)%(i-st+1))) {
        c=i-st+1;
        for(j=i+1;j<=fn && ln[j]==ln[(j-st)%c+st];j++);
        if(j!=fn+1) continue;
        r=min(2+_log10((fn-st+1)/(i-st+1))+dfs(st,i),r);
    }
    return dp[st][fn]=r;
}

string back(int st,int fn) {
    //cerr<<st<<' '<<fn<<'\n';
    if(st==fn) return string("")+ln[st];
    int r = dp[st][fn];
    if(r==fn-st+1) return string(ln+st,ln+fn+1);
    int i,j,c;
    for(i=st+1;i<=fn;i++) {/*cerr<<i<<'\n';*/if(r==dfs(st,i-1)+dfs(i,fn)) {
        return back(st,i-1) + back(i,fn);
    }}
    for(i=st;i<fn;i++) if(!((fn-st+1)%(i-st+1))) {
        c=i-st+1;
        for(j=i+1;j<=fn && ln[j]==ln[(j-st)%c+st];j++);
        if(j!=fn+1) continue;
        if(r==(2+_log10((fn-st+1)/(i-st+1))+dfs(st,i))) {
            stringstream ss;
            ss<<((fn-st+1)/(i-st+1))<<'('<<back(st,i)<<')';
            return ss.str();
        }
    }
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    while(gets(ln)) {
        CLR(vis);
        int t=dfs(0,strlen(ln)-1);
        cout<<back(0,strlen(ln)-1)<<'\n';
    }
    return 0;
}
