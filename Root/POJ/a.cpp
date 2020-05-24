#include <cstdio>
#include <vector>

using namespace std;

#define SZ 10010

int a[SZ];
vector <int> v[SZ];

int main () {
	int n;
	scanf("%d", &n);

	v[0].push_back(0);
	int mod = -1;
	int sum = 0;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum = (sum + a[i]) % n;
		v[sum].push_back(i);
		if (v[sum].size() > 1) {
			mod = sum;
		}
	}

	printf ("%d\n", v[mod][1] - v[mod][0]);
	for (int i = v[mod][0] + 1; i <= v[mod][1]; i++) {
		printf ("%d\n", a[i]);
	}
	
	return 0;
}
