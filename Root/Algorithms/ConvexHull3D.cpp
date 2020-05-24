#include <bits/stdc++.h>

using namespace std;

#define EPS 1E-8
#define N 110

struct PT {
    double x, y, z;
    PT() {}
    PT(double _x, double _y, double _z):x(_x), y(_y), z(_z) {}
    PT operator - (const PT p) {
        return PT(x-p.x, y-p.y, z-p.z);
    }
    PT operator * (const PT p) {
        return PT(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);
    }
    double operator ^ (const PT p) {
        return x*p.x + y*p.y + z*p.z;
    }
};

struct face {
    int a, b, c;
    bool ok;
};

struct ConHull3D {
    int n; //this variable n must be initialized manually
    int trianglecnt;
    PT point[N];
    int vis[N][N];
    face tri[8*N];

    double dist (PT a) {
        return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
    }

    double area (PT a, PT b, PT c) {
        return dist((b-a)*(c-a));
    }

    double volume (PT a, PT b, PT c, PT d) {
        return (b-a)*(c-a)^(d-a);
    }

    double ptoplane (PT &p, face &f) {
        PT m = point[f.b] - point[f.a], n = point[f.c]-point[f.a], t = p-point[f.a];
        return (m*n)^t;
    }

    void deal (int p, int a, int b) {
        int f = vis[a][b];
        face add;
        if (tri[f].ok) {
            if((ptoplane(point[p], tri[f])) > EPS)
                dfs(p, f);
            else {
                add.a = b, add.b = a, add.c = p, add.ok = 1;
                vis[p][b] = vis[a][p] = vis[b][a] = trianglecnt;
                tri[trianglecnt++] = add;
            }
        }
    }

    void dfs (int p, int cnt) {
        tri[cnt].ok = 0;
        deal(p, tri[cnt].b, tri[cnt].a);
        deal(p, tri[cnt].c, tri[cnt].b);
        deal(p, tri[cnt].a, tri[cnt].c);
    }

    bool same (int s, int e) {
        PT a = point[tri[s].a], b = point[tri[s].b], c = point[tri[s].c];
        return fabs(volume(a,b,c,point[tri[e].a])) < EPS
               && fabs(volume(a,b,c,point[tri[e].b])) < EPS
               && fabs(volume(a,b,c,point[tri[e].c])) < EPS;
    }

    void construct () {
        int i, j;
        trianglecnt = 0;
        if (n < 4) return;
        bool tmp = true;
        for(i = 1; i < n; i++) {
            if((dist(point[0]-point[i])) > EPS) {
                swap(point[1], point[i]);
                tmp = false;
                break;
            }
        }
        if (tmp) return;
        tmp = true;
        for(i = 2; i < n; i++) {
            if((dist((point[0]-point[1])*(point[1]-point[i]))) > EPS) {
                swap(point[2], point[i]);
                tmp = false;
                break;
            }
        }
        if(tmp) return;
        tmp = true;
        for(i = 3; i < n; i++) {
            if(fabs((point[0]-point[1])*(point[1]-point[2])^(point[0]-point[i])) > EPS) {
                swap(point[3], point[i]);
                tmp =false;
                break;
            }
        }
        if(tmp) return;
        face add;
        for(i = 0; i < 4; i++) {
            add.a = (i+1)%4, add.b = (i+2)%4, add.c = (i+3)%4, add.ok = 1;
            if((ptoplane(point[i], add))>0)
                swap(add.b, add.c);
            vis[add.a][add.b] = vis[add.b][add.c] = vis[add.c][add.a] = trianglecnt;
            tri[trianglecnt++] = add;
        }
        for(i = 4; i < n; i++) {
            for(j = 0; j < trianglecnt; j++) {
                if(tri[j].ok && (ptoplane(point[i], tri[j])) > EPS) {
                    dfs(i, j);
                    break;
                }
            }
        }
        int cnt = trianglecnt;
        trianglecnt = 0;
        for(i = 0; i < cnt; i++) {
            if(tri[i].ok)
                tri[trianglecnt++] = tri[i];
        }
    }

    double area () {
        double ret = 0;
        for(int i = 0; i < trianglecnt; i++)
            ret += area(point[tri[i].a], point[tri[i].b], point[tri[i].c]);
        return ret/2.0;
    }

    double volume () {
        PT p(0,0,0);
        double ret = 0;
        for(int i = 0; i < trianglecnt; i++)
            ret += volume(p, point[tri[i].a], point[tri[i].b], point[tri[i].c]);
        return fabs(ret/6);
    }
};

int main() {
    int cs = 1, n;
    while(scanf("%d",&n) == 1 && n) {
        ConHull3D obj;
        obj.n = n;
        for(int i = 0; i < n; i++)
            scanf("%lf %lf %lf",&obj.point[i].x, &obj.point[i].y, &obj.point[i].z);
        obj.construct();
        printf("Case %d: %.2lf\n", cs++, obj.area());
    }
    return 0;
}
