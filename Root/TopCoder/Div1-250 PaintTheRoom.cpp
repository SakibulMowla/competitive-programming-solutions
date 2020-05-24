#include <bits/stdc++.h>

using namespace  std;


class PaintTheRoom {
public:
	string canPaintEvenly(int R, int C, int K) {
        if (R % 2 == 0 || C % 2 == 0) return "Paint";
        if (K == 1) return "Paint";
        return "Cannot paint";
	}
};

