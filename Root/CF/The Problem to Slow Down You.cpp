//courtesy - http://adilet.org/blog/25-09-14/

#include <bits/stdc++.h>

using namespace std;

struct PalindromicTree {
    int MAXLEN;

    /**
        every node represents a palindrome
        len - the length of palindrome represented by current node
        next - transition from this node to other nodes by different characters
        link - node number of longest suffix palindrome of current node
    **/
    struct state {
        unordered_map <char, int> next;
        int len, link;
    };

    string s;
    vector <state> tree;
    int sz;
    int last;

    ///For finding total number of palindromes
    vector <long long> cnt;
    ///For finding total number of palindromes

    /**
        node 1 is root with len = -1
        node 2 is root with len = 0
    **/
    PalindromicTree(int length) {
        MAXLEN = length + 5;
        tree = vector <state> (MAXLEN);
        ///For finding total number of palindromes
        cnt = vector <long long> (MAXLEN, 0);
        ///For finding total number of palindromes
        sz = last = 2;
        tree[1].len = -1; tree[1].link = 1;
        tree[2].len = 0; tree[2].link = 1;
    }


    /**
        Tested Problem: NUMOFPAL(SPOJ), LPS (SPOJ), 3948(HDU), 1960(Timus)
    */
    void buildTree(string& str) {
        s = str;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            Insert(i, s[i]);
        }
        return;
    }

    /**
        call this function before working with different palindromic substring frequency
        cnt[i] - total frequency of palindromic node i
        palindromes - total number of palindromes(Unique + Non-unique)
        total number of unique palindromes is just the number of nodes in the tree except the 2 roots
    **/
    long long palindromeCount() {
        long long palindromes = 0;
        for (int i = sz; i >= 3; i--) {
            cnt[tree[i].link] += cnt[i];
            palindromes += cnt[i];
        }
        cnt[1] = cnt[2] = 0;
        return palindromes;
    }

    /**
        returns true is a new palindromic substring is found adding new character c and false otherwise
    **/
    bool Insert(int pos, char c) {
        int cur = last, curlen = 0;

        while (true) {
            curlen = tree[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
                break;
            cur = tree[cur].link;
        }

        if (tree[cur].next[c]) {
            last = tree[cur].next[c];
            ///For finding total number of palindromes
            cnt[last]++;
            ///For finding total number of palindromes
            return false;
        }

        sz++;
        last = sz;
        tree[sz].len = tree[cur].len + 2;
        tree[cur].next[c] = sz;

        if (tree[sz].len == 1) {
            tree[sz].link = 2;
            ///For finding total number of palindromes
            cnt[sz] = 1;
            ///For finding total number of palindromes
            return true;
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
        cnt[sz] = 1;
        ///For finding total number of palindromes

        return true;
    }
};

long long dfs(int node1, int node2, PalindromicTree& PTa, PalindromicTree& PTb) {
    long long ans = PTa.cnt[node1] * PTb.cnt[node2];
    for (int i = 0; i < 26; i++) {
        if (PTa.tree[node1].next.count(i + 'a') && PTb.tree[node2].next.count(i + 'a')) {
            ans += dfs(PTa.tree[node1].next[i + 'a'], PTb.tree[node2].next[i + 'a'], PTa, PTb);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string a, b;
        cin >> a >> b;

        PalindromicTree PTa(a.size());
        PTa.buildTree(a);
        PTa.palindromeCount();

        PalindromicTree PTb(b.size());
        PTb.buildTree(b);
        PTb.palindromeCount();

        cout << "Case #" << cs + 1 << ": " << dfs(1, 1, PTa, PTb) + dfs(2, 2, PTa, PTb) << endl;
    }

    return 0;
}
