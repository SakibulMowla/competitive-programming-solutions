#include<stdio.h>
#include<string.h>
#define MAXD 100010
int L[MAXD], R[MAXD];
char b[MAXD];
void solve()
{
    int i, j, k;
    L[0] = R[0] = 0;
    for(i = 1; b[i]; i ++)
    {
        if(b[i] == '[')
            L[i] = 0, R[i] = R[0];
        else if(b[i] == ']')
            L[i] = L[0], R[i] = 0;
        else
            L[i] = i - 1, R[i] = R[i - 1];
        L[R[i]] = i, R[L[i]] = i;
    }
    for(i = R[0]; i != 0; i = R[i]) if(b[i] != '[' && b[i] != ']') printf("%c", b[i]);
    printf("\n");
}
int main()
{
    while(gets(b + 1) != NULL)
        solve();
    return 0;
}
