// CERC 2012
// Problem I: The Dragon and the knights
// Slow solution (compare every pair of points against every line), O(nm^2)
// Author: Grzegorz Herman

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

struct point { long long x, y; };
struct line { long long a, b, c; };

inline long long operator*(line const & l, point const & p)
{
    return l.a*p.x + l.b*p.y + l.c;
}

inline bool operator<(line const & l1, line const & l2)
{
    return l1.a*l2.b < l2.a*l1.b;
}

typedef pair<unsigned long long, unsigned long long> code;

void set(code & c, int i)
{
    if (i<64) c.first += (1ULL << i);
    else c.second += (1ULL << (i-64));
}

#define debug(...) fprintf(stderr, __VA_ARGS__)

int main()
{
    int nT;
    scanf("%d", &nT);
    for (int t=0; t<nT; ++t)
    {
        // read input
        int nL, nP;
        scanf("%d%d", &nL, &nP);
        line L[nL];
        for (int l=0; l<nL; ++l)
        {
            scanf("%Ld%Ld%Ld", &L[l].a, &L[l].b, &L[l].c);
            if ((L[l].a<0) || ((L[l].a==0) && (L[l].b<0)))
            { L[l].a *= -1; L[l].b *= -1; L[l].c *= -1; }
        }
        // calculate guarded regions
        point P[nP];
        for (int p=0; p<nP; ++p)
            scanf("%Ld%Ld", &P[p].x, &P[p].y);
        int guarded = 0;
        for (int p=0; p<nP; ++p)
        {
            bool fresh = true;
            for (int q=0; q<p; ++q)
            {
                bool dif = false;
                for (int l=0; l<nL; ++l)
                    if ((L[l]*P[p] > 0) ^ (L[l]*P[q] > 0))
                    {
                        dif = true;
                        break;
                    }
                if (!dif)
                {
                    fresh = false;
                    break;
                }
            }
            if (fresh)
                guarded++;
        }
        // calculate total regions
        sort(L, L+nL);
        int total = 2;
        int added = 0;
        for (int l=1; l<nL; ++l)
        {
            if (L[l-1] < L[l])
                added = l;
            total += added + 1;
        }
        // output the answer
        debug("case %d: guarded = %d, total = %d\n", t+1, guarded, total);
        assert(guarded <= total);
        printf(guarded == total ? "PROTECTED\n" : "VULNERABLE\n");
    }
}
