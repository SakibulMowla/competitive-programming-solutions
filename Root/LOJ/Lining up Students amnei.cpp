#include <stdio.h>

void RD(int &x){scanf("%d",&x);}


inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int main() {
    int test=0, t, i, n, left, ans;

    inp(t);

    while(t--) {
        inp(n);
        ans = 0;

        RD(left);
        for(i=1;i<=n-1;i++) {
            inp(left);
            if(left <= ans) ans++;
        }

        printf("Case %d: %d\n",++test,n-ans);
    }


    return 0;
}













