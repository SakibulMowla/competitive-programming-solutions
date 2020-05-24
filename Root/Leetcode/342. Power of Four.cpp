class Solution {
public:
    bool isPowerOfFour(int n) {
        int base = 1;
        while (base <= n) {
            if (base == n) return true;
            if (base <= n / 4) base *= 4;
            else return false;
        }
        return false;
    }
};
