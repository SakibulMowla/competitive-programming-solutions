#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int tests;
    cin >> tests;

    while (tests--) {
        string seq;
        cin >> seq;

        int len = seq.size();
        string smallestSeq = seq;
        seq = seq + seq;

        for (int i = 0; i < len; i++) {
            string candidate = seq.substr(i, len);
            smallestSeq = min(smallestSeq, candidate);
        }

        cout << smallestSeq << endl;
    }
    
    return 0;
}
