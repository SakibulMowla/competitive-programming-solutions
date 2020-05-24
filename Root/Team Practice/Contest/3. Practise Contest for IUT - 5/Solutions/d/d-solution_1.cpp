// CERC 2012
// Problem D: Non-boring sequences
// Model solution. O(n lg n)
// Author: Adam Polak

#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 200000;

int n, a[MAXN], values[MAXN];
int prev[MAXN], next[MAXN], last[MAXN];

bool IsBoring(int beg, int end) {
  if (beg == end) return false;
  for (int i = 0; i < (end - beg); ++i) {
    int mid = ((i & 1) ? beg + i / 2 : end - 1 - i / 2);
    if (prev[mid] < beg && next[mid] >= end)
      return IsBoring(beg, mid) || IsBoring(mid+1, end);
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      values[i] = a[i];
    }
    sort(values, values + n);
    int m = unique(values, values + n) - values;
    for (int i = 0; i < n; ++i)
      a[i] = lower_bound(values, values + m, a[i]) - values;

    for (int i = 0; i < m; ++i) last[i] = -1;
    for (int i = 0; i < n; ++i) {
      prev[i] = last[a[i]];
      last[a[i]] = i;
    }
    for (int i = 0; i < m; ++i) last[i] = n;
    for (int i = n-1; i >= 0; --i) {
      next[i] = last[a[i]];
      last[a[i]] = i;
    }
    
    cout << (IsBoring(0, n) ? "boring\n" : "non-boring\n");
   } 
  return 0;
}

