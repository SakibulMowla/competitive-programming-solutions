#include <bits/stdc++.h>

using namespace  std;

void RD(int &x) {
    scanf("%d",&x);
}

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define ssort(a) stable_sort(a.begin(), a.end())

#define SZ  200010
#define SZ1 524300

#define left node<<1, b, mid
#define riht node<<1|1, mid+1, e


struct data {
    int val, id;
};

bool comp(data a, data b) {
    if(a.val == b.val)
        return a.id < b.id;
    return a.val < b.val;
}

data point[SZ];
int seg[SZ][2];
int tree[SZ1];
set <int> ms;

struct Problem {
    int n, cnt, test;
    Problem();
    void init();
    void take_input();
    void process();
    void update(int,int,int,int,int,int);
    void push_down(int,int,int);
    void query(int,int,int);
    void print_ans();
};

Problem::Problem() {
    test = 0;
}

void Problem::init() {
    cnt = 0;
    mem(tree, 0);
    clr(ms);
}

void Problem::take_input() {
    int i;
    RD(n);
    REP1(i, 1, n) {
        RD(point[(i<<1)-1].val);
        RD(point[i<<1].val);
        point[(i<<1)-1].id = -i;
        point[i<<1].id = i;
    }
}

void Problem::process() {
    int i;

    stable_sort(point+1, point+(n<<1)+1, comp);
    point[0].val = -1;

    REP1(i, 1, n<<1) {
        if(point[i].val != point[i-1].val) cnt++;
        if(point[i].id < 0) seg[-point[i].id][0] = cnt;
        else seg[point[i].id][1] = cnt;
    }

    REP1(i, 1, n) {
        update(1, 1, cnt, seg[i][0], seg[i][1], i);
    }

    query(1, 1, cnt);
}

void Problem::update(int node, int b, int e, int f, int t, int seg_no) {
    if(b>=f && e<=t) {
        tree[node] = seg_no;
        return;
    }

    push_down(node, b, e);

    int mid = (b+e) >> 1;

    if(f<=mid) update(left, f, t, seg_no);
    if(t>mid)  update(riht, f, t, seg_no);
}

void Problem::push_down(int node, int b, int e) {
    if(tree[node] && b!=e) {
        tree[node<<1] = tree[node<<1|1] = tree[node];
        tree[node] = 0;
    }
}

void Problem::query(int node, int b, int e) {
    if(tree[node]) {
        ms.insert(tree[node]);
        return;
    }

    int mid = (b+e) >> 1;

    query(left);
    query(riht);
}

void Problem::print_ans() {
    printf("Case %d: %d\n",++test,sz(ms));
}

int main() {
    Problem Posters_for_Election;
    int t;

    RD(t);

    while(t--) {
        Posters_for_Election.init();
        Posters_for_Election.take_input();
        Posters_for_Election.process();
        Posters_for_Election.print_ans();
    }


    return 0;
}













