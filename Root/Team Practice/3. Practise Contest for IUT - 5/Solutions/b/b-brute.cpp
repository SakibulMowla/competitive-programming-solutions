// CERC 2012
// Problem B: Who wants to live forever?
// Brute-force simulating solution - TLE
// Author: Bartosz Walczak

#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

typedef unsigned long type;
const int group = sizeof(type)*8;
const int iterations = INT_MAX;

char str[1000001];
type table[1000000/group+2];

void testcase() {
    gets(str);
    int n = strlen(str);
    int m = n/group+1, r = n%group;
    type b = 1U;
    int index = 0;
    for (int i=0; i<=m; ++i) table[i] = 0U;
    for (int i=0; i<n; ++i) {
        table[index] |= b & static_cast<signed char>('0'-str[i]);
        index += b>>group-1;
        b = b<<1 | b>>group-1;
    }
    for (int iter = min(iterations, n); iter; --iter) {
        type last = 0U;
        for (int i=0; i<m; ++i) {
            type next = (table[i]<<1 | last>>group-1) ^ (table[i]>>1 | table[i+1]<<group-1);
            last = table[i];
            table[i] = next;
        }
        table[m-1] &= (static_cast<type>(1U)<<r)-1U;
    }
    type result = 0U;
    for (int i=0; i<m; ++i) result |= table[i];
    printf(result ? "LIVES\n" : "DIES\n");
}

int main() {
    int t; scanf("%d\n", &t);
    for (; t; --t) testcase();
    return 0;
}
