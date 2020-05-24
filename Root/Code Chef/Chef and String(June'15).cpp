#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1E9 + 7;

#define SZ  5010

char str[SZ];
int revSA[SZ],SA[SZ];
int cnt[SZ], nxt[SZ];
bool bh[SZ], b2h[SZ];
int lcp[SZ];

bool cmp (int i,int j) {
    return str[i]<str[j];
}

void sortFirstChar (int n) {
    for(int i = 0; i < n; i++)
        SA[i] = i;
    sort(SA, SA+n, cmp);
    for(int i = 0; i < n; i++) {
        bh[i] = ( i==0  || str[SA[i]]!=str[SA[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket (int n) {
    int i, j, bucket = 0;
    for(i = 0, j; i < n ; i = j) {
        j = i+1;
        while(j < n && bh[j] == false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}

void SetRank (int n) {
    int i, j;
    for(i = 0; i < n; i = nxt[i]){
        cnt[i] = 0;
        for(j = i; j < nxt[i]; j++){
            revSA[SA[j]] = i;
        }
    }
    return;
}

void findNewRank (int l, int r, int step) {
    int j, head;
    for(j = l; j < r; j++) {
        int pre = SA[j] - step;
        if(pre >= 0) {
            head = revSA[pre];
            revSA[pre] = head + cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
    return;
}

void findNewBucket (int l,int r,int step) {
    int j, k, pre;
    for(j = l; j < r; j++) {
        pre = SA[j] - step;
        if(pre >= 0 && b2h[revSA[pre]]) {
            for(k = revSA[pre]+1; b2h[k] && !bh[k]; k++) b2h[k] = false;
        }
    }
    return;
}

void buildSA (int n) {
    int h, i;
    sortFirstChar(n);
    for(h = 1; h < n; h <<= 1) {
        if(CountBucket(n)==n) break;
        SetRank(n);
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;

        for(i = 0; i < n; i = nxt[i]) {
            findNewRank(i,nxt[i] , h);
            findNewBucket(i , nxt[i] , h);
        }
        for(i = 0; i < n; i++) {
            SA[revSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    return;
}

void buildLCP (int n) {
    int len = 0, i, k, j;

    for(i = 0; i < n; i++)
        revSA[SA[i]] = i;
    for(i = 0; i < n; i++) {
        k = revSA[i];
        if(k == 0) {
            lcp[k] = 0;
            continue;
        }
        j = SA[k-1];
        while(str[i+len] == str[j+len] && i+len < n && j+len < n) len++;
        lcp[k] = len;
        if(len) len--;
    }
    return;
}

void printSA (int n) {
    int i;
    printf("SA: ");
    for(i=0; i<n; i++) printf("%d ",SA[i]);puts("");
    printf("lcp: ");
    for(i=1; i<n; i++) printf("%d ",lcp[i]);puts("");
    return;
}

ll C[SZ][SZ];
ll ans[SZ];
ll occurr[SZ];
ll match[SZ];
ll Prev[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    for (int i = 0; i <= 5000; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) C[i][j] = 1LL;
			else if (j == 1) C[i][j] = i;
			else C[i][j] = C[i-1][j] + C[i-1][j-1];
			if (C[i][j] >= mod) C[i][j] -= mod;
		}
	}

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, q;
        scanf("%d %d %s", &n, &q, str);

        if (cs) {
            mem(cnt, 0);
            mem(revSA, 0);
            mem(SA, 0);
            mem(nxt, 0);
            mem(b2h, 0);
            mem(bh, 0);
            mem(lcp, 0);
        }

        buildSA(n);
        buildLCP(n);

        if (cs) {
            mem(occurr, 0);
            mem(match, 0);
            mem(Prev, 0);
            mem(ans, 0);
        }

        for (int i = 1; i < n; i++) {
            int mn = lcp[i];
            for (int j = i; j < n; j++) {
                mn = min(mn, lcp[j]);
                match[j] = mn;
            }
            for (int j = n - 1; j >= i; j--) {
                occurr[j - i + 2] += match[j] - max(Prev[j], match[j+1]);
                Prev[j] = match[j];
            }
        }

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				ll tmp = (C[i][j] * occurr[i]) % mod;
				ans[j] = ans[j] + tmp;
				if (ans[j] >= mod) ans[j] -= mod;
			}
		}

		for (int i = 0; i < q; i++) {
			int x;
			scanf("%d", &x);
			if (x == 1) printf("%d\n", n * (n + 1) / 2);
			else if (x <= n) printf("%lld\n", ans[x]);
			else printf("0\n");
		}
    }

    return 0;
}


/*
1
5 5
aaaaa
1 2 3 4 5
*/
