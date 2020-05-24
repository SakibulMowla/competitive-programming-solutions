#include "stdio.h"

const int mod = 1e9+7;

int nCr[1001][1001];

void calculate(){
    int i, j;
    for(i=0; i<=1000; i++){
        for(j=0; j<=i; j++){
            if(j == 0) nCr[i][j] = 1;
            else if(j == 1) nCr[i][j] = i;
            else nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % mod;
        }
    }
}

int main(){
	calculate();
	int n, r;

	while(scanf("%d %d",&n,&r) == 2){
		printf("%d\n",nCr[n][r]);
	}

	return 0;
}
