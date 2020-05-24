/**
        Implementation of Pollard's Rho algorithm with Random Seed and Mod value
        Running time:
            Dunno { Reasonable I hope :) } find out sometime ...
        Usage:
            - values of seed, seeds, mod can be changed in the constructor
            - calling findFactor wiil return a factor of n
        Input:
            - a number n whose factor is to find
        Output:
            - a factor of n and -1 if there is no factor of n
        Tested Problems:
**/

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

struct PollardsRho {
    ll n, mod;
    int now, seeds;
    ll seed[3];

    PollardsRho () {}
    PollardsRho (ll n) {
        this->n = n;
        now = 0;
        seeds = 3;
        seed[0] = 2LL;
        seed[1] = 3LL;
        seed[2] = 5LL;
        mod = 55LL;
    }

    inline ll f (ll x) {
        x = (x * x + seed[now]) % mod;
    }

    void changeSeed () {
        now++;
        if (now >= seeds) now -= seeds;
    }

    ll findFactor () {
        for (int k = 0; k < seeds; k++) {
            for (int i = 0; i < seeds; i++) {
                ll a = seed[i];
                ll b = seed[i];
                a = f(a);
                b = f(f(b));
                while (a != b) {
                    ll p = __gcd(llabs(a-b), n);
                    if (p > 1LL) {
                        return p;
                    }
                    a = f(a);
                    b = f(f(b));
                }
            }
            changeSeed();
        }
        return -1;
    }
};


int main () {
    PollardsRho *pr;
    ll n;

    while (cin >> n) {
        pr = new PollardsRho(n);

        ll p = pr->findFactor();

        if (p != -1) printf("One of the factors of the number %lld is : %lld (using Pollard's Rho)\n", n, p);
        else printf("Couldn't find factor of %lld using Pollard's Rho!\n", n);
    }

    return 0;
}
