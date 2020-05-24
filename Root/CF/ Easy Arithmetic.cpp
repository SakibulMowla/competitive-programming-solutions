#include <bits/stdc++.h>

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

void doit (string &s) {
    if (sz(s) == 1) {
        cout << s;
    } else {
        cout << s[0];
//        cout << '+';
        for (int i = 1; i < sz(s); i++) {
            cout << '+';
            if (s[i] == '0') {
                cout << s[i];
            } else {
                cout << s.substr(i);
                break;
            }
        }
    }
    return;
}

int main() {
//    #if defined JESI
        freopen("easy.in", "r", stdin);
        freopen("easy.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    char arr[1010];
    char *s;

    vector <char> Signs;
    vector <string> nums;

    scanf(" %s", arr);
    for (int i = 0; arr[i]; i++) {
        if (arr[i] == '-' || arr[i] == '+') {
            Signs.pb(arr[i]);
        }
    }

    s = strtok(arr, "+-");
    while (s != NULL) {
        nums.pb(s);
        s = strtok(NULL, "+-");
    }

    char pre = '+';
    bool go = false;
    if (sz(Signs) == sz(nums)) {
        go = true;
        pre = Signs[0];
        Signs.erase(Signs.begin());
    }

//    cout << sz(Signs) << ' ' << sz(nums) << endl;

    for (int i = 0; i < sz(nums); i++) {
        if (go) cout << pre;
        else go = true;
        if (pre == '+') {
            cout << nums[i];
        } else {
            doit(nums[i]);
        }
        if (i < sz(Signs)) pre = Signs[i];
    }
    cout << endl;


    return 0;
}





