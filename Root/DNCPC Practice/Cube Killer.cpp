#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1e11;

#define SZ 20010

struct data{
    ll minim, maxim, range;
};

data axis[3];

struct data1{
    ll x, y, z;
};

data1 point[SZ];

ll solve(int n){
    ll range, xmin, xmax, ymin, ymax, zmin, zmax, need;
    int i, j, k, p;

    range = max(axis[0].range, max(axis[1].range, axis[2].range));

    for(i=0; i<2; i++){
        need = range - axis[0].range;
        xmin = axis[0].minim;
        xmax = axis[0].maxim;
        if(i==0) xmin -= need;
        else xmax += need;

        for(j=0; j<2; j++){
            need = range - axis[1].range;
            ymin = axis[1].minim;
            ymax = axis[1].maxim;
            if(j==0) ymin -= need;
            else ymax += need;

            for(k=0; k<2; k++){
                need = range - axis[2].range;
                zmin = axis[2].minim;
                zmax = axis[2].maxim;
                if(k==0) zmin -= need;
                else zmax += need;

                for(p=0; p<n; p++){
                    if(point[p].x==xmin || point[p].x==xmax || point[p].y==ymin || point[p].y==ymax || point[p].z==zmin || point[p].z==zmax)
                        ;
                    else
                        break;
                }

                if(p == n) return range;
            }
        }
    }

    return -1;
}

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int main(){
    #if defined JESI
//        freopen("1.txt","r",stdin);
    #endif // defined

    int test=0, t, n, i, tmp;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);

        axis[0].maxim = -inf;
        axis[1].maxim = -inf;
        axis[2].maxim = -inf;

        axis[0].minim = inf;
        axis[1].minim = inf;
        axis[2].minim = inf;


        for(i=0; i<n; i++){
//            scanf("%lld %lld %lld",&point[i].x,&point[i].y,&point[i].z);
            inp(tmp);
            point[i].x = tmp;
            inp(tmp);
            point[i].y = tmp;
            inp(tmp);
            point[i].z = tmp;

            axis[0].maxim = max(axis[0].maxim, point[i].x);
            axis[1].maxim = max(axis[1].maxim, point[i].y);
            axis[2].maxim = max(axis[2].maxim, point[i].z);

            axis[0].minim = min(axis[0].minim, point[i].x);
            axis[1].minim = min(axis[1].minim, point[i].y);
            axis[2].minim = min(axis[2].minim, point[i].z);
        }

        axis[0].range = axis[0].maxim - axis[0].minim;
        axis[1].range = axis[1].maxim - axis[1].minim;
        axis[2].range = axis[2].maxim - axis[2].minim;


        printf("Case %d: %lld\n",++test,solve(n));
    }


    return 0;
}


