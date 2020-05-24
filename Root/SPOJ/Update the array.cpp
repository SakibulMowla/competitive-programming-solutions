#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void PR(int x) {printf("%d\n",x);}

#define SZ 10010

struct BIT { ///Range Update Point Query [1D]
    int n;
    int tree[SZ];

    void init() {
        memset(tree, 0, sizeof(int)*(n+2));
    }

    void update(int indx, int val) {
        while(indx <= n) {
            tree[indx] += val;
            indx += (indx & -indx);
        }
    }

    void update(int l, int r, int val) {
        update(l, val);
        update(r+1, -val);
    }

    int query(int indx) {
        int sum = 0;
        while(indx > 0) {
            sum += tree[indx];
            indx -= (indx & -indx);
        }
        return sum;
    }
};

int main() {
    BIT bit;
    int t, u, q, l, r, val;

    RD(t);

    while(t--){
        RD(bit.n);
        RD(u);

        bit.init();

        while(u--) {
            RD(l); l++;
            RD(r); r++;
            RD(val);
            bit.update(l, r, val);
        }

        RD(q);

        while(q--){
            RD(l);
            l++;
            PR(bit.query(l));
        }
    }



    return 0;
}



