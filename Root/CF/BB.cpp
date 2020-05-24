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

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

//    ios::sync_with_stdio(false);

    srand (time(NULL));
    int cnt = 0, rev = 0;

    vector<int> a(10);
    for (int i = 0; i < 10; i++) a[i] = i;
    random_shuffle(a.begin(), a.end());

    for (int i = 0; i < 6; i++) {
        cout << a[i] << endl;
        string s;
        getline(cin, s);
        if (s == "cool" || s == "great" || s == "not bad" || s == "don't think so" || s == "don't touch me" || s == "no") cnt++;
        if (s == "terrible" || s == "don't even" || s == "worse" || s == "are you serious" || s == "go die in a hole" || s == "no way") rev++;
    }

    cout << (cnt > rev ? "normal" : "grumpy") << endl;

    return 0;
}
