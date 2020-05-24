//courtesy - http://adilet.org/blog/25-09-14/

#include <bits/stdc++.h>

using namespace std;

struct PalindromicTree {
    const int MAXLEN = 100000 + 10;

    /**
        every node represents a palindrome
        len - the length of palindrome represented by current node
        next - transition from this node to other nodes by different characters
        link - node number of longest suffix palindrome of current node
    **/
    struct state {
        map <char, int> next;
        int len, link;
    };

    string s;
    vector <state> tree;
    int sz;
    int last;

    ///For finding total number of palindromes
    vector <long long> dp;
    ///For finding total number of palindromes

    /**
        node 1 is root with len = -1
        node 2 is root with len = 0
    **/
    PalindromicTree() {
        tree = vector <state> (MAXLEN);
        ///For finding total number of palindromes
        dp = vector <long long> (MAXLEN, 0);
        ///For finding total number of palindromes
        sz = last = 2;
        tree[1].len = -1; tree[1].link = 1;
        tree[2].len = 0; tree[2].link = 1;
    }


    /**
        Tested Problem: NUMOFPAL(SPOJ), LPS (SPOJ), 3948(HDU)
    */
    void buildTree(string& str) {
        s = str;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            Insert(i, s[i]);
            if (i) cout << ' ';
            cout << sz - 2;
        }
        cout << endl;

        ///total number of palindromes(Unique + Non-unique) = palindromes
        long long palindromes = 0;
        for (int i = 3; i <= sz; i++) palindromes += dp[i];
        ///total number of unique palindromes is just the number of nodes in the tree except the 2 roots

        return;
    }

    /**
        returns true is a new palindromic substring is found adding new character c and false otherwise
    **/
    long long Insert(int pos, char c) {
        int cur = last, curlen = 0;

        while (true) {
            curlen = tree[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
                break;
            cur = tree[cur].link;
        }

        if (tree[cur].next[c]) {
            last = tree[cur].next[c];
            return dp[last] += 1 + dp[tree[last].link];
        }

        sz++;
        last = sz;
        tree[sz].len = tree[cur].len + 2;
        tree[cur].next[c] = sz;

        if (tree[sz].len == 1) {
            tree[sz].link = 2;
            ///For finding total number of palindromes
            return dp[sz] = 1;
            ///For finding total number of palindromes
        }

        while (true) {
            cur = tree[cur].link;
            curlen = tree[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
                tree[sz].link = tree[cur].next[c];
                break;
            }
        }

        ///For finding total number of palindromes
        return dp[sz] = 1 + dp[tree[sz].link];
        ///For finding total number of palindromes
    }
};


int main() {

    string s;
    cin >> s;

    PalindromicTree PT;
    PT.buildTree(s);

    return 0;
}
