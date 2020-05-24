#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define SZ 1000010

using namespace std;

bool arr[SZ];
int p_eular[10010],prime[12000];
int k;

void sieve() {
    int i,j,lim;
    lim = sqrt(SZ);
    prime[0]=2;
    arr[0]=arr[1]=1;
    k=1;
    for(i=3; i<=lim; i+=2) {
        if(!arr[i]) {
            for(j=i*i; j<SZ; j+=i+i)
                arr[j]=1;
        }
    }
    for(i=3; i<11000; i+=2) {
        if(!arr[i]) {
            prime[k++]=i;
        }
    }
    return;
}

inline int prime_check(int num) {
    if (num <= 1000000) {
        if (num % 2 == 0 && num != 2)
            return 0;
        return !arr[num];
    }
    for(int i=0; prime[i]*prime[i]<=num; i++) {
        if(num%prime[i]==0)
            return 0;
    }
    return 1;
}

int main() {
    sieve();
    int i,j,k;
    for(i=0,k=1; i<=10000; i++,k++) {
        j=(i*i) + i + 41;
        p_eular[k] = p_eular[k-1] + prime_check(j);
    }
    int low,high;
    double right,total,ans;
    while(scanf("%d %d",&low,&high)==2) {
        ++low;
        ++high;
        total=high-low+1;
        right=p_eular[high]-p_eular[low-1];
        ans=(right*100)/total+1e-9;
        printf("%.2lf\n",ans);
    }
    return 0;
}


