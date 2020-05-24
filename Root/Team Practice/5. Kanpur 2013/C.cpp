#include <stdio.h>

#define SZ 4*1000010

int par[SZ];
char arr[SZ];

void failure() {
	int i, k, n;
	
	k = 0;
	par[0] = 0;
	n = strlen(arr);
	
	printf("0");
	for(i = 1; i < n; i++) {
		while(k > 0 && arr[k] != arr[i])
			k = par[k-1];
		if(arr[k] == arr[i])
			k++;
		par[i] = k;
		printf(" %d", k);
	}
	printf("\n");
	
	return;
}

int main() {
	while(scanf("%s", arr) == 1) {
		if(strcmp(arr, "End") == 0) 
			break;
		failure();
	}
	return 0;
}

