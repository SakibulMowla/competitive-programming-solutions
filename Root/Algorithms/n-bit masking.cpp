#include <bits/stdc++.h>

using namespace std;

struct nBitMasking {
    const int limit = 21;
    const int base = 7;
    vector <int> power;

    nBitMasking() {
        power = vector <int> (limit, 1);
        for (int i = 1; i < limit; i++) power[i] = base * power[i - 1];
    }

    /**
        finds the pos-th bit of the number, mask
    **/
    int getBit(int mask, int pos) {
        return (mask / power[pos]) % base;
    }

    /**
        sets the pos-th bit of mask as bit and returns the new mask
    **/
    int setBit(int mask, int pos, int bit) {
        int tmp = (mask / power[pos]) % base;
        mask -= tmp * power[pos];
        mask += bit * power[pos];
        return mask;
    }
};

int main(){


    return 0;
}
