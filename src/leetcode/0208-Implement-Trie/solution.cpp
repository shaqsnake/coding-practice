// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-13 15:32:02
 * @LastEditTime: 2019-08-13 16:16:21
 * @Description: 208. Implement Trie (Prefix Tree)
 */
class Node {
    friend class Trie;

public:
    Node() : isWord_(false) {
        for (int i = 0; i < 26; i++)
            ne_[i] = nullptr;
    };
    ~Node() = default;

private:
    Node *ne_[26];
    bool isWord_;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root_(new Node()) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root_;
        for (auto const &w : word) {
            int u = w - 'a';
            if (!p->ne_[u]) p->ne_[u] = new Node();
            p = p->ne_[u];
        }
        
        p->isWord_ = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root_;
        for (auto const &w : word) {
            int u = w - 'a';
            if (!p->ne_[u]) return false;
            p = p->ne_[u];
        }

        return p->isWord_;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        auto p = root_;
        for (auto const &w : prefix) {
            int u = w - 'a';
            if (!p->ne_[u]) return false;
            p = p->ne_[u];
        }

        return true;
    }

private:
    Node *root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */