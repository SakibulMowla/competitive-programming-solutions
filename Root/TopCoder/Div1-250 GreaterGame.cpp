#include <bits/stdc++.h>

using namespace std;


class GreaterGame {
public:
    int has[110], lft[110];

	double calc(vector <int> hand, vector <int> sothe) {
		int n = hand.size();

		memset(has, 0, sizeof has);
		for(int i = 1; i <= 100; i++)
            lft[i] = 1;

		for(int i = 0; i < n; i++)
            has[ hand[i] ] = 1, lft[ hand[i] ] = 0;

        for(int i = 0; i < n; i++)
            if(sothe[i] != -1)
                lft[ sothe[i] ] = 0;

        double point = 0.0;

        for(int i = 0; i < n; i++)
        {
            if(sothe[i] != -1)
            {
                int flag = 0;
                for(int j = sothe[i] + 1; j <= 2*n; j++)
                    if(has[j] == 1)
                    {
                        has[j] = 0;
                        point = point + 1.0;
//                        sothe[i] = -1;
                        flag = 1;
                        break;
                    }
                if(flag == 0)
                    for(int j = 1; j <= 2*n; j++)
                        if(has[j] == 1)
                        {
                            has[j] = 0;
//                            sothe[i] = -1;
                            break;
                        }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(has[ hand[i] ])
                cnt++;
        if(cnt)
        {
            double tmp = 0.0;
            for(int i = 0; i < n; i++)
            {
                if(has[ hand[i] ])
                    for(int j = 1; j <= 2*n; j++)
                        if(lft[j])
                        {
                            tmp += (double) (hand[i] > j);
                        }
            }
            tmp = tmp / (double)cnt;
//            printf(">>>>>>>>>>>>>>>>>>>>>>>>> tmp = %lf\n", tmp);
            point = point + tmp;
        }

        return point;
	}
};
