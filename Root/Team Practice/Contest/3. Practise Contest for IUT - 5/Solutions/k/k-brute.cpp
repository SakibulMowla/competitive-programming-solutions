// CERC 2012
// Problem K: Graphic Madness
// Slow solution, exponential in n
// [
//   1. Answer NO, if a vertex of degree 1 exists
//   2. Replace degree 2 vertices with edges that must lie on the cycle
//   3. Search for the cycle exhaustively
// ]
// Author: Bartosz Walczak

#include <cstdio>
#include <iostream>
#include <list>
#include <string>
using namespace std;

int vertex_no(const string& name, int k, int n) {
    int no;
    sscanf(name.c_str()+2, "%d", &no);
    --no;
    if (name[0] == 'B') no += n+k;
    if (name[1] == 'P') no += k;
    return no;
}

void print_vertex_name(int no, int k, int n) {
    putchar(no < n+k ? 'A' : 'B');
    if (no >= n+k) no -= n+k;
    putchar(no < k ? 'S' : 'P');
    if (no >= k) no -= k;
    printf("%d", no+1);
}

template<typename Iter>
inline Iter prev(Iter iter) { return --iter; }

struct vertex;

struct edge {
    vertex* v;
    list<edge>::iterator rev;
    vertex* sub;
    explicit edge(vertex* v) : v(v), sub(0) {}
};

struct vertex {
    int no;
    list<edge> adj;
    int degree;
    bool used;
    list<edge>::iterator prev, next;
    vertex() : degree(0), used(false) {}
};

void simplify(vertex* v) {
    const edge& e1 = v->adj.front();
    const edge& e2 = v->adj.back();
    e1.rev->v = e2.v;
    e1.rev->rev = e2.rev;
    e1.rev->sub = v;
    e2.rev->v = e1.v;
    e2.rev->rev = e1.rev;
    e2.rev->sub = v;
}

vertex* expand(vertex* u) {
    while (vertex* v = u->next->sub) {
        const edge& e1 = v->adj.front();
        const edge& e2 = v->adj.back();
        e1.rev->v = v;
        e1.rev->rev = v->adj.begin();
        e1.rev->sub = e1.sub;
        e2.rev->v = v;
        e2.rev->rev = prev(v->adj.end());
        e2.rev->sub = e2.sub;
        if (v->adj.front().v==u) {
            v->prev = v->adj.begin();
            v->next = prev(v->adj.end());
        } else {
            v->prev = prev(v->adj.end());
            v->next = v->adj.begin();
        }
    }
    return u->next->v;
}

bool search(vertex* v, vertex* prev, vertex* start, int length) {
    if (!length) return v==start;
    if (v->used) return false;
    list<edge>::iterator forced;
    int forced_cnt = 0;
    for (list<edge>::iterator it = v->adj.begin(); it != v->adj.end(); ++it)
      if (it->v != prev && it->sub) {
        forced = it;
        ++forced_cnt;
    }
    if (forced_cnt > 2 || prev && forced_cnt > 1) return false;
    v->used = true;
    if (forced_cnt) {
        if (search(forced->v, v, start, length-1)) {
            v->next = forced;
            forced->v->prev = forced->rev;
            return true;
        }
        v->used = false;
        return false;
    }
    for (list<edge>::iterator it = v->adj.begin(); it != v->adj.end(); ++it)
      if (it->v != prev && search(it->v, v, start, length-1)) {
        v->next = it;
        it->v->prev = it->rev;
        return true;
    }
    v->used = false;
    return false;
}

void testcase() {
    int k, n, m;
    cin >> k >> n >> m;
    int vertices = n+m+2*k;
    vertex* G = new vertex[vertices];
    for (int i=0; i<vertices; ++i) G[i].no = i;
    for (int edges = n+m+3*k-2; edges; --edges) {
        string a_name, b_name;
        cin >> a_name >> b_name;
        int a = vertex_no(a_name, k, n), b = vertex_no(b_name, k, n);
        G[a].adj.push_back(edge(&G[b]));
        G[b].adj.push_back(edge(&G[a]));
        G[a].adj.back().rev = prev(G[b].adj.end());
        G[b].adj.back().rev = prev(G[a].adj.end());
        ++G[a].degree;
        ++G[b].degree;
    }
    for (int i=0; i<vertices; ++i) if (G[i].degree==1) {
        printf("NO\n");
        return;
    }
    int length = vertices;
    vertex* start;
    for (int i=0; i<vertices; ++i) {
        if (length>3 && G[i].degree==2) {
            simplify(&G[i]);
            --length;
        } else start = &G[i];
    }
    if (!search(start, 0, start, length)) {
        printf("NO\n");
        return;
    }
    printf("YES");
    vertex* cur = start;
    do {
        putchar(' ');
        print_vertex_name(cur-G, k, n);
        cur = expand(cur);
    } while (cur != start);
    putchar('\n');
    delete[] G;
}

int main() {
    int t; cin >> t;
    for (; t; --t) testcase();
}
