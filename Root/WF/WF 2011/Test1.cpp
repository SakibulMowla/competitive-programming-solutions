#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    const int max_height = 200, max_cube = 1024 * 1024;

    vector <int> high(max_height), low(max_height);
    vector <pair <int, int>> pyramids;
    map <pair <int, int>, pair <int, char>> name;

    high[0] = low[0] = 0, high[1] = low[1] = 1;
    for (int i = 2; i < max_height; i++) {
        high[i] = high[i - 1] + i * i;
        low[i] = low[i - 2] + i * i;

        if (high[i] < max_cube) {
            pyramids.emplace_back(high[i], 1);
            name[{high[i], 1}] = {i, 'H'};
        }

        if (low[i] < max_cube && i > 2) {
            pyramids.emplace_back(low[i], 0);
            name[{low[i], 0}] = {i, 'L'};
        }
    }

    sort(pyramids.begin(), pyramids.end(), greater <pair <int, int>>());


    int total_pyramids = pyramids.size();

    vector <int> min_pyramid (max_cube, -1);
    map <pair <int, int>, int> best;

    min_pyramid[0] = 0;
    best[{0, 0}] = -1;
    int cnt = 0;
    for (int i = 0; i < total_pyramids; ++i) {
        int p = pyramids[i].x;
        for (int a = max_cube - 1; a >= p; a--) {
            if (min_pyramid[a - p] != -1 && (min_pyramid[a] == -1 || min_pyramid[a - p] + 1 < min_pyramid[a])) {
                min_pyramid[a] = min_pyramid[a - p] + 1;
                best[{a, min_pyramid[a]}] = i;
                // cout << ++cnt << endl;
            }
        }
    }

    for (int cs = 1, n; cin >> n && n != 0; ++cs) {
        cout << "Case " << cs << ":";
        if (min_pyramid[n] == -1) {
            cout << " impossible" << endl;
        } else {
            for (int i = min_pyramid[n], j = 0; i >= 1; --i) {
                for (; j < total_pyramids; j++) {
                    auto &p = pyramids[j];
                    if (best.count({n - p.x, i - 1})) {
                        cout << ' ' << name[p].x << name[p].y;
                        n -= p.x;
                        j++;
                        break;
                    }
                }
            }
            assert(n == 0);
            cout << endl;
        }
    }

    return 0;
}
