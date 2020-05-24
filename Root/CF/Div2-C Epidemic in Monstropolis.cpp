#include <iostream>
#include <vector>

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

void packet_compress_print (int already, vector <int>& v, int mx) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == mx && i + 1 < v.size() && v[i + 1] < mx) {
            for (int j = i + 1; j < v.size(); j++) {
                cout << already + i + 1 << " R" << endl;
            }
            for (int j = i - 1, k = 0; j >= 0; j--, k++) {
                cout << already + i - k + 1 << " L" << endl;
            }
            break;
        } else if (v[i] == mx && i - 1 >= 0 && v[i - 1] < mx) {
            int last;
            for (int j = i - 1, k = 0; j >= 0; j--, k++) {
                cout << already + i - k + 1 << " L" << endl;
                last = already + i - k;
            }
            for (int j = i + 1; j < v.size(); j++) {
                cout << last << " R" << endl;
            }
            break;
        }
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n);
    for (auto& x: a) {
    	cin >> x;
    }

    int k;
    cin >> k;

    vector <int> b(k);
    for (auto& x: b) {
    	cin >> x;
    }

    vector < vector <int> > aa(k, vector <int> ());
    vector <int> mx(k, 0);
    vector <int> mn(k, 1E9);
    bool flag = true;
    int last = 0;

    for (int i = 0, j = 0; i < k; i++) {
    	for (int cur_sum = 0; j < n; j++) {
            cur_sum += a[j];
            aa[i].push_back(a[j]);
            mx[i] = max(mx[i], a[j]);
            mn[i] = min(mn[i], a[j]);
            if (cur_sum == b[i]) {
                j++;
                last = j;
                break;
            } else if (cur_sum > b[i]) {
                flag = false;
                break;
            }
    	}
    }

    if (last != n) {
        flag = false;
    }

    for (int i = 0; i < k; i++) {
        if ((mx[i] == mn[i] && aa[i].size() > 1) || aa[i].size() == 0) {
            flag = false;
            break;
        }
    }

    if (flag == false) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < k; i++) {
            packet_compress_print(i, aa[i], mx[i]);
        }
    }

    return 0;
}




