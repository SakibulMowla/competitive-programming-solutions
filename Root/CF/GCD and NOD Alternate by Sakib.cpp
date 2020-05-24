#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LIM = 1000000000000000000;

int main() {
    ios::sync_with_stdio(false);

    vector <ll> two, three;

    two.push_back(1);
    for (int i = 1; i < 70; i++) {
        two.push_back(two[i-1] * 2);
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll g, a, b;
        cin >> g >> a >> b;

        ll twoCount = 1, threeCount = 1, tmpg = g;

        while (tmpg % 2 == 0) {
            tmpg /= 2;
            twoCount++;
        }

        while (tmpg % 3 == 0) {
            tmpg /= 3;
            threeCount++;
        }

        assert(tmpg == 1);

        pair <ll, ll> ans = make_pair(numeric_limits<ll>::max(), numeric_limits<ll>::max());

        if (a % twoCount == 0 && b % threeCount == 0 && a / twoCount >= threeCount && b / threeCount >= twoCount) {
            pair <ll, ll> tmp = make_pair(g, g);
            bool flag = true;
            ll tmp3cnt = threeCount, tmp2cnt = twoCount;
            while (tmp3cnt < a / twoCount) {
                tmp.first *= 3;
                tmp3cnt++;
                if (tmp.first > LIM) {
                    flag = false;
                    break;
                }
            }
            while (tmp2cnt < b / threeCount) {
                tmp.second *= 2;
                tmp2cnt++;
                if (tmp.second > LIM) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = min(ans, tmp);
            }
        }
        if (a % threeCount == 0 && b % twoCount == 0 && a / threeCount >= twoCount && b / twoCount >= threeCount) {
            pair <ll, ll> tmp = make_pair(g, g);
            bool flag = true;
            ll tmp3cnt = threeCount, tmp2cnt = twoCount;
            while (tmp2cnt < a / threeCount) {
                tmp.first *= 2;
                tmp2cnt++;
                if (tmp.first > LIM) {
                    flag = false;
                    break;
                }
            }
            while (tmp3cnt < b / twoCount) {
                tmp.second *= 3;
                tmp3cnt++;
                if (tmp.second > LIM) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = min(ans, tmp);
            }
        }
        if (twoCount * threeCount == a) {
            for (int i = twoCount; i <= 61; i++) {
                if (b % i == 0 && b / i >= threeCount) {
                    ll x = two[i - 1];
                    bool flag = true;
                    for (int j = 1; j <= ((b/i) - 1); j++) {
                        x = (x * 3);
                        if (x > LIM) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        ans = min(ans, make_pair(g, x));
                    }
                }
            }
        }
        if (twoCount * threeCount == b) {
            for (int i = twoCount; i <= 61; i++) {
                if (a % i == 0 && a / i >= threeCount) {
                    ll x = two[i - 1];
                    bool flag = true;
                    for (int j = 1; j <= ((a/i) - 1); j++) {
                        x = (x * 3);
                        if (x > LIM) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        ans = min(ans, make_pair(x, g));
                    }
                }
            }
        }

        cout << ans.first << ' ' << ans.second << endl;
    }

    return 0;
}

