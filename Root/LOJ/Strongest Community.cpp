#include <bits/stdc++.h>

using namespace  std;

void RD(int &x){scanf("%d",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void PR(int x) {printf("%d\n",x);}


#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

#define SZ  100010
#define SZ1 262150

#define left node<<1, b, mid
#define riht node<<1|1, mid+1, e

struct data{
    int b, e, cnt;
};

int tree[SZ1];
data info[SZ];
int arr[SZ];

class Problem {
    public:
    int test, i, j, k, n, c, q, pos, ans;

    Problem() {
        test = 0;
    }

    void init() {
    }

    void take_input() {
        RD(n);
        RD(c, q);
        REP1(i, 1, n) RD(arr[i]);
    }

    void process() {
        for(i=1; i<=n; i++){
            pos = i;
            while(pos+1 <= n && arr[pos+1] == arr[pos]) pos++;

            j = i;
            k = pos-i+1;

            while(j <= pos) {
                info[j].b = i;
                info[j].e = pos;
                info[j].cnt = k;
                j++;
            }

            i = pos;
        }
    }

    void solve() {
        printf("Case %d:\n",++test);

        build(1, 1, n);

        while(q--){
            RD(i, j);

            ans = max(min(info[i].e,j)-i+1, j-max(info[j].b,i)+1);
            if(info[i].e+1 <= info[j].b-1)
                ans = max(ans, query(1, 1, n, info[i].e+1, info[j].b-1));

            PR(ans);
        }
    }

    void build(int node, int b, int e) {
        if(b == e){
            tree[node] = info[b].cnt;
            return;
        }

        int mid = (b + e) >> 1;

        build(left);
        build(riht);

        tree[node] = max(tree[node<<1], tree[node<<1|1]);
    }

    int query(int node, int b, int e, int f, int t){
        if(b>=f && e<=t)
            return tree[node];

        int mid = (b + e) >> 1, ret = 0;

        if(f <= mid) ret = query(left, f, t);
        if(t > mid) ret = max(ret, query(riht, f, t));

        return ret;
    }
};

int main() {
    Problem Strongest_Community;
    int t;

    RD(t);

    while(t--){
        Strongest_Community.take_input();
        Strongest_Community.process();
        Strongest_Community.solve();
    }


    return 0;
}













