#include <bits/stdc++.h>

using namespace  std;

const int SZ  = (1<<12)+10;
const int SZ1 = 66;

int dp[SZ][SZ1];
int cool[SZ][SZ1];
int mp[200];
int four[10];
char tile[15][5];
int now_col;

void init(){
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    mp['Y'] = 3;

    int i;

    four[0] = 1;
    for(i=1;i<=5;i++) four[i] = 4 * four[i-1];
}

int check(int mask, int pos){
    return (mask/four[pos]) % 4;
}

int Set(int mask, int pos, int val){
    int bit = (mask/four[pos]) % 4;
    mask -= bit * four[pos];
    mask += val * four[pos];
    return mask;
}

int solve(int main_mask, int up_mask);

int gen(int main_mask, int up_mask, int down_mask, int left_side, int column){
    if(column == 3)
        return solve(main_mask, down_mask);

    int i, ret = 0;

    for(i=0;i<12;i++)
        if((main_mask&(1<<i)) && (left_side == - 1 || left_side == mp[tile[i][3]]) && (up_mask == 65 || check(up_mask, column) == mp[tile[i][0]]))
            ret += gen(main_mask&~(1<<i), up_mask, Set(down_mask, column, mp[tile[i][2]]), mp[tile[i][1]], column+1);

    return ret;
}

int solve(int main_mask, int up_mask){
    if(!main_mask) return 1;

    int &ret = dp[main_mask][up_mask];
    int &col = cool[main_mask][up_mask];

    if(col == now_col) return ret;
    col = now_col;

    ret = gen(main_mask, up_mask, 0, -1, 0);
    return ret;
}

int main() {
    init();
    now_col = 0;

    int test=0, t, i;

    scanf("%d",&t);

    while(t--){
        for(i=0;i<12;i++) scanf("%s",tile[i]);
        now_col++;
        printf("Case %d: %d\n",++test,solve((1<<12)-1, 65));
    }


    return 0;
}



/*
    RRBR RRBR RRBR BBBB BBBB BBBB BBBB BBBB BBBB BBBB BBBB BBBB
    Ans = 2177280
    BRBR BRBR BRBR BBBB BBBB BBBB BBBB BBBB BBBB BBBB BBBB BBBB
    ANS = 8709120
*/






