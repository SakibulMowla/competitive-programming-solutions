#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct NBitMasking {
    int limit;
    int base;
    vector<int> power;

    /**
        initializes the masking system
        with provided base and limit
        limit is the highest power of the base that will be used
    **/    
    NBitMasking(int base, int limit): base(base), limit(limit), power(limit + 1, 1) {
        for (int i = 1; i <= limit; i++) {
            power[i] = base * power[i - 1];
        }
    }

    /**
        0 - based
        finds the pos-th bit of the number mask
    **/
    int getBit(int mask, int pos) {
        return (mask / power[pos]) % base;
    }

    /**
        0 - based
        sets the pos-th bit of mask as bit and returns the new mask
    **/
    int setBit(int mask, int pos, int bit) {
        int tmp = (mask / power[pos]) % base;
        mask -= tmp * power[pos];
        mask += bit * power[pos];
        return mask;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (auto& edge: edges) {
        cin >> edge.first >> edge.second;
    }

    NBitMasking nBitMasking(6, n);

    int ans = 0;
    for (int mask = 0; mask < nBitMasking.power[n]; mask++) {
        set<pair<int, int>> marked;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int nodeA = edges[i].first;
            int nodeB = edges[i].second;

            int valA = nBitMasking.getBit(mask, nodeA - 1);
            int valB = nBitMasking.getBit(mask, nodeB - 1);

            if (marked.find({min(valA, valB), max(valA, valB)}) == marked.end()) {
                cnt++;
                marked.insert({min(valA, valB), max(valA, valB)});
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}
