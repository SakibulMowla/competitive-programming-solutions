#include <bits/stdc++.h>

using namespace std;

struct SuffixAutomata {
    struct state {
        int len, link;
        map <char, int> next;
    };

    const int MAXLEN = 250000;
    vector <state> st;
    int sz;
    int last;

    SuffixAutomata() {
        st = vector <state> (MAXLEN * 2);
        last = 0;
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;
    }

    void BuildAutomata(string& s) {
        for (auto &x: s) Insert(x);
    }

    void Insert (char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p;
        for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
            st[p].next[c] = cur;
        if (p == -1)
            st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                for (; p !=- 1 && st[p].next[c] == q; p = st[p].link)
                    st[p].next[c] = clone;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    /**
        Finds the lexicographically earliest longest common substring between the String s
        and string on which automata is built
    **/
    string LongestCommonSubstring(string& s) {
        int v = 0, l = 0, best = 0, bestpos = 0;
        for (int i = 0; i < s.size(); i++) {
            while (v && !st[v].next.count(s[i])) {
                v = st[v].link;
                l = st[v].len;
            }
            if (st[v].next.count(s[i])) {
                v = st[v].next[s[i]];
                l++;
            }
            if (l > best)
                best = l, bestpos = i;
        }
        return s.substr(bestpos - best + 1, best);
    }
};


int main() {
    ios_base::sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;

    SuffixAutomata SA;
    SA.BuildAutomata(s1);

    string ans = SA.LongestCommonSubstring(s2);
    if (ans.size()) cout << ans << endl;
    cout << ans.size() << endl;

    return 0;
}
