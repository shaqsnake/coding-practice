const int N = 100010;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): idx(0) {
        memset(chd, 0, sizeof(chd));
        memset(cnt, false, sizeof(cnt));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int p = 0;
        for (const auto &c: word) {
            int u = c - 'a';
            if (!chd[p][u]) chd[p][u] = ++idx;
            p = chd[p][u];
        }
        cnt[p+1] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return cnt[find(word)];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       if (find(prefix)) return true;
       return false; 
    }

private:
    int chd[N][26];
    bool cnt[N+1];
    int idx;
    int find(string word) {
        int p = 0;
        for (const auto &c: word) {
            int u = c - 'a';
            if (!chd[p][u]) return 0;
            p = chd[p][u];
        }
        return p+1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */