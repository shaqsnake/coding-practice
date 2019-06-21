#pragma once

#include <cassert>
#include <iostream>
#include <queue>

// Class template declaration.
template <typename, typename> class Node;
template <typename, typename> class BSTree;

template <typename K, typename V> class Node {
    friend class BSTree<K, V>;
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

template <typename K, typename V> class BSTree {
public:
    BSTree() : root(nullptr), count(0){};
    ~BSTree() { _destroy(root); };

    int size() const { return count; }
    bool empty() const { return count == 0; }
    // Contain a key or not.
    bool contain(const K &key) const { return _contain(root, key); }
    // Insert a new key-value into BST.
    void insert(const K &key, const V &value) {
        root = _insert(root, key, value);
    }
    // Search by key, return its value if exists.
    V *search(const K &key) const { return _search(root, key); }
    // Find minimum key in BST.
    K findMin() const {
        assert(count != 0);
        Node<K, V> *node = _findMin(root);
        return node->key;
    }
    // Find maximum key in BST.
    K findMax() const {
        assert(count != 0);
        Node<K, V> *node = _findMax(root);
        return node->key;
    }
    // Remove the node with minimum key.
    void removeMin() {
        if (root)
            root = _removeMin(root);
    }
    // Remove the node with maximum key.
    void removeMax() {
        if (root)
            root = _removeMax(root);
    }
    // Print BST nodes by pre-order.
    void preOrder() const { _preOrder(root); }
    // Print BST nodes by in-order.
    void inOrder() const { _inOrder(root); }
    // Print BST nodes by post-order.
    void postOrder() const { _postOrder(root); }
    // Print BST nodes by BFS.
    void levelOrder() const;
    // Print BST in a pretty format.
    void print_tree() const { _print_tree(root, "", false); }

private:
    Node<K, V> *root;
    int count;

    void _destroy(Node<K, V> *node);
    bool _contain(Node<K, V> *node, const K &key) const;
    Node<K, V> *_insert(Node<K, V> *node, const K &key, const V &value);
    V *_search(Node<K, V> *node, const K &key) const;
    Node<K, V> *_findMin(Node<K, V> *node) const;
    Node<K, V> *_findMax(Node<K, V> *node) const;
    Node<K, V> *_removeMin(Node<K, V> *node);
    Node<K, V> *_removeMax(Node<K, V> *node);
    void _preOrder(Node<K, V> *node) const;
    void _inOrder(Node<K, V> *node) const;
    void _postOrder(Node<K, V> *node) const;
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
V *BSTree<K, V>::_search(Node<K, V> *node, const K &key) const {
    if (node == nullptr)
        return nullptr;

    if (key == node->key)
        return &node->value;
    else if (key < node->key)
        return _search(node->left, key);
    else
        return _search(node->right, key);
}

template <typename K, typename V>
Node<K, V> *BSTree<K, V>::_findMin(Node<K, V> *node) const {
    if (node->left)
        return _findMin(node->left);
    return node;
}

template <typename K, typename V>
Node<K, V> *BSTree<K, V>::_findMax(Node<K, V> *node) const {
    if (node->right)
        return _findMax(node->right);
    return node;
}

template <typename K, typename V>
Node<K, V> *BSTree<K, V>::_removeMin(Node<K, V> *node) {
    if (node->left == nullptr) {
        Node<K, V> *rightChild = node->right;
        delete node;
        count--;
        return rightChild;
    }

    node->left = _removeMin(node->left);
    return node;
}

template <typename K, typename V>
Node<K, V> *BSTree<K, V>::_removeMax(Node<K, V> *node) {
    if (node->right == nullptr) {
        Node<K, V> *leftChild = node->left;
        delete node;
        count--;
        return leftChild;
    }
    node->right = _removeMax(node->right);
    return node;
}

template <typename K, typename V>
void BSTree<K, V>::_preOrder(Node<K, V> *node) const {
    if (node) {
        std::cout << node << " ";
        _preOrder(node->left);
        _preOrder(node->right);
    }
}

template <typename K, typename V>
void BSTree<K, V>::_inOrder(Node<K, V> *node) const {
    if (node) {
        _inOrder(node->left);
        std::cout << node << " ";
        _inOrder(node->right);
    }
}

template <typename K, typename V>
void BSTree<K, V>::_postOrder(Node<K, V> *node) const {
    if (node) {
        _postOrder(node->left);
        _postOrder(node->right);
        std::cout << node << " ";
    }
}

template <typename K, typename V> void BSTree<K, V>::levelOrder() const {
    std::queue<Node<K, V> *> q;
    q.push(root);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        std::cout << node << " ";

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
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