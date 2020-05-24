class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        for (int i = 0, j = 0; i < n1; i++) {
            bool flag = false;
            for (; j < n2; j++) {
                if (s[i] == t[j]) {
                    flag = true;
                    j++;
                    break;
                }
            }
            if (flag == false) return flag;
        }
        return true;
    }
};
