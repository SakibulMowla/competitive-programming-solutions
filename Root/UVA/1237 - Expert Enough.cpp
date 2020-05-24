#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using PSI = pair<string, int>;

const int LIMIT = 1000001;

int main() {
    ios::sync_with_stdio(false);

    // using lambda to compare elements.
    auto compare = [](PSI lhs, PSI rhs) {
        return lhs.second > rhs.second;
    };

    int cases;
    cin >> cases;

    while (cases--) {
        int D;
        cin >> D;

        vector<vector<PSI>> nameAndHigh(LIMIT, vector<PSI>());
        priority_queue<PSI, vector<PSI>, decltype(compare)> pq(compare);
        vector<string> ans(LIMIT, "UNDETERMINED");

        while (D--) {
            string M;
            int L, H;
            cin >> M >> L >> H;
            nameAndHigh[L].push_back({M, H});
        }

        for (int i = 0; i < LIMIT; i++) {
            for (auto& item: nameAndHigh[i]) {
                pq.push(item);
            }

            while (!pq.empty()) {
                auto item = pq.top();
                if (item.second < i) {
                    pq.pop();
                } else {
                    break;
                }
            }

            if (pq.size() == 1) {
                auto item = pq.top();
                ans[i] = item.first;
            }
        }

        int Q;
        cin >> Q;

        while (Q--) {
            int P;
            cin >> P;
            cout << ans[P] << '\n';
        }

        if (cases) {
            cout << '\n';
        }
    }        

    return 0;
}
