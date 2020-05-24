#include <stdio.h>

using namespace  std;

typedef long long ll;

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}


template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
//    scanf("%d", &t);
    inp(t);

    for (int cs = 0; cs < t; cs++) {
        int n;
//        scanf("%d", &n);
        inp(n);

        ll l = 1LL;
        for (int i = 0; i < n; i++) {
            int x;
//            scanf("%d", &x);
            inp(x);
            l = lcm(l, (ll)x);
        }
        l *= 35LL;

        printf("Case %d: %lld\n", cs+1, l);
    }

    return 0;
}


