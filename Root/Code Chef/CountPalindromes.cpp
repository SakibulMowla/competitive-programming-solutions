#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

bool isPalindrome (char *s) {
    int len = strlen(s);
    for (int i = 0; i < len/2; i++) {
        if (s[i] != s[len-i-1]) {
            return false;
        }
    }
    return true;
}

int input () {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

int sum[172000];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    
    char a[12];

    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                sprintf(a, "%02d%02d%02d", i, j, k);
                int now = i * 3600 + j * 60 + k;
                if (now) {
                    sum[now] = sum[now-1];
                }
                if (isPalindrome(a)) {
                    sum[now]++;
                }
            }
        }
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int a = input();
        int b = input();

        cout << sum[b] - (a ? sum[a-1] : 0) << '\n';
    }

    return 0;
}





