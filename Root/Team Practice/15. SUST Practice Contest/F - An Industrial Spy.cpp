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
#include <assert.h>
#include <time.h>

using namespace  std;

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

#define SZ  10010

bool arr[SZ];
vector <int> prime;

void sieve () {
    arr[0] = arr[1] = 1;
    for (int i = 4; i <= 10000; i += 2)
        arr[i] = 1;
    for (int i = 3; i <= 100; i += 2)
        if (!arr[i])
            for (int j = i * i; j <= 10000; j += i + i)
                arr[j] = 1;
    prime.pb(2);
    for (int i = 3; i <= 10000; i += 2)
        if (!arr[i])
            prime.pb(i);

    return;
}

bool checkPrime (int n) {
    if (n <= 10000) return !arr[n];
    for (int i = 0; prime[i] * prime[i] <= n; i++)
        if (n % prime[i] == 0)
            return 0;
    return 1;
}

int toInt (string &a) {
    int n = 0;
    for (int i = 0; i < sz(a); i++)
        n = n * 10 + a[i] - '0';
    return n;
}

map <int , int> mp;

void permute (string &a) {
    if (sz(a) == 0) return;
    int ans = 0;
    do {
        int tmp = toInt(a);
        if (checkPrime(tmp))
            mp[tmp] = 1;
    } while (next_permutation(a.begin(), a.end()));
    return;
}

void solve (string &a) {
    permute(a);
    for (int i = 0; i < sz(a); i++) {
        string ss = a;
        ss.erase(i, 1);
        solve(ss);
    }
    return;
}

char str[100];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    sieve();

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%s", str);
        string a = str;

        clr(mp);
        sort(a.begin(), a.end());
        solve(a);

        printf("%d\n", sz(mp));
    }

    return 0;
}






