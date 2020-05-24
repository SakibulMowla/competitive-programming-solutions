#include "stdio.h"
#include "string.h"
#include "vector"
#include "queue"
#include "iostream"
#include "algorithm"
using namespace std;
#define SZ 110

typedef long long ll;
const ll inf = (1LL<<28);
ll T[SZ] , dist[SZ] , n;

struct vertex
{
    ll node,dist,lift;
    bool operator < (const vertex &x) const
    {
        return dist > x.dist;
    }
};

vector <vertex> input[SZ];
priority_queue <vertex> Q;

void dijkstra()
{
    ll i,j,k,l,c,no;
    for(i=0; i<=100LL; i++) dist[i] = inf;

    while(!Q.empty()) Q.pop();
    vertex u,v;
    dist[0] = 0;
    u.dist = 0 , u.lift = -1 , u.node = 0;
    Q.push(u);

    while(!Q.empty())
    {
        u = Q.top() , Q.pop();
        no = u.node , l = u.lift , c = u.dist;
        k = input[no].size();
        for(i=0; i<k; i++)
        {
            j = c + input[no][i].dist;
            if(l != -1 && (l != input[no][i].lift)) j += 60LL;
            if(dist[input[no][i].node] > j)
            {
                dist[input[no][i].node] = j;
                v.dist = j;
                v.lift  = input[no][i].lift;
                v.node = input[no][i].node;
                Q.push(v);
//                printf("from--> n = %lld l = %lld c = %lld --to--> n = %lld l = %lld c = %lld\n",no,l,c,v.node,v.lift,v.dist);
//                printf("c = %lld input = %lld\n",c,input[no][i].dist);
            }
        }
    }
//    for(i=0;i<=100LL;i++) printf("dist[%lld] = %lld\n",i,dist[i]);
}

int main()
{
//    freopen("1.txt","r",stdin);
    ll i,j,k,p,q;
    ll num[SZ];
    vertex var;
    char arr[1000],*str;
    while(scanf("%lld %lld",&n,&k) == 2)
    {
        for(i=0;i<=100;i++) input[i].clear();
        for(i=0; i<n; i++) scanf("%lld",&T[i]);
        for(i=0; i<n; i++)
        {
            scanf(" %[^\n]",arr);
            j = 0;
            str = strtok(arr," ");
            while(str)
            {
                num[j++] = atol(str);
//                printf("num %lld = %lld\n",j-1,num[j-1]);
                str = strtok(NULL," ");
            }
            for(p=0; p<j; p++)
                for(q=0; q<j; q++)
                {
                    if(p == q) continue;
                    var.node = num[q];
                    var.dist = T[i] * abs(num[q] - num[p]);
                    var.lift = i;
                    input[num[p]].push_back(var);
//                    printf("%lld %lld %lld\n",num[p],var.node,var.dist);
                }
        }
        dijkstra();
        if(dist[k] >= inf) printf("IMPOSSIBLE\n");
        else printf("%lld\n",dist[k]);
    }

    return 0;
}
