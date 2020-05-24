//ACed

#include <bits/stdc++.h>
using namespace  std;

typedef long long ll;

#define sz(x) (int)x.size()

#define SZ 1000010

bool arr[SZ];
vector <int> prime;

void sieve(){
    int i, j, k;

    k = sqrt(SZ);

    for(i=3;i<=k;i++)
        if(!arr[i])
            for(j=i*i;j<SZ;j+=i)
                arr[j] = 1;

    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(!arr[i])
            prime.push_back(i);
}

class BigFatInteger {
public:
	int minOperations(int A, int B) {
	    sieve();
        int i, j, k, cnt, mx;
        ll two;

        cnt = mx = 0;
        k = sz(prime);

        for(i=0;i<k && A!=1;i++){
//                printf("A = %d\n",A);
            if(A%prime[i] == 0){
                j = 0;
                while(A%prime[i] == 0){
                    j++;
                    A /= prime[i];
                }
                mx = max(mx, j);
                cnt++;
//                printf("%d %d\n", prime[i], j);
            }
        }

        if(A != 1)
            cnt++;

        two = 1;
        while(two < (ll)((ll)B*(ll)mx)){
            two <<= 1;
            cnt++;
        }

        return cnt;
	}
};
