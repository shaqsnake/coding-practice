#pragma once

#include <iostream>

template <typename K, typename V>
class Node {
    template <typename, typename>
    friend class BSTree;

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
    void insert(const K &key, const V &value) {
        root = _insert(root, key, value);
    }
    void print_tree() const { _print_tree(root, "", false); }

private:
    Node<K, V> *root;
    int count;

    void _destroy(Node<K, V> *root);
    Node<K, V> *_insert(Node<K, V> *node, const K &key, const V &value);
    void _print_tree(Node<K, V> *node, const std::string &prefix,
                     bool isLeft) const;
};

template <typename K, typename V>
inline void BSTree<K, V>::_destroy(Node<K, V> *node) {
    if (node) {
        _destroy(node->left);
        _destroy(node->right);
        // std::cout << "~Node: " << node->key << std::endl;
        delete node;
    }
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
        std::cout << "[ " << node->key << ": " << node->value << " ]"
                  << std::endl;

        // enter the next tree level - left and right branch
        _print_tree(node->left, prefix + (isLeft ? "│   " : "    "), true);
        _print_tree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}