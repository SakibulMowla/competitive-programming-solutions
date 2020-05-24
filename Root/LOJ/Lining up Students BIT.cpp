#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)


#define SZ 100010

int arr[SZ];
int tree[SZ];
int n;


void update(int indx, int val) {
    while(indx <= n){
        tree[indx] += val;
        indx += (indx & -indx);
    }
}


int query(int indx) {
    int sum = 0;
    while(indx > 0){
        sum += tree[indx];
        indx -= (indx & -indx);
    }
    return sum;
}


int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    int test=0, t, i, num, m, lo, hi, mid, alive, pos;

    RD(t);
//    inp(t);

    while(t--) {
        RD(n);
//        inp(n);
        m = n;

        REP1(i, 1, n) RD(arr[i]), update(i, 1);

        REP2(i, n, 1) {
            num = m - arr[i];

            lo = 1;
            hi = n;

            while(lo <= hi) {
                mid = (lo + hi) >> 1;
                alive = query(mid);

                if(alive == num) {
                    pos = mid;
                    hi = mid - 1;
                }
                else if(alive > num)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }

            update(pos, -1);
            m--;
        }

        printf("Case %d: %d\n",++test,pos);
    }


    return 0;
}













