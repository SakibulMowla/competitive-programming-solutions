#include "stdio.h"

#define SZ 100

int n;
int arr[SZ];
int tree[SZ];

/// BY TOURIST
void update(int x, int v) {
  while (x <= n) {
    x = (x | (x - 1)) + 1;
  }
}

int query(int x) {
  while (x > 0) {
    x &= x - 1;
  }
  return v;
}
/// BY TOURIST

///Cumulative sum from 1 to idx
int read(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

///Updates a indx with some value val and updates all its post-decessors
void update(int idx, int val) {
    while(idx <= n) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

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

/// 1-based indexing

int main() {
    freopen("1.txt","r",stdin);
    int i, j, k, m;

    while(scanf("%d %d",&n,&m) == 2) {

        printf("nm   %d %d\n",n,m);

        for(i=1; i<=n; i++) {
            printf("Indx ================== %d\n",i);
            scanf("%d",&arr[i]);
            update(i, arr[i]);
        }

        for(i=1;i<=n;i++)
            printf("Sum[%d] = %d\n",i,read(i));
//
        while(m--){
            scanf("%d",&k);
            if(k == 1){ /// Update
                scanf("%d %d",&i,&j);
                update(i, -arr[i]); /// erasing the previous value
                update(i, j); /// updating with new value
                arr[i] = j;
            }

            else if(k == 2){ /// Query
                scanf("%d %d",&i,&j);
                printf("sum = %d\n",read(j)-read(i-1));
            }
        }
    }


    return 0;
}
