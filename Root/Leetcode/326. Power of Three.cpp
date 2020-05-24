class Solution {
public:
    bool isPowerOfThree(int n) {
        int base = 1;
        while (base <= n) {
            if (base == n) return true;
            if (base <= n / 3) base *= 3;
            else return false;
        }
        return false;
    }
};
