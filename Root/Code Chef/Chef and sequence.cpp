#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define SZ  100010

int arr[SZ];

void solve1(int n, int k) {
	int i, j, a, d, match, dif, l, cur, na, nd;

	a = 2000000010;
	d = 2000000010;

	for(i = 0; i < n; i++) {
		for(j = i+1; j < n; j++) {
			if((arr[j] - arr[i]) % (j-i) != 0) continue;

			dif = (arr[j] - arr[i]) / (j-i);
			match = 1;

			cur = arr[i];
			for(l = i+1; l < n; l++) {
				cur += dif;
				if(cur == arr[l]) match++;
			}

			cur = arr[i];
			for(l = i-1; l >= 0; l--) {
				cur += dif;
				if(cur == arr[l]) match++;
			}

			if(match >= (n-k)) {
				na = arr[i] - (i * dif);
				nd = dif;
				if(na < a || (na == a && nd < d)) {
					a = na;
					d = nd;
				}
			}
		}
	}

	for(i = 0; i < n; i++) {
		if(i) printf(" ");
		printf("%d",a + i*d);
	}
	printf("\n");

	return;
}

void solve2(int n) {
	int i, j, k, cnt, best, a, d;

	best = 0;

	for(i = 1; i < n; i++) {
		k = arr[i] - arr[i-1];
		j = i;
		cnt = 0;
		while(j+1 < n && (arr[j+1] - arr[j]) == k) {
			j++;
			cnt++;
		}
		if(cnt > best) {
			best = cnt;
			a = arr[i] - (i * k);
			d = k;
		}
		i = j;
	}

	for(i = 0; i < n; i++) {
		if(i) printf(" ");
		printf("%d",a + i*d);
	}
	printf("\n");

	return;
}

int main() {
    int n, k, i;

	scanf("%d %d",&n,&k);

	for(i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}

	if(n < 50) solve1(n, k);
	else solve2(n);

    return 0;
}













