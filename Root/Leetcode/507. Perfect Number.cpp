class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1, divisor = 2;
        for (; divisor * divisor < num; divisor++) {
            if (num % divisor == 0) {
                sum += divisor;
                sum += num / divisor;
            }
        }
        if (divisor * divisor == num) sum += divisor;
        return sum == num;
    }
};
