#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define sz(x) (int)x.size()

#define X first
#define Y second

struct data {
    double prob;
    ll cnt;
    data (double prob, ll cnt): prob(prob), cnt(cnt) {}
    bool operator < (const data &x) const {
        return prob > x.prob;
    }
};

struct Huffman {
    int n;
    double pa, pb, pc, pd;
    vector <ll> f;
    priority_queue <data> pq;

    Huffman (): f(21, 1) {
        for (int i = 1; i <= 20; i++) {
            f[i] = (ll)i * f[i-1];
        }
    }

    double Power (double b, int p) {
        double ans = 1.0;
        for (int i = 0; i < p; i++) {
            ans *= b;
        }
        return ans;
    }

    void Process () {
        while (!pq.empty()) {
            pq.pop();
        }

        for (int a = 0; a <= n; a++) {
            for (int b = 0; a + b <= n; b++) {
                for (int c = 0; a + b + c <= n; c++) {
                    int d = n - a - b - c;
                    ll cnt = f[n] / f[a] / f[b] / f[c] / f[d];
                    double prob = Power(pa, a) * Power(pb, b) * Power(pc, c) * Power(pd, d);
                    pq.push(data(prob, cnt));
                }
            }
        }
    }

    double ExpectedLength () {
        double ans = 0.0;

        while (sz(pq) != 1) {
            data u = pq.top(); pq.pop();
            if (u.cnt != 1) {
                ans += u.cnt * u.prob;
                pq.push(data(u.prob * 2.0, u.cnt / 2LL));
                if (u.cnt & 1) {
                    ans -= u.prob;
                    pq.push(data(u.prob, 1));
                }
            } else {
                data v = pq.top(); pq.pop();
                ans += u.prob + v.prob;
                pq.push(data(u.prob + v.prob, 1));
                if (v.cnt != 1) {
                    pq.push(data(v.prob, v.cnt - 1LL));
                }
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Huffman Task = Huffman();

    while (cin >> Task.n) {
        cin >> Task.pa >> Task.pb >> Task.pc >> Task.pd;
        Task.Process();
        cout << fixed << setprecision(10) << Task.ExpectedLength() << endl;
    }

    return 0;
}


