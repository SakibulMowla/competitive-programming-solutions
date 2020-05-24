#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string& s) {
    int n = s.size();
    vector <int> z(n);
    /**
        z[i] is the length of the longest common prefix between s and the suffix of s starting at position i.
        z[0] = 0 but the whole string is obviously a suffix and prefix of itself
    **/
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {

    return 0;
}
