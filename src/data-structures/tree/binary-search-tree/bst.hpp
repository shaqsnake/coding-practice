#pragma once

#include <iostream>

template <typename K, typename V>
class Node {
    template <typename, typename>
    friend class BSTree;
    friend std::ostream &operator<<(std::ostream &os, const Node *node) {
        return os << "[" << node->key << ": " << node->value << "]";
    }

public:
    Node(K k, V v) : key(k), value(v), left(nullptr), right(nullptr){};

private:
    K key;
    V value;
    Node *left;
    Node *right;
};

template <typename K, typename V>
class BSTree {
public:
    BSTree() : root(nullptr), count(0){};
    ~BSTree() { _destroy(root); };

    int size() const { return count; }
    bool empty() const { return count == 0; }
    bool contain(const K &key) const { return _contain(root, key); }
    void insert(const K &key, const V &value) {
        root = _insert(root, key, value);
    }
    void print_tree() const { _print_tree(root, "", false); }

private:
    Node<K, V> *root;
    int count;

    void _destroy(Node<K, V> *node);
    bool _contain(Node<K, V> *node, const K &key) const;
    Node<K, V> *_insert(Node<K, V> *node, const K &key, const V &value);
    void _print_tree(Node<K, V> *node, const std::string &prefix,
                     bool isLeft) const;
};

template <typename K, typename V>
inline void BSTree<K, V>::_destroy(Node<K, V> *node) {
    if (node) {
        _destroy(node->left);
        _destroy(node->right);
        // std::cout << "~Node: " << node << std::endl;
        delete node;
        count--;
    }
}

template <typename K, typename V>
bool BSTree<K, V>::_contain(Node<K, V> *node, const K &key) const {
    if (node == nullptr)
        return false;

    if (key == node->key)
        return true;
    else if (key < node->key)
        return _contain(node->left, key);
    else
        return _contain(node->right, key);
}

template <typename K, typename V>
Node<K, V> *BSTree<K, V>::_insert(Node<K, V> *node, const K &key,
                                  const V &value) {
    if (node == nullptr) {
        count++;
        return new Node<K, V>(key, value);
    }

    if (node->key == key) {
        node->value = value;
    } else if (key < node->key) {
        node->left = _insert(node->left, key, value);
    } else {
        node->right = _insert(node->right, key, value);
    }

    return node;
}

template <typename K, typename V>
void BSTree<K, V>::_print_tree(Node<K, V> *node, const std::string &prefix,
                               bool isLeft) const {
    if (node != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // print the key and value of the node
        std::cout << node << std::endl;

        // enter the next tree level - left and right branch
        _print_tree(node->left, prefix + (isLeft ? "│   " : "    "), true);
        _print_tree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}