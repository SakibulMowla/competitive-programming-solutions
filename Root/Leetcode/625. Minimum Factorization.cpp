vector <int> ans, tmp;
bool found;
map <int, int> mark;

class Solution {
public:
    
    static void solve(int n) {
        //cout << "left = " << n << endl;
        if (found == true) return;
        
        if (n == 1) {
            vector <int> ttmp = tmp;
            sort(ttmp.begin(), ttmp.end());
            if (ans.size() == 0 || tmp.size() < ans.size()) ans = ttmp, found = true;
            else if (ans.size() == tmp.size()) {
                for (int i = 0; i < ans.size(); i++) {
                    if (ans[i] > ttmp[i]) {
                        ans = ttmp;
                        break;
                    }
                }
            }
        } else {
            for (int i = 9; i > 1; i--) {
                if (n % i == 0) {
                    //cout << "teken = " << i << endl;
                    tmp.push_back(i);
                    solve(n / i);
                    if (found == true) return;
                    tmp.erase(tmp.begin() + tmp.size() - 1);
                }
            }
        }
        return;
    } 
    
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        tmp.clear();
        ans.clear();
        mark.clear();
        found = false;
        solve(a);
        if (ans.size() > 10) return 0;
        long long n = 0;
        for (int i = 0; i < ans.size(); i++) {
            n = n * 10 + ans[i];
        }
        if (n > numeric_limits<int>::max()) return 0;
        return n;
    }
};