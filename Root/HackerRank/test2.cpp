#pragma warning ( disable : 4786 )

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <cassert>
#include <ctime>
using namespace std;

//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep( i, a, b, x ) for( i = ( a ); i <= ( b ); i += x )
#define rep( i, n ) _rep( i, 0, n - 1, 1 )

#define ff first
#define ss second

#define pii pair< int, int >
#define psi pair< string, int >

#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define set(p) memset(p, -1, sizeof(p))
#define clr(p) memset(p, 0, sizeof(p))

typedef long long i64;
//typedef __int64 i64;
typedef long double ld;

//const double pi = (2.0*acos(0.0));
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = (1<<28);
const int MIN_LEN = 1;
const int MAX_LEN = 1000;

int r, c;
int mat[MAX_LEN+5][MAX_LEN+5];
double c_sum[MAX_LEN+5][MAX_LEN+5], csq_sum[MAX_LEN+5][MAX_LEN+5];

void gen_cumulative_sum() {
    int i, j, k, tmp;

    for(i=0; i<=r; i+=1) {
        for(j=0; j<=c; j+=1) {
            c_sum[i][j] = 0.0;
            csq_sum[i][j] = 0.0;
        }
    }

    for(i=1; i<=r; i+=1) {
        for(j=1; j<=c; j+=1) {
            c_sum[i][j] = (double)mat[i][j] + c_sum[i-1][j] + c_sum[i][j-1] - c_sum[i-1][j-1];
            csq_sum[i][j] = ((double)mat[i][j]*(double)mat[i][j]) + csq_sum[i-1][j] + csq_sum[i][j-1] - csq_sum[i-1][j-1];
        }
    }
}

void print_cumulative_sum() {
    int i, j;

    for(i=1; i<=r; i+=1) {
        for(j=1; j<=c; j+=1) {
            printf("%.0lf ", c_sum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=1; i<=r; i+=1) {
        for(j=1; j<=c; j+=1) {
            printf("%.0lf ", csq_sum[i][j]);
        }
        printf("\n");
    }
}

double solve(int x1, int y1, int x2, int y2) {
    //formula: sum_sq/n - sum^2/n^2
    double n = (double)(x2-x1+1) * (double)(y2-y1+1);
    double first_term = (csq_sum[x2][y2] - csq_sum[x1][y1-1] - csq_sum[x1-1][y1] + csq_sum[x1-1][y1-1]) / n;
    double second_term = ((c_sum[x2][y2] - c_sum[x1][y1-1] - c_sum[x1-1][y1] + c_sum[x1-1][y1-1]) / n) * ((c_sum[x2][y2] - c_sum[x1][y1-1] - c_sum[x1-1][y1] + c_sum[x1-1][y1-1]) / n);
    return first_term - second_term;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset <int> ms;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            ms.insert(-nums[i]);
        }
        for (int i = k; i < n; i++) {
            ms.insert(-nums[i]);
            ms.erase(prev(ms.end()));
        }
        return -(*prev(ms.end()));
    }
};

int main() {
    freopen("in0.txt", "w", stdout);

    int t = 10;
    cout << t << endl;

    for (int cs = 0; cs < t; cs++) {
        int l = (rand() % 80) + 2;
        int n = (rand() % 10) + 1;
        cout << l << ' ' <<  n << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << rand() % 100 << ' ';
            }
            cout << endl;
        }
    }

	return 0;
}
