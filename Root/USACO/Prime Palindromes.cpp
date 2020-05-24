/*
    ID: sakibul1
    PROG: pprime
    LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> v;

#define SZ 100010

bool arr[SZ];
vector <int> prime;

void sieve () {
    int k = sqrt(SZ);
    for (int i = 3; i <= k; i += 2) {
        if (!arr[i]) {
            for (ll j = (ll)i * (ll)i; j < SZ; j += i + i) {
                arr[j] = 1;
            }
        }
    }
    prime.push_back(2);
    for (int i = 3; i < SZ; i += 2) {
        if (!arr[i]) {
            prime.push_back(i);
        }
    }
    return;
}

bool isPrime (int n) {
    for (int i = 0; i < prime.size() && (ll)prime[i] * (ll)prime[i] <= (ll)n; i++) {
        if (n % prime[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
//    freopen("pprime.in", "r", stdin);
//    freopen("pprime.out", "w", stdout);

    ios::sync_with_stdio(0);

    sieve();

    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    for (int d1 = 1; d1 <= 9; d1 += 2) { /// 2 digit
        int n = 10*d1 + d1;
        if (isPrime(n)) v.push_back(n);
    }
    for (int d1 = 1; d1 <= 9; d1 += 2) { /// 3 digit
        for (int d2 = 0; d2 < 10; d2++) {
            int n = 100*d1 + 10*d2 + d1;
            if (isPrime(n)) v.push_back(n);
        }
    }
    for (int d1 = 1; d1 <= 9; d1 += 2) { /// 4 digit
        for (int d2 = 0; d2 < 10; d2++) {
            int n = 1000*d1 + 110*d2 + d1;
            if (isPrime(n)) v.push_back(n);
        }
    }
    for (int d1 = 1; d1 <= 9; d1 += 2) { /// 5 digit
        for (int d2 = 0; d2 < 10; d2++) {
            for (int d3 = 0; d3 < 10; d3++) {
                int n = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
                if (isPrime(n)) v.push_back(n);
            }
        }
    }
    for (int d1 = 1; d1 <= 9; d1 += 2) { /// 6 digit
        for (int d2 = 0; d2 < 10; d2++) {
            for (int d3 = 0; d3 < 10; d3++) {
                int n = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
                if (isPrime(n)) v.push_back(n);
            }
        }
    }
    for (int d1 = 1; d1 <= 9; d1 += 2) { /// 7 digit
        for (int d2 = 0; d2 < 10; d2++) {
            for (int d3 = 0; d3 < 10; d3++) {
                for (int d4 = 0; d4 < 10; d4++) {
                    int n = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
                    if (isPrime(n)) v.push_back(n);
                }
            }
        }
    }
    for (int d1 = 1; d1 <= 9; d1 += 2) { /// 8 digit
        for (int d2 = 0; d2 < 10; d2++) {
            for (int d3 = 0; d3 < 10; d3++) {
                for (int d4 = 0; d4 < 10; d4++) {
                    int n = 10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 + 1000*d4 + 100*d3 + 10*d2 + d1;
                    if (isPrime(n)) v.push_back(n);
                }
            }
        }
    }
    for (int d1 = 1; d1 <= 9; d1 += 2) { /// 9 digit
        for (int d2 = 0; d2 < 10; d2++) {
            for (int d3 = 0; d3 < 10; d3++) {
                for (int d4 = 0; d4 < 10; d4++) {
                    for (int d5 = 0; d5 < 10; d5++) {
                        int n = 100000000*d1 + 10000000*d2 + 1000000*d3 + 100000*d4 + 10000*d5 + 1000*d4 + 100*d3 + 10*d2 + d1;
                        if (isPrime(n)) v.push_back(n);
                    }
                }
            }
        }
    }

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > b) {
            break;
        }
        if (v[i] >= a) {
            cout << v[i] << '\n';
        }
    }

	return 0;
}


