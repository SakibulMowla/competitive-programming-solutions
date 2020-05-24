#include <stdio.h>

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}

#define SZ 20

int arr[SZ];

bool check(int n, int b) {
    int idx = 0;
    while(n) {
        arr[idx++] = n % b;
        n /= b;
    }
    for (int i = 0; i < idx/2; i++) if(arr[i] != arr[idx-i-1]) return false;
    return true;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    while(scanf("%d", &n) == 1) {
        bool f = 0;
        int b;
        for (b = 2; b * b <= n; b++) if(n % b != 0 && check(n, b)) {
            f = 1;
            break;
        }
        if(!f) {
            b = n + 1;
            for (int a = 1; a * a <= n; a++) if(n % a == 0) {
                if((n / a - 1) > a)
                    b = n / a - 1;
            }
        }
        printf("%d\n", b);
    }

    return 0;
}




