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

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;

  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
	Edge &e = G[x][i];
	if (!dad[e.to] && e.cap - e.flow > 0) {
	  dad[e.to] = &G[x][i];
	  Q[tail++] = e.to;
	}
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	if (!e) { amt = 0; break; }
	amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	e->flow += amt;
	G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};



int main()
{
//    freopen("1.txt", "r", stdin);
    int category, problem;

    /// Node 0 is source and 1 is sink
    while(scanf("%d %d", &category, &problem) == 2 && (category + problem))
    {
        Dinic din(category+problem+2);

        int total = 0;
        for(int i = 0; i < category; i++)
        {
            int cap;
            scanf("%d", &cap);
            din.AddEdge(0, i+2, cap); /// Edge from source to category
            total += cap;
        }

        for(int i = 0; i < problem; i++)
        {
            int qty;
            scanf("%d", &qty);
            for(int j = 0; j < qty; j++)
            {
                int _category;
                scanf("%d", &_category);
                --_category;
                din.AddEdge(_category+2, i+2+category, 1); /// Edge from category to problem
            }
        }

        for(int i = 0; i < problem; i++)
        {
            din.AddEdge(i+2+category, 1, 1); /// Edge from problem to sink
        }

//        printf(" %lld %d\n", din.GetMaxFlow(0, 1), total);

        if((int)din.GetMaxFlow(0, 1) != (int)total) puts("0");
        else
        {
            puts("1");
            vector <int> ans[problem];

            for(int i = 0; i < din.G.size(); i++)
            {
                for(int j = 0; j < din.G[i].size(); j++)
                {
                    if(din.G[i][j].flow && din.G[i][j].from >= 2 && din.G[i][j].from < 2+category && din.G[i][j].to >= 2+category)
                    {
                        ans[ din.G[i][j].from-2 ].push_back(din.G[i][j].to-2-category);
                    }
                }
            }

            for(int i = 0; i < category; i++)
            {
                for(int j = 0; j < ans[i].size(); j++)
                {
                    if(j) printf(" ");
                    printf("%d", ans[i][j]+1);
                }
                printf("\n");
            }
        }
    }

    return 0;
}





