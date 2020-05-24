#include "bits/stdc++.h"
#define SZ 520
using namespace std;

int board[12], row[12], col[12];
char arr[12];
int grid[10][4][4];
bool found;

int which_board(int n) {
    int b = n/9;
    if(n%9 >=0 && n%9 <= 2) return b+1;
    else if(n%9 >=3 && n%9 <= 5) return b+2;
    else return b+3;
}

int which_row(int n) {
    return (n/9) % 3;
}

int which_col(int n) {
    return (n%3);
}

void bctk(int n) {
    if(found)
        return;
    if(n == 81) {
        found = true;
        return;
    }
    int b, r, c;

    b = which_board(n);
    r = which_row(n);
    c = which_col(n);

    if(grid[b][r][c]) bctk(n+1);

    int i;

    for(i=1;i<=9;i++) {
        if((board[b]&(1<<i)) == 0 && (row[r]&(1<<i)) == 0 && (col[c]&(1<<i)) == 0){
            board[b] |= (i<<i);
            row[r] |= (i<<i);
            col[c] |= (i<<i);
            grid[b][r][c] = i;
            bctk(n+1);
            if(found) return;
            grid[b][r][c] = 0;
            board[b] &= ~(1<<i);
            row[r] &= ~(1<<i);
            col[c] &= ~(1<<i);
        }
    }

    return;
}

int main(){
    int test=0, t, i, j, k;

    scanf("%d",&t);

    while(t--) {
        for(i=0;i<=9;i++)
            board[i] = row[i] = col[i] = 0;
        k = 0;

        for(i=0;i<=8;i++) {
            scanf(" %s",arr);
            for(j=0;j<=8;j++) {
                k++;
                if(arr[j] == '.')
                    grid[which_board(k)][i][j] = 0;
                else {
                    grid[which_board(k)][i][j] = arr[j]-'0';
                    board[which_board(k)] |= 1<<(arr[j]-'0');
                    row[i] |= 1<<(arr[j]-'0');
                    col[j] |= 1<<(arr[j]-'0');
                }
            }
        }

        found = false;
        bctk(0);
        k = 0;

        for(i=0;i<=8;i++) {
            for(j=0;j<=8;j++) {
                k++;
                printf("%d ",grid[which_board(k)][i][j]);
            }
            puts("");
        }
    }

    return 0;
}
