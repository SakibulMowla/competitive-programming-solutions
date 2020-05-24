#include "bits/stdc++.h"
using namespace std;

#define SZ 27

bool avoid[SZ][SZ][SZ];
int dist[SZ][SZ][SZ];

queue <int> Q;

int bfs(int s1, int s2, int s3, int e1, int e2, int e3)
{
    while(!Q.empty()) Q.pop();

    int i, j, k, p, q, r, u, v, w;
    int num[5], num1[5];

    dist[s1][s2][s3] = 0;
    Q.push(s1);
    Q.push(s2);
    Q.push(s3);

    while(!Q.empty())
    {
        num[0] = Q.front();
        Q.pop();
        num[1] = Q.front();
        Q.pop();
        num[2] = Q.front();
        Q.pop();

        if(num[0] == e1 && num[1] == e2 && num[2] == e3)
            return dist[num[0]][num[1]][num[2]];

        for(i=0;i<3;i++)
        {
            num1[0] = num[0], num1[1] = num[1], num1[2] = num[2];
            num1[i] = (num[i] + 1) % 26;
            if(dist[num1[0]][num1[1]][num1[2]] == -1 && !avoid[num1[0]][num1[1]][num1[2]])
            {
                dist[num1[0]][num1[1]][num1[2]] = dist[num[0]][num[1]][num[2]] + 1;
                Q.push(num1[0]);
                Q.push(num1[1]);
                Q.push(num1[2]);
            }

            num1[0] = num[0], num1[1] = num[1], num1[2] = num[2];
            num1[i] = (num[i] - 1 + 26) % 26;
            if(dist[num1[0]][num1[1]][num1[2]] == -1 && !avoid[num1[0]][num1[1]][num1[2]])
            {
                dist[num1[0]][num1[1]][num1[2]] = dist[num[0]][num[1]][num[2]] + 1;
                Q.push(num1[0]);
                Q.push(num1[1]);
                Q.push(num1[2]);
            }
        }
    }

    return dist[e1][e2][e3];
}

int main()
{
    char arr1[SZ], arr2[SZ], arr3[SZ], start[5], end[5];
    int test = 0, t, i, j, k, l;

    scanf("%d",&t);

    while(t--)
    {
        scanf(" %s %s",start,end);
        scanf("%d",&l);

        memset(avoid, 0, sizeof(avoid));

        while(l--)
        {
            scanf(" %s %s %s",arr1,arr2,arr3);
            for(i=0; arr1[i]; i++)
                for(j=0; arr2[j]; j++)
                    for(k=0; arr3[k]; k++)
                        avoid[arr1[i]-'a'][arr2[j]-'a'][arr3[k]-'a'] = 1;
        }

        printf("Case %d: ",++test);

        if(avoid[start[0]-'a'][start[1]-'a'][start[2]-'a'] || avoid[end[0]-'a'][end[1]-'a'][end[2]-'a'])
        {
            printf("-1\n");
            continue;
        }

        memset(dist, -1, sizeof(dist));

        printf("%d\n",bfs(start[0]-'a',start[1]-'a',start[2]-'a',end[0]-'a',end[1]-'a',end[2]-'a'));
    }

    return 0;
}
