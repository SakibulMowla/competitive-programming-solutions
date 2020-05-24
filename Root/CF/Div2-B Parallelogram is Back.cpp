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


int main() {
	ios::sync_with_stdio(false);

    vector <pii> point(3);
    for (int i = 0; i < 3; i++) {
        cin >> point[i].X >> point[i].Y;
    }

    set <pii> ms;
    pii dif;

    dif.X = point[0].X - point[1].X;
    dif.Y = point[0].Y - point[1].Y;
    ms.insert({point[2].X + dif.X, point[2].Y + dif.Y});
    ms.insert({point[2].X - dif.X, point[2].Y - dif.Y});

    dif.X = point[0].X - point[2].X;
    dif.Y = point[0].Y - point[2].Y;
    ms.insert({point[1].X + dif.X, point[1].Y + dif.Y});
    ms.insert({point[1].X - dif.X, point[1].Y - dif.Y});

    dif.X = point[2].X - point[1].X;
    dif.Y = point[2].Y - point[1].Y;
    ms.insert({point[0].X + dif.X, point[0].Y + dif.Y});
    ms.insert({point[0].X - dif.X, point[0].Y - dif.Y});

    cout << sz(ms) << endl;
    for (auto it: ms) {
        cout << it.X << ' ' << it.second << endl;
    }

    return 0;
}





