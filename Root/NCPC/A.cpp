const int MAXN = 505; // number of elements.
int n; //n no. of vertices.
vector<int> g[MAXN];
int match[MAXN]; //stores the matcings
int p[MAXN]; //array of ancestors.
int base[MAXN]; //Node numbering after compression.
int q[MAXN]; //Queue
bool used[MAXN], blossm[MAXN];
int lca (int a, int b) {
    bool used[MAXN] = { 0 };
// From the node a climb up to the roots,
//marking all even vertices
    for (;;) {
        a = base[a];
        used[a] = true;
        if (match[a] == -1) break; // Got the root
        a = p[match[a]];
    }
// Climb from node b,
//until we find the marked vertex
    for (;;) {
        b = base[b];
        if (used[b]) return b;
        b = p[match[b]];
    }
}
void mark_path (int v, int b, int children) {
    while (base[v] != b) {
        blossm[base[v]]=blossm[base[match[v]]]=true;
        p[v] = children;
        children = match[v];
        v = p[match[v]];
    }
}
int find_path (int root) {
    Clear(used,0);
    Clear(p,-1);
    for (int i=0; i<n; ++i)
        base[i] = i;
    used[root] = true;
    int qh=0, qt=0;
    q[qt++] = root;
    while (qh < qt) {
        int v = q[qh++];
        for (int i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (base[v] == base[to]
                    || match[v] == to) continue;
            if (to == root || match[to] != -1
                    && p[match[to]] != -1) {
                int curbase = lca (v, to);
                Clear(blossm,0);
                mark_path (v, curbase, to);
                mark_path (to, curbase, v);
                for (int i=0; i<n; ++i)
                    if (blossm[base[i]]) {
                        base[i] = curbase;
                        if (!used[i]) {
                            used[i] = true;
                            q[qt++] = i;
                        }
                    }
            } else if (p[to] == -1) {
                p[to] = v;
                if (match[to] == -1) return to;
                to = match[to];
                used[to] = true;
                q[qt++] = to;
            }
        }
    }
    return -1;
}
int graph_match() {
    int ret = 0;
    Clear(match,-1);
    for (int i=0; i<n; ++i)
        if (match[i] == -1) {
            int v = find_path (i);
            if(v!=-1) ret++;
            while (v != -1) {
                int pv = p[v], ppv = match[pv];
                match[v] = pv, match[pv] = v;
                v = ppv;
            }
        }
    return ret;
}
int main() {
    scanf("%d",&n);
    while(scanf("%d %d",&i,&j)==2) {
        i--,j--;
        g[i].pb(j);
        g[j].pb(i);
    }
    int ans = graph_match();
    printf("%d\n",ans*2);
    for(i=0; i<n; i++)
        if(match[i]>-1) {
            printf("%d %d\n",i+1,match[i]+1);
            match[match[i]] = -1;
        }
    return 0;
}
