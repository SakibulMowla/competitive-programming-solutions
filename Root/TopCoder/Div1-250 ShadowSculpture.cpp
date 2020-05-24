#include <bits/stdc++.h>
using namespace  std;
typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  110


class ShadowSculpture {
public:
    int n;
    int mat[12][12][12];
    set <pii> mp[3], tmp[3];
    void pre (int n) {
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            mat[i][j][k] = 1;
    }
    bool col[12][12][12];
    void dfs(int x, int y, int z) {
        set <pii> ::iterator it;

        it = mp[0].find(MP(x, y));
        if(it != mp[0].end()) mp[0].erase(it);
        it = mp[1].find(MP(y, z));
        if(it != mp[1].end()) mp[1].erase(it);
        it = mp[2].find(MP(z, x));
        if(it != mp[2].end()) mp[2].erase(it);

        col[x][y][z] = 1;

        if(x+1<n && col[x+1][y][z] == 0 && mat[x+1][y][z] == 1) dfs(x+1, y, z);
        if(x-1>=0 && col[x-1][y][z] == 0 && mat[x-1][y][z] == 1) dfs(x-1, y, z);
        if(y+1<n && col[x][y+1][z] == 0 && mat[x][y+1][z] == 1) dfs(x, y+1, z);
        if(y-1>=0 && col[x][y-1][z] == 0 && mat[x][y-1][z] == 1) dfs(x, y-1, z);
        if(z+1<n && col[x][y][z+1] == 0 && mat[x][y][z+1] == 1) dfs(x, y, z+1);
        if(z-1>=0 && col[x][y][z-1] == 0 && mat[x][y][z-1] == 1) dfs(x, y, z-1);

        return;
    }
	string possible(vector <string> x, vector <string> y, vector <string> z) {
		n = x[0].size();
		pre(n);
		clr(mp[0]);clr(mp[1]);clr(mp[2]);
		clr(tmp[0]);clr(tmp[1]);clr(tmp[2]);
        for (int i = 0; i < sz(x); i++)
            for (int j = 0; j < sz(x[0]); j++)
                if(x[i][j] == 'N')
                    for(int k = 0; k < n; k++)
                        mat[i][j][k] = 0;
                else mp[0].insert(MP(i, j));
        for (int i = 0; i < sz(y); i++)
            for (int j = 0; j < sz(y[0]); j++)
                if(y[i][j] == 'N')
                    for(int k = 0; k < n; k++)
                        mat[k][i][j] = 0;
                else mp[1].insert(MP(i, j));
        for (int i = 0; i < sz(z); i++)
            for (int j = 0; j < sz(z[0]); j++)
                if(z[i][j] == 'N')
                    for(int k = 0; k < n; k++)
                        mat[j][k][i] = 0;
                else mp[2].insert(MP(i, j));
        tmp[0] = mp[0];
        tmp[1] = mp[1];
        tmp[2] = mp[2];
        if(sz(mp[0])+sz(mp[1])+sz(mp[2]) == 0) return "Possible";
        for (int i = 0; i < sz(x); i++)
            for (int j = 0; j < sz(x[0]); j++)
            if(x[i][j] == 'Y') {
                for(int k = 0; k < n; k++) if(mat[i][j][k]){
                    mp[0] = tmp[0];
                    mp[1] = tmp[1];
                    mp[2] = tmp[2];
                    mem(col, 0);
                    dfs(i, j, k);
                    if(sz(mp[0])+sz(mp[1])+sz(mp[2]) == 0) return "Possible";
                }
            }
        return "Impossible";
	}
};
