#include <vector>
#include <cstdio>

using namespace std;

#define ll long long

struct Trie {
	int child[2];
	Trie () {
		child[0] = child[1] = -1;
	}
};

struct Solve {
	int n;
	int nodes;
	vector <ll> nums;
	vector <ll> prefix_xor;
	vector <Trie> T;

	Solve (int n): n(n), nums(n + 2, 0), prefix_xor(n + 2, 0), nodes(0) {
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &nums[i]);
			prefix_xor[i] = prefix_xor[i - 1] ^ nums[i];
		}

		T.push_back(Trie());
		insert(0);

		ll ans = 0, xor_sum = 0;
		for (int i = n; i >= 0; i--) {
			ans = max(ans, get_max(prefix_xor[i]));
			xor_sum ^= nums[i];
			insert(xor_sum);
		}

		printf("%lld\n", ans);
	}

	void insert (ll x) {
		int now = 0;
		for (int i = 40; i >= 0; i--) {
			int bit = ((x >> i) & 1);
			if (T[now].child[bit] == -1) {
				T.push_back(Trie());
				T[now].child[bit] = ++nodes;
			}
			now = T[now].child[bit];
		}
		return;
	}

	ll get_max (ll x) {
		ll ret = 0;
		int now = 0;
		for (int i = 40; i >= 0; i--) {
			int bit = ((x >> i) & 1);
			ret <<= 1LL;
			if (T[now].child[bit ^ 1] == -1) {
				now = T[now].child[bit];
			} else {
				ret |= 1;
				now = T[now].child[bit ^ 1];
			}
		}
		return ret;
	}
};

int main() {
	int n;
	scanf("%d", &n);
    Solve sol(n);

    return 0;
}

/*
0332a2d2-1d1d-4c69-a46c-821fc6c11b83
*/
