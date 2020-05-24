#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

#define SZ 100010

typedef pair <int , int> pii;

map <pii, bool> mp;
string s;
int dp[SZ][27], N;

int solve (int pos, int last) {
    int &ret = dp[pos][last];
    if(~ret) return ret;
    if(pos == N) return 0;

    ret = solve(pos+1, last);
    if(mp.find(MP(last, s[pos]-'a')) == mp.end())
        ret = max(ret, 1 + solve(pos+1, s[pos]-'a'));

    return ret;
}

int main() {

    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(false);

    while(cin >> s) {
        clr(mp);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string t;
            cin >> t;
            mp[ MP(t[0]-'a', t[1]-'a') ] = mp[ MP(t[1]-'a', t[0]-'a') ] = 1;
        }
        mem(dp, -1);
        N = sz(s);
        cout << sz(s) - solve(0, 26) << endl;
    }

    return 0;
}









