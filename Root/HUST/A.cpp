#include <stdio.h>
#include <stdbool.h>

#define SZ 10001

int number[SZ], previous[SZ];

int main () {
	int n;
	scanf("%d", &n);

	previous[0] = 1;
	bool flag = false;
	int Left, Right, sum = 0;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &number[i]);
		
		if (flag) continue;

		sum = (sum + number[i]) % n;

		if (previous[sum]) {
			Left = previous[sum];
			Right = i;
			flag = true;
		} else {
			previous[sum] = i + 1;	
		}
	}	

	printf("%d\n", Right - Left + 1);
	for (int i = Left; i <= Right; i++) {
		printf("%d\n", number[i]);
	}

	return 0;
}
