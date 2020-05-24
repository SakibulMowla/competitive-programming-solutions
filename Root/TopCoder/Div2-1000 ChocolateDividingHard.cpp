#include <bits/stdc++.h>

using namespace std;


class ChocolateDividingHard {
public:
    vector <string> choco;
    int cum[80][80];

    void pre() {
        memset(cum, 0, sizeof cum);

        int n = choco.size();
        int m = choco[0].size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                cum[i][j] = choco[i][j]-'0';
                if(j) cum[i][j] += cum[i][j-1];
            }

        for(int i = 1; i < n; i++)
            for(int j = 0; j < m; j++)
                cum[i][j] += cum[i-1][j];
    }

    int calc(int x1, int y1, int x2, int y2) {
        int area = cum[x2][y2];
        if(x1 != -1) area -= cum[x1][y2];
        if(y1 != -1) area -= cum[x2][y1];
        if(x1 != -1 && y1 != -1) area += cum[x1][y1];
        return area;
    }

    bool possible(int n, int c1, int c2, int c3, int mid, int now, int pre) {
        int area = calc(-1, pre-1, c1-1, now-1); if(area < mid) return false;
        area = calc(c1-1, pre-1, c2-1, now-1); if(area < mid) return false;
        area = calc(c2-1, pre-1, c3-1, now-1); if(area < mid) return false;
        area = calc(c3-1, pre-1, n-1, now-1); if(area < mid) return false;
        return true;
    }

    bool f(int mid) {
        int n = choco.size();
        int m = choco[0].size();

        for(int i = 1; i <= n-1; i++) {
            for(int j = i+1; j <= n-1; j++) {
                for(int k = j+1; k <= n-1; k++) {
                    int cnt = 0, p = 1, pre = 0;
                    while(p <= m) {
                        if(possible(n, i, j, k, mid, p, pre)) {
                            cnt++;
                            pre = p;
                            if(cnt == 4)
                                return true;
                        }
                        p++;
                    }
                }
            }
        }

        return false;
    }

	int findBest(vector <string> chocolate) {
		choco = chocolate;
		pre();

		int lo = 0;
        int hi = choco.size()*choco[0].size()*9;
        int ans = 0;

        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(f(mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return ans;
	}
};
