#include <bits/stdc++.h>

using namespace  std;


void PR(int x) {printf("%d\n",x);}


#define clr(a) (a.clear())
#define mem(a,b) memset(a, b, sizeof(a))
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define pb push_back

#define SZ 1010

int mat[SZ][SZ];

vector <int> lvl[32];
int tmp[32];

int main() {
#if defined JESI
    //  freopen("1.txt", "r", stdin);
    //  freopen("2.txt", "w", stdout);
#endif

    int i, j, k, n, m, rem, dim, f;

    while(scanf("%d",&rem) == 1) {
        mem(mat, 0);
        n = 2;
        f = 0;

        for(i=29; i>=1; i--) {

            if(rem&(1<<i)) {
                if(f == 0) {
                    f = 1;
                    dim = i;

                    for(j=1; j<=dim; j++) {
                        clr(lvl[j]);
                        lvl[j].pb(++n);
                        lvl[j].pb(++n);
                    }

                    for(j=1; j<=dim-1; j++) {
                        mat[ lvl[j][0] ][lvl[j+1][0]] = mat[ lvl[j+1][0] ][lvl[j][0]] = 1;
                    }

                    for(j=1; j<=i; j++) {
                        if(j==1) {
                            mat[1][ lvl[j][0] ] = mat[ lvl[j][0] ][1] = 1;
                            mat[1][ lvl[j][1] ] = mat[ lvl[j][1] ][1] = 1;
                        } else {
                            mat[lvl[j-1][0]][ lvl[j][0] ] = mat[ lvl[j][0] ][lvl[j-1][0]] = 1;
                            mat[lvl[j-1][0]][ lvl[j][1] ] = mat[ lvl[j][1] ][lvl[j-1][0]] = 1;
                            mat[lvl[j-1][1]][ lvl[j][0] ] = mat[ lvl[j][0] ][lvl[j-1][1]] = 1;
                            mat[lvl[j-1][1]][ lvl[j][1] ] = mat[ lvl[j][1] ][lvl[j-1][1]] = 1;
                        }

                        if(j!=dim) mat[ lvl[j][0] ][ lvl[j+1][0] ] = mat[ lvl[j+1][0] ][ lvl[j][0] ] = 1;
                        if(j!=dim) mat[ lvl[j][1] ][ lvl[j+1][0] ] = mat[ lvl[j+1][0] ][ lvl[j][1] ] = 1;
                    }

                    mat[ lvl[dim][0] ][2] = mat[2][ lvl[dim][0] ] = 1;
                    if(i==dim)  mat[ lvl[dim][1] ][2] = mat[2][ lvl[dim][1] ] = 1;
                } else {
                    for(j=1;j<=i;j++);
                    k = 0;
                    for(;j<=dim;j++){
                        tmp[++k] = ++n;
                        if(k != 1) mat[tmp[k]][tmp[k-1]] = mat[tmp[k-1]][tmp[k]] = 1;
                    }
                    mat[ tmp[k] ][2] = mat[2][ tmp[k] ] = 1;
                    mat[tmp[1]][ lvl[i][0] ] = mat[ lvl[i][0] ][tmp[1]] = 1;
                    mat[tmp[1]][ lvl[i][1] ] = mat[ lvl[i][1] ][tmp[1]] = 1;
                }
            }
        }

        if(f == 0)
            dim = 1;

        if(rem&(1<<0) == 1) {
            for(j=1; j<=dim; j++) {
                clr(lvl[j]);
                lvl[j].pb(++n);
            }
            for(j=1; j<=dim-1; j++) {
                mat[ lvl[j][0] ][lvl[j+1][0]] = 1;
                mat[ lvl[j+1][0] ][lvl[j][0]] = 1;
            }
            mat[1][lvl[1][0]] = mat[lvl[1][0]][1] = 1;
            mat[2][lvl[dim][0]] = mat[lvl[dim][0]][2] = 1;
        }

        PR(n);
//        REP1(i, 1, n) {
//            REP1(j, 1, n) {
//                if(mat[i][j]) printf("Y");
//                else printf("N");
//            }
//            puts("");
//        }
    }


    return 0;
}




