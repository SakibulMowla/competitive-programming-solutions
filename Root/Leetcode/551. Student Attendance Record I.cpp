class Solution {
public:
    bool checkRecord(string s) {
        int lateCount = 0, absentCount = 0;
        bool flag = true;
        for (auto &x: s) {
            if (x == 'L') {
                lateCount++;
            } else {
                lateCount = 0;
                if (x == 'A') {
                    absentCount++;
                }
            }
            if (lateCount == 3 || absentCount == 2) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};