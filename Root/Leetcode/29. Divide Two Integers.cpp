class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == numeric_limits<int>::min() && divisor == -1))
            return numeric_limits<int>::max();

        int sign = ((dividend < 0) ^ (divisor < 0)) ? 0 : 1;
        long long num = dividend, den = divisor, got = 0;
        num = abs(num);
        den = abs(den);
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            if (got + (den << i) <= num) {
                got += (den << i);
                ans += (1 << i);
            }
        }

        return sign ? ans : -ans;
    }
};
