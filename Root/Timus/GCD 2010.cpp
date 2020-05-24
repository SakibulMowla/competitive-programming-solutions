#include <stdio.h>
#include <map>
#include <iostream>

using namespace  std;

template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}

#define SZ  100010
#define SZ1 262150

int tree[SZ1];
map <int,int> mp, mp1;

inline void update(int node, int b, int e, int x, int val){
    int par;
    while(1){
        if(b==e){
            tree[node] = val;
            par = node;
            while(par!=1){
                par >>= 1;
                tree[par] = gcd(tree[par<<1], tree[(par<<1)|1]);
            }
            break;
        }
        int mid = (b+e) >> 1;
        if(x <= mid) e = mid, node <<= 1;
        else         b = mid+1, node = (node<<1)|1;
    }
}

int main() {
    int t, tt, n, elements=0, tmp=0;
    char ch;

    scanf("%d",&t);
    tt = t;
    while(t--){
        getchar();
        ch = getchar();
        scanf("%d",&n);
        if(ch == '+'){
            tmp++;
            elements++;
            mp1[n]++;
            if(mp1[n] == 1){
                update(1, 1, tt, elements, n);
                mp[n] = elements;
            }
        }else{
            tmp--;
            mp1[n]--;
            if(mp1[n] == 0){
                update(1, 1, tt, mp[n], 0);
            }
        }
        if(tmp) printf("%d\n",tree[1]);
        else puts("1");
    }


    return 0;
}
















