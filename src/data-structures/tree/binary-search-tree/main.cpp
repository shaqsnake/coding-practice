#include <iostream>
#include <string>
#include <memory>
#include "bst.hpp"

using namespace std;

int main() {
    auto bst = make_shared<BSTree<string, int>>();

    bst->insert("c", 1);
    bst->insert("b", 2);
    bst->insert("a", 3);
    bst->insert("d", 4);

    cout << bst->size() << endl;

    bst->print_tree();

    if (bst->contain("a"))
        cout << *bst->search("a") << endl;
    if (bst->contain("z"))
        cout << *bst->search("z") << endl;

    bst->preOrder();
    cout << endl;
    bst->inOrder();
    cout << endl;
    bst->postOrder();
    cout << endl;
    bst->levelOrder();
    cout << endl;

    return 0;
}