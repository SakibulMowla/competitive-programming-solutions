// Adjacency list implementation of Dinic's blocking flow algorithm.
// This is very fast in practice, and only loses to push-relabel flow.
//
// Running time:
//     O(|V|^2 |E|)
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual flow values, look at all edges with
//       capacity > 0 (zero capacity edges are residual edges).

#include <cmath>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int INF = 2000000000;

struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t)
    {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail)
        {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if (!e)
                {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t)
    {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

int mp[300];
char rev_mp[300];

int colorIt(int &source, int &sink)
{
    int cnt = 0;
    for(int i = 'A'; i <= 'Z'; i++)
    {
        mp[i] = cnt++;
        rev_mp[cnt-1] = (char)i;
    }
    for(int i = '0'; i <= '9'; i++)
    {
        mp[i] = cnt++;
        rev_mp[cnt-1] = (char)i;
    }
    source = cnt++;
    rev_mp[cnt-1] = '&';
    sink = cnt++;
    rev_mp[cnt-1] = '*';

    return cnt;
}

int mark[10];

void process(char arr[], Dinic &din, int &source, int &sink, int &need)
{
    char job[5], machine[110];
    sscanf(arr, "%s %s", job, machine);

    need += job[1]-'0';

    din.AddEdge(source, mp[job[0]], job[1]-'0'); /// edge from source to process

    for(int i = 0; ; i++)
    {
        if(machine[i] == ';')
            break;
        din.AddEdge(mp[job[0]], mp[machine[i]], 1);  /// edge from process to computer
        mark[ machine[i]-'0' ] = 1;
    }

    return;
}

int main()
{
//    freopen("1.txt", "r", stdin);

    int source, sink;
    int node = colorIt(source, sink);

    char arr[1010];
    while(gets(arr))
    {
        if(arr[0] == '\0') break;

        Dinic din(node);

        int need = 0;

        process(arr, din, source, sink, need);
        while(gets(arr))
        {
            if(arr[0] == '\0') break;
            process(arr, din, source, sink, need);
        }

        /// edge from each computer to sink
        for(int i = 0; i < 10; i++)
            if(mark[i])
                din.AddEdge(mp[ i+'0' ], sink, 1);

        int ans = din.GetMaxFlow(source, sink);
        if(ans < need) printf("!\n");
        else
        {
            char ans[11];
            for(int i = 0; i < 10; i++) ans[i] = '_';
            ans[10] = '\0';

            for(int i = 0; i < din.G.size(); i++)
            {
                for(int j = 0; j < din.G[i].size(); j++)
                {
                    if(din.G[i][j].flow)
                    {
                        if(rev_mp[ din.G[i][j].to ] >= '0' && rev_mp[ din.G[i][j].to ] <= '9')
                        {
                            if(rev_mp[ din.G[i][j].from ] >= 'A' && rev_mp[ din.G[i][j].from ] <= 'Z')
                            {
                                ans[ rev_mp[ din.G[i][j].to ]-'0' ] = rev_mp[ din.G[i][j].from ];
                            }
                        }
                    }
                }
            }

            printf("%s\n", ans);
        }
    }


    return 0;
}

