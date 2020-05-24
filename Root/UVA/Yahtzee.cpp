#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;

struct data
{
    int p, q, x, y, z;
};

data arr[15];
int bcnt;
vector <int> tmp, best;

int equal(int i)
{

}

int cal(int op,int i)
{
    int ret = 0, same = 0;
    if(op == 1)
    {
        if(arr[i].p == 1) same++;
        if(arr[i].q == 1) same++;
        if(arr[i].x == 1) same++;
        if(arr[i].y == 1) same++;
        if(arr[i].z == 1) same++;
        ret = 1 * same;
    }
    else if(op == 2)
    {
        if(arr[i].p == 2) same++;
        if(arr[i].q == 2) same++;
        if(arr[i].x == 2) same++;
        if(arr[i].y == 2) same++;
        if(arr[i].z == 2) same++;
        ret = 2 * same;
    }
    else if(op == 3)
    {
        if(arr[i].p == 3) same++;
        if(arr[i].q == 3) same++;
        if(arr[i].x == 3) same++;
        if(arr[i].y == 3) same++;
        if(arr[i].z == 3) same++;
        ret = 3 * same;
    }
    else if(op == 4)
    {
        if(arr[i].p == 4) same++;
        if(arr[i].q == 4) same++;
        if(arr[i].x == 4) same++;
        if(arr[i].y == 4) same++;
        if(arr[i].z == 4) same++;
        ret = 4 * same;
    }
    else if(op == 5)
    {
        if(arr[i].p == 5) same++;
        if(arr[i].q == 5) same++;
        if(arr[i].x == 5) same++;
        if(arr[i].y == 5) same++;
        if(arr[i].z == 5) same++;
        ret = 5 * same;
    }
    else if(op == 6)
    {
        if(arr[i].p == 6) same++;
        if(arr[i].q == 6) same++;
        if(arr[i].x == 6) same++;
        if(arr[i].y == 6) same++;
        if(arr[i].z == 6) same++;
        ret = 6 * same;
    }
    else if(op == 7)
    {
        ret = arr[i].p + arr[i].q + arr[i].x + arr[i].y + arr[i].z;
    }
    else if(op == 8)
    {

    }
    else if(op == 9)
    {

    }
    else if(op == 10)
    {

    }
    else if(op == 11)
    {

    }
    else if(op == 12)
    {

    }
    else if(op == 13)
    {

    }
    return ret;
}

void solve(int indx,int mask,int six)
{
    if(indx == 13)
    {
        int i, sum;
        sum = 0;
        for(i=0;i<13;i++)   sum += tmp[i];
        if(six >= 63)   sum += 35;
        if(sum > bcnt)
        {
            bcnt = sum;
            best.clear();
            for(i=0;i<13;i++)   best.push_back(tmp[i]);
            if(six >= 63)   best.push_back(35);
            else    best.push_back(0);
            best.push_back(sum);
        }
        return;
    }

    int i, j, t, s;

    for(i=0;i<13;i++)
    {
        if((mask & (1<<i)) == 0)
        {
            j = cal(indx+1, i);
            t = mask | (1<<i);
            s = 0;
            if(indx < 6)    s = j;
            tmp.push_back(j);
            solve(indx+1, t, six + s);
            tmp.pop_back();
        }
    }
}

int main()
{
    int i;
    while(scanf("%d %d %d %d %d",&arr[0].p,&arr[0].q,&arr[0].x,&arr[0].y,&arr[0].z) == 5)
    {
        for(i=1;i<13;i++)
            scanf("%d %d %d %d %d",&arr[i].p,&arr[i].q,&arr[i].x,&arr[i].y,&arr[i].z);
        bcnt = 0;
        solve(0, 0, 0);
        printf("%d",best[0]);
        for(i=1;i<15;i++)
            printf(" %d",best[i]);
        printf("\n");
    }

    return 0;
}
