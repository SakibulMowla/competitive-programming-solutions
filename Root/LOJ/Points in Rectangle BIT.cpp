#include <bits/stdc++.h>

using namespace  std;

void RD(int &x){scanf("%d",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void PR(int x) {printf("%d\n",x);}

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

#define mem(a,b) memset(a, b, sizeof(a))

#define SZ 1002

bool arr[SZ][SZ];
int tree[SZ][SZ];

void update(int xx, int yy){
    int x, y;
    x = xx;
    while(x <= 1001){
        y = yy;
        while(y <= 1001){
            tree[x][y]++;
            y += (y & -y);
        }
        x += (x & -x);
    }
}

int query(int xx, int yy){
    int x, y, sum=0;
    x = xx;
    while(x > 0){
        y = yy;
        while(y > 0){
            sum += tree[x][y];
            y -= (y & -y);
        }
        x -= (x & -x);
    }
    return sum;
}

int main() {
    int test=0, t, q, k, r, c, lx, ly, ux, uy;

//    RD(t);
    inp(t);

    while(t--){
//        RD(q);
        inp(q);
        mem(tree, 0);
        mem(arr, 0);

        printf("Case %d:\n",++test);

        while(q--){
//            RD(k);
            inp(k);
            if(k == 0){
//                RD(r, c);
                inp(r);inp(c);
                r++, c++;
                if(arr[r][c]) continue;
                update(r, c);
                arr[r][c] = 1;
            }
            else{
//                RD(ux, uy);
//                RD(lx, ly);
                inp(ux);inp(uy);
                inp(lx);inp(ly);
                ux++, uy++, lx++, ly++;
                PR(query(lx, ly)-query(ux-1, ly)-query(lx, uy-1)+query(ux-1, uy-1));
            }
        }
    }


    return 0;
}













