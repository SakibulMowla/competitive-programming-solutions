#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct SuffixAutomata {
    struct state {
        int len, link;
        unordered_map <char, int> next;
    };

    const int MAXLEN = 100001;
    vector <state> st;
    int sz;
    int last;

    ///For finding number of occurrences
    vector < vector <int> > base;
    vector <int> cnt;
    vector <long long> dp;
    bool isPreProcessed;
    ///For finding number of occurrences

    SuffixAutomata() {
        st = vector <state> (MAXLEN * 2);
        last = 0;
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;

        ///For finding number of occurrences
        cnt = vector <int> (MAXLEN * 2);
        isPreProcessed = false;
        dp = vector <long long> (MAXLEN * 2, 0);
        base = vector < vector <int> > (MAXLEN, vector <int> ());
        ///For finding number of occurrences
    }

    void clean() {
        st = vector <state> (MAXLEN * 2);
        last = 0;
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;

        ///For finding number of occurrences
        cnt = vector <int> (MAXLEN * 2);
        isPreProcessed = false;
        dp = vector <long long> (MAXLEN * 2, 0);
        ///For finding number of occurrences
    }

    void BuildAutomata(string& s) {
        for (auto &x: s) Insert(x);
    }

    void Insert(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;

        ///For finding number of occurrences
        cnt[cur] = 1;
        base[st[cur].len].push_back(cur);
        ///For finding number of occurrences

        int p;
        for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link) {
            st[p].next[c] = cur;
        }
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

                ///For finding number of occurrences
                cnt[clone] = 0;
                base[st[clone].len].push_back(clone);
                ///For finding number of occurrences
            }
        }
        last = cur;
    }

    /**
        Finds the lexicographically earliest longest common substring between the String s
        and string on which automata is built
        Tested Problem: SSTORY(CodeChef)
    **/
    string LongestCommonSubstring(string &s) {
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

    /**
        Finds the number of time(s) String s occurs in the String on which
        automata is built
        Tested Problem: 432D(CF)
    **/

    int OccurrencesPreprocess() {
        for (int i = MAXLEN - 1; i >= 0; i--) {
            int lim = base[i].size();
            for (int j = 0; j < lim; j++) {
                cnt[st[base[i][j]].link] += cnt[base[i][j]];
            }
            base[i].clear();
        }
    }

    int Occurrences(string& s) {
        if (isPreProcessed == false) OccurrencesPreprocess();
        isPreProcessed = true;

        int v = 0;
        for (auto &x: s) v = st[v].next[x];

        return cnt[v];
    }

    ll dfs (int node) {
        if (dp[node]) return dp[node];
        dp[node] = (node != 0 ? (ll)cnt[node] * (ll)cnt[node] : 0);
        for (auto x: st[node].next) {
            dp[node] += dfs(x.second);
        }
        return dp[node];
    }
};


int main() {
    /**
        builds automata on String s1 and finds out the Longest common substring between s1 and s2
        string s1, s2;
        cin >> s1 >> s2;
        SuffixAutomata SA;
        SA.BuildAutomata(s1);
        cout << SA.LongestCommonSubstring(s2) << ;
    **/

    ios::sync_with_stdio(false);

    SuffixAutomata SA;

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        SA.BuildAutomata(s);
        SA.OccurrencesPreprocess();
        cout << SA.dfs(0) << endl;
        if (t) SA.clean();
    }

    return 0;
}
