#include <stdio.h>
#include <stdlib.h>
#include <math.h>


using namespace  std;

typedef long long ll;

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


template <class T> inline T BigMod(T B,T P,T M) {
    T R=1%M;
    B %= 10;
    while(P>0) {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}


#define SZ  20000010
#define SZ1  2000010

bool arr[SZ];
int prime[SZ1];
int cnt;

void sieve() {
    int i, j, k;

    k = sqrt(SZ);

    for(i=3; i<=k; i+=2)
        if(!arr[i])
            for(j=i*i; j<SZ; j+=i+i)
                arr[j] = 1;

    cnt = 0;
    prime[cnt++] = 2;

    for(i=3; i<SZ; i+=2)
        if(!arr[i])
            prime[cnt++] = i;
}

inline int occur(int num, int div) {
    int cnt = 0;

    while(num >= div) {
        cnt += num / div;
        num /= div;
    }

    return cnt;
}

int main() {
    sieve();

    int i, n, r, ans, tmp;

    while(scanf("%d %d",&n,&r) == 2) {
        ans = 1;

        for(i=0; i<cnt && prime[i]<=n; i++) {
            if(prime[i] == 2 || prime[i] == 5) continue;
            ans = (ans * BigMod(prime[i], occur(n, prime[i])-occur(n-r, prime[i]), 10) ) % 10;
        }

        tmp = (occur(n, 2) - occur(n-r, 2)) - (occur(n, 5) - occur(n-r, 5));
        if(tmp > 0) ans = (ans * BigMod(2, tmp, 10)) % 10;
        else if(tmp < 0) ans = (ans * BigMod(5, -tmp, 10)) % 10;

        printf("%d\n",ans);
    }

    return 0;
}



/*
5 1
ans = 5
*/









