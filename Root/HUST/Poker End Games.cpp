#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "iostream"
#include "algorithm"

using namespace std;

#define SZ 310
#define SZ1 200

double dp1[SZ][SZ1];
double dp2[SZ][SZ1];
double dp3[SZ][SZ1];
bool visited[SZ][SZ1];
double two[SZ1];

void pre() {
	int i;
	two[0] = 1.0;
	for(i = 1; i < SZ1; i++)
		two[i] = two[i-1] / 2.0;
	return;
}

int N;

double solve1(int a, int step) {
	if(step > 199) return 0.0;
	int b = N - a;
	
	if(visited[a][step])
		return dp1[a][step];
	
	double &ret = dp1[a][step];
	
	if(a == 0) 
		return ret = 0.0;
	if(b == 0)
		return ret = two[step];
		
	ret = solve1(a+min(a, b), step+1);
	ret += solve1(a-min(a, b), step+1);
	
	return ret;
}

double solve2(int a, int step) {
	if(step > 199) return 0.0;
	int b = N - a;
	
	if(visited[a][step])
		return dp2[a][step];
	
	double &ret = dp2[a][step];
	
	if(a == 0) 
		return ret = 0.0;
	if(b == 0)
		return ret = step;
		
	ret = solve2(a+min(a, b), step+1) + solve2(a-min(a, b), step+1);
	
	return ret;
}

double solve3(int a, int step) {
	if(step > 199) return 0.0;
	int b = N - a;
	
	if(visited[a][step])
		return dp3[a][step];
	
	double &ret = dp3[a][step];
	
	if(a == 0) 
		return ret = 0.0;
	if(b == 0)
		return ret = 1;
		
	ret = solve3(a+min(a, b), step+1) + solve3(a-min(a, b), step+1);
	
	return ret;
}

int main() {
	pre();
	int t, a, b;
	double d1, d2;
	
	scanf("%d",&t);
	
	while(t--) {
		scanf("%d %d",&a,&b);
		N = a + b;
		
		memset(visited, 0, sizeof(visited));
		d1 = solve2(a, 0);
		memset(visited, 0, sizeof(visited));
		d2 = solve3(a, 0);
		printf("%.10lf ",d1/d2);
		memset(visited, 0, sizeof(visited));
		printf("%.10lf\n",solve1(a, 0));
		
		printf("D1 D2 %lf %lf\n",d1,d2);
	}
	
	return 0;
}



