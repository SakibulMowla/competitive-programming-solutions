#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    char arr[200];
    arr['G'] = 'g';
    arr['g'] = 'G';
    arr['o'] = 'O';
    arr['O'] = 'o';
    arr['c'] = 'C';
    arr['C'] = 'c';

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        cin >> s;
        for (int i = 0; i < 3; i++) {
            s[i] = arr[s[i]];
        }
        cout << s << endl;
    }

    return 0;
}
