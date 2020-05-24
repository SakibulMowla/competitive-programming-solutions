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
const double PI = 3.1415926535897932;


#define SZ 100010


int main() {
//#if defined JESI
//        freopen("progress_pie.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
//#endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int P, X, Y;
        cin >> P >> X >> Y;

        bool flag = false;
        int dist = (50 - X) * (50 - X) + (50 - Y) * (50 - Y);

        if (P && dist <= 2500) {
            double endAngle = P * 3.6;
            double pointAngle;

            if (X == 50) {
                if (Y >= 50) pointAngle = 0;
                else pointAngle = 180;
            } else if (Y == 50) {
				if (X >= 50) pointAngle = 90;
				else pointAngle = 270;
			} else if (X > 50 && Y > 50) {
				pointAngle = atan2(Y - 50, X - 50) * 180.0 / PI;
				pointAngle = 90 - pointAngle;
			} else if (X < 50 && Y > 50) {
				pointAngle = atan2(Y - 50, X - 50) * 180.0 / PI;
				pointAngle = (180 - pointAngle) + 270;
			} else if (X < 50 && Y < 50) {
				pointAngle = atan2(50 - Y, 50 - X) * 180.0 / PI;
				pointAngle = pointAngle + 180;
				pointAngle = (270 - pointAngle) + 180;
			} else if (X > 50 && Y < 50) {
				pointAngle = atan2(Y - 50, X - 50) * 180.0 / PI;
				pointAngle = pointAngle + 360;
				pointAngle = (360 - pointAngle) + 90;
			}

			flag = (pointAngle <= endAngle);
        }

        cout << "Case #" << cs + 1 << ": " << (flag? "black": "white") << endl;
    }

    return 0;
}




