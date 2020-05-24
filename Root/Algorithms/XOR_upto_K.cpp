///Returns 0 ^ 1 ^ .... ^ k:
#include "stdio.h"

int xorUpToK(int k) {
	switch (k % 4) {
		case 0: return k;
		case 1: return 1;
		case 2: return k + 1;
		case 3: return 0;
	}
}

int main(){
    int n;
    while(scanf("%d",&n) == 1)
        printf("%d\n",xorUpToK(n));
    return 0;
}
