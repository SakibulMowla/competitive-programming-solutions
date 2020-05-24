#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct data {
    int cnt, child[2];
    data () {
        cnt = 0;
        child[0] = child[1] = -1;
    }
};

vector <data> Trie;
int nodes;

void addNumber (int n) {
    int now = 0;
    for (int i = 20; i >= 0; i--) {
        int bit = (n & (1<<i))? 1: 0;
        if (Trie[now].child[bit] == -1) {
            Trie.push_back(data());
            Trie[now].child[bit] = nodes++;
        }
        now = Trie[now].child[bit];
        Trie[now].cnt++;
    }
    return;
}

int Query (int now, int step, int &n, int &k) {
    if (step == -1) return 1;

    ll ret = 0;
    for (int bit1 = 0; bit1 <= 1; bit1++) {
        if (Trie[now].child[bit1] != -1) {
            int bit2 = (n & (1<<step))? 1: 0;
            int bit = (k & (1<<step))? 1: 0;

            if (bit == 1) {
                if (bit1 == bit2) {cout << ">> " << Trie[Trie[now].child[bit1]].cnt << endl;ret += (ll)Trie[Trie[now].child[bit1]].cnt;}
                else ret += Query(Trie[now].child[bit1], step - 1, n, k);
            } else {
                if (bit1 == bit2) ret += Query(Trie[now].child[bit1], step - 1, n, k);
            }
        }
    }

    cerr << ">> step " << step << " ans = " << ret << endl;

    return ret;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        scanf("%d %d", &n, &k);

        Trie.push_back(data());
        nodes = 1;

        ll ans = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);

            int tmp = sum ^ x;
            ans += (ll)Query(0, 20, tmp, k);

            sum = tmp;
            addNumber(sum);

            printf("%lld\n", ans);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
