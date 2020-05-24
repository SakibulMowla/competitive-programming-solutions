//
//  main.cpp
//  Works Application Exam#3
//
//  Created by Kaidul Islam on 16/2/17.
//  Copyright © 2017 Kaidul Islam. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m, K;
vector<vector<vector<bool>>> grid;
vector<vector<bool>> candidate; // pixels which are not all off or all on for all characters
bool found;

bool isValid(vector<pair<int, int>> pixel) {
    unordered_set<int> maskSet;
    for(int i = 0; i < K; i++) {
        int mask = 0;
        for(int j = 0; j < pixel.size(); j++) {
            int x = pixel[j].first;
            int y = pixel[j].second;
            if(grid[i][x][y]) {
                mask |= (1 << j);
            }
        }
        maskSet.insert(mask);
    }

    return maskSet.size() == K;
}

bool checkAllCombination(int x, int y, const int nPixel, vector<pair<int, int>>& pixel) {
    if(found) { // prune
        return found;
    }
    if((int)pixel.size() == nPixel) {
        return found = isValid(pixel);
    }
    if(x == n) {
        return false;
    }
    int nextY = (y + 1) % m;
    int nextX = x + (nextY == 0);

    if(candidate[x][y]) {
        pixel.push_back({x, y});
        if(checkAllCombination(nextX, nextY, nPixel, pixel)) {
            return true;
        }
        pixel.pop_back();
    }

    if(checkAllCombination(nextX, nextY, nPixel, pixel)) {
        return true;
    }

    return false;
}

bool canRecognize(int nPixel) {
    found = false;
    vector<pair<int, int>> pixel;
    return checkAllCombination(0, 0, nPixel, pixel);
}

int main(int argc, const char * argv[]) {
//#ifndef ONLINE_JUDGE
////    assert(freopen("/Users/kaidul/Documents/C++ workspace/Works Application Exam#3/Works Application Exam#3/input.txt", "r", stdin));
//#endif
//    freopen("4.txt", "r", stdin);
//    freopen("5.txt", "w", stdout);

    while (scanf("%d %d %d", &n, &m, &K) == 3)
    {
        grid = vector<vector<vector<bool>>>(K, vector<vector<bool>>(n, vector<bool>(m, false)));
        candidate = vector<vector<bool>>(n, vector<bool>(m, false));
        string line;
        char pixel;
        for(int i = 0; i < K; i++) {
            getline(cin, line);
            for(int j = 0; j < n; j++) {
                int pixel = getchar();
                for(int k = 0; k < m; k++) {
                    pixel = getchar();
//                    scanf(" %c", &pixel);
                    grid[i][j][k] = pixel - 48;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int mask = 0;
                for(int k = 0; k < K; k++) {
                    if(grid[k][i][j]) {
                        mask |= (1 << k);
                    }
                }
                if(mask != 0 and mask != (1 << K) - 1) {
                    candidate[i][j] = true;
                }
            }
        }
        int left = ceil(log(K) / log(2.0));
        int right = K;
    //    assert(left <= right);
        int result = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(canRecognize(mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    //    assert(result != -1);
        printf("%d\n", result);

        if (result == -1) {
            printf("%d %d %d\n", n, m, K);
            for(int i = 0; i < K; i++) {
                for(int j = 0; j < n; j++) {
                    for(int k = 0; k < m; k++) {
                        printf("%d", (int)grid[i][j][k]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
    }
    return 0;
}

/*
2 2 5
11
00

00
00

10
10

01
00

10
00
*/
