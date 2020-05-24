/*
    Author       :  Jan
    Problem Name :
    Algorithm    :
    Complexity   :
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("1.txt", "w", stdout);

    double cl = clock();

    int cases = 10;
    printf("%d\n", cases);
    while( cases-- ) {
        int query;

        query = 30000 - rand() % 100;

        if( cases == 1 ) query = 30000;

        printf("%d\n", query);

        query--;

        int k = 0;
        while( query-- ) {
            if( rand() % 4 == 0 || k++ <= 50 ) {
                printf("0 %d %d\n", rand() % 1001, rand() % 1001);
            }
            else {
                int x1, y1, x2, y2;

                while( 1 ) {
                    x1 = rand() % 1001;
                    x2 = rand() % 1001;

                    if( x2 - x1 >= 500 ) break;
                    if( rand() % 100 == 0 && x2 > x1 ) break;
                }
                while( 1 ) {
                    y1 = rand() % 1001;
                    y2 = rand() % 1001;

                    if( y2 - y1 >= 500 ) break;
                    if( rand() % 10 == 0 && y2 > y1 ) break;
                }
                if( rand() % 5 == 0 ) {
                    x1 = rand() % 100;
                    x2 = 1000 - rand() % 100;
                }
                if( rand() % 5 == 0 ) {
                    y1 = rand() % 100;
                    y2 = 1000 - rand() % 100;
                }
                printf("1 %d %d %d %d\n", x1, y1, x2, y2);
            }

        }
        puts("1 0 0 1000 1000");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
