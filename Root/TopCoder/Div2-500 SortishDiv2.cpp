#include <bits/stdc++.h>

using namespace std;


class SortishDiv2 {
public:
    int calc(vector <int> &v) {
        int k = 0;
        for(int i = 0; i < v.size(); i++)
            for(int j = i+1; j < v.size(); j++)
                if(v[i] < v[j])
                    k++;
        return k;
    }
	int ways(int sortedness, vector <int> seq) {
		int k = seq.size();
		vector <int> pos;
		vector <int> tmp;
		for(int i = 0; i < k; i++)
            if(seq[i] == 0)
                pos.push_back(i);
        vector <int> nai;
        for(int i = 1; i <= k; i++)
        {
            int j;
            for(j = 0; j < k; j++)
                if(seq[j] == i)
                    break;
            if(j == k)
                nai.push_back(i);
        }
        int ans = 0;
        if(nai.size()){
            do{
                tmp = seq;
                for(int i = 0; i < pos.size(); i++)
                    tmp[ pos[i] ] = nai[i];
                if(calc(tmp)==sortedness)
                    ans++;
            }while(next_permutation(nai.begin(), nai.end()));
        }
        else{
            ans += (calc(seq)==sortedness);
        }
        return ans;
	}
};
