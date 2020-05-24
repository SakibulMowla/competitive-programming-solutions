#include "stdio.h"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 110

struct point
{
    int x, y;
    bool operator <(const point &p) const
    {
        return y < p.y || (y == p.y && x < p.x);
    }
};

point arr[SZ], hull[SZ];

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
int cross(const point &O, const point &A, const point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.

int convex_hull(int n)
{
    int k = 0;
    // Sort points lexicographically
    sort(arr, arr+n);

    // Build lower hull
    for (int i = 0; i < n; i++)
    {
        while (k >= 2 && cross(hull[k-2], hull[k-1], arr[i]) >= 0) k--;
        hull[k++] = arr[i];
    }

    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--)
    {
        while (k >= t && cross(hull[k-2], hull[k-1], arr[i]) >= 0) k--;
        hull[k++] = arr[i];
    }

    return k;
}

bool comp(point p, point q)
{
    if(p.y == q.y)
        return p.x < q.x;
    return p.y < q.y;
}

int main()
{
    freopen("1.txt","r",stdin);
    int i, n, test;

    scanf("%d",&test);
    printf("%d\n",test);

    while(test--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
            scanf("%d %d", &arr[i].x, &arr[i].y);

        n = convex_hull(n);

        printf("%d\n",n);

//        sort(hull, hull+n-1, comp);

        for(i=0; i<n; i++)
            printf("%d %d\n", hull[i].x, hull[i].y);
//        printf("%d %d\n",hull[0].x,hull[0].y);

        if(test)
        {
            scanf("%d",&n);
            puts("-1");
        }
    }

    return 0;
}

/*
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
*/

