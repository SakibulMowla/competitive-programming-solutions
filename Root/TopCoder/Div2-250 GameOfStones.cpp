#include <bits/stdc++.h>

using namespace std;


class GameOfStones {
public:
	int count(vector <int> stones) {
	    int k = stones.size(), sum = 0;
	    for(int i = 0; i < k; i++){
            sum += stones[i];
	    }
	    if(sum%k != 0) return -1;
        int avg = sum / k;
        int ans = 0;
        for(int i = 0; i < k; i++) {
            if((stones[i]-avg)%2 != 0) return -1;
            if((stones[i]-avg) > 0) ans += (stones[i]-avg)/2;
        }
        return ans;
	}
};
