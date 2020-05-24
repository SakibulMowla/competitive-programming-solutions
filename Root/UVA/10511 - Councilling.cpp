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
#include <assert.h>

using namespace std;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

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


#define SZ  10010

vector <int> partyToMember[SZ];
vector <int> memberToClub[SZ];

map <string , int> mpParty;
map <string , int> mpMember;
map <string , int> mpClub;

string revParty[SZ];
string revMember[SZ];
string revClub[SZ];

void process(char arr[])
{
    char *s;
    int cnt = 0, member, party, club;

    s = strtok(arr, " ");
    while(s != NULL)
    {
        if(cnt == 0)
        {
            if(mpMember.find(s) == mpMember.end())
            {
                revMember[ sz(mpMember) ] = s;
                memberToClub[ sz(mpMember) ].clear();
                mpMember[ s ] = sz(mpMember)-1;
            }
            member = mpMember[s];
        }
        else if(cnt == 1)
        {
            if(mpParty.find(s) == mpParty.end())
            {
                revParty[ sz(mpParty) ] = s;
                partyToMember[ sz(mpParty) ].clear();
                mpParty[ s ] = sz(mpParty)-1;
            }
            party = mpParty[s];
            partyToMember[party].pb(member);
        }
        else
        {
            if(mpClub.find(s) == mpClub.end())
            {
                revClub[ sz(mpClub) ] = s;
                mpClub[ s ] = sz(mpClub)-1;
            }
            club = mpClub[s];
            memberToClub[member].pb(club);
        }

        s = strtok(NULL, " ");
        cnt++;
    }
    return;
}

/// Node 0 is Source and 1 is Sink
void giveConnection(Dinic &din)
{
    /// Giving Connection From Source to Party
    int cap = sz(mpClub);
    cap = cap/2 - (cap%2 == 0);

    for(int i = 0; i < sz(mpParty); i++)
    {
        din.AddEdge(0, 2+i, cap);
    }
    /// Giving Connection From Party to Member
    for(int i = 0; i < sz(mpParty); i++)
    {
        for(int j = 0; j < sz(partyToMember[i]); j++)
        {
            din.AddEdge(2+mpParty[revParty[i]], partyToMember[i][j] + 2 + sz(mpParty), 1);
        }
    }
    /// Giving Connection From Member to Club
    for(int i = 0; i < sz(mpMember); i++)
    {
        for(int j = 0; j < sz(memberToClub[i]); j++)
        {
            din.AddEdge(2+sz(mpParty)+mpMember[revMember[i]], memberToClub[i][j]+2+sz(mpParty)+sz(mpMember), 1);
        }
    }
    /// Giving Connection From Club to Sink
    for(int i = 0; i < sz(mpClub); i++)
    {
        din.AddEdge(2+sz(mpParty)+sz(mpMember)+mpClub[revClub[i]], 1, 1);
    }
    return;
}

int main() {
//    freopen("1.txt", "r", stdin);
    char arr[SZ];

    int test;

    scanf("%d", &test);
    getchar();
    getchar();

    while(test--)
    {
        clr(mpParty);
        clr(mpMember);
        clr(mpClub);

        while(gets(arr))
        {
            if(arr[0] == '\0') break;
            process(arr);
        }

        Dinic din(2 + sz(mpParty) + sz(mpMember) + sz(mpClub));
        giveConnection(din);

        if((int)din.GetMaxFlow(0, 1) != sz(mpClub)) printf("Impossible.\n");
        else
        {
            for(int i = 0; i < sz(din.G); i++)
            {
                for(int j = 0; j < sz(din.G[i]); j++)
                {
                    if(din.G[i][j].flow && din.G[i][j].from >= 2+sz(mpParty) && din.G[i][j].from < 2+sz(mpParty)+sz(mpMember) && din.G[i][j].to >= 2+sz(mpParty)+sz(mpMember))
                    {
                        int to = din.G[i][j].to - 2 - sz(mpParty) - sz(mpMember);
                        int from = din.G[i][j].from - 2 - sz(mpParty);
                        printf("%s %s\n", revMember[from].c_str(), revClub[to].c_str());
                    }
                }
            }
        }

        if(test) printf("\n");
    }

    return 0;
}





