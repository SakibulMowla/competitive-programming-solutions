#include <stdio.h>
#include <string.h>

#define SZ 110

int r, c, cnt;
char arr[SZ][SZ];

int x[] = {0,0,-1,1};
int y[] = {-1,1,0,0};

void DFS(int n,int m)
{
    arr[n][m] = '1';
    cnt++;

    int u, v, i;

    for(i=0;i<4;i++)
    {
        u = n + x[i];
        v = m + y[i];
        if(u >= 0 && v >= 0 && u < r && v < c && arr[u][v] == '0')
            DFS(u, v);
    }

    return;
}

int main()
{
    int t, n, m, blank=0;

    scanf("%d", &t);

    while(t--)
    {
        if(blank) printf("\n");
        else blank = 1;
        scanf("%d %d", &n, &m);
        getchar();

        r=0;
        while( gets(arr[r]) )
        {
            if(strlen(arr[r]) == 0) break;
            r++;
        }

        c = strlen(arr[0]);
        --n, --m;
        cnt = 0;
        DFS(n,m);

        printf("%d\n", cnt);
    }

    return 0;
}
