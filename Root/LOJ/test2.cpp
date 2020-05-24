/*
	Author       :	Jan
	Problem Name :
	Algorithm    :
	Complexity   :
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 100000007;
const int NN = 100;

int cases, caseno, n, K, A[NN], C[NN], d[1005];

int main() {
	freopen("1.txt", "r", stdin);
	freopen("3.txt", "w", stdout);

	double cl = clock();
	scanf("%d", &cases);
	while( cases-- ) {
		scanf("%d %d", &n, &K);

		for( int i = 0; i < n; i++ ) scanf("%d", &A[i]);
		for( int i = 0; i < n; i++ ) scanf("%d", &C[i]);

		memset( d, 0, sizeof(d) );
		d[0] = 1;
		for( int i = 0; i < n; i++ ) {
			for( int j = K; j >= 0; j-- ) {
				int s = j;
				for( int k = 0; k < C[i]; k++ ) {
					s += A[i];
					if( s > K ) break;
					d[s] = ( d[s] + d[j] ) % MOD;
				}
			}
		}
		printf("Case %d: %d\n", ++caseno, d[K]);
	}

	cl = clock() - cl;
	fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

	return 0;
}
