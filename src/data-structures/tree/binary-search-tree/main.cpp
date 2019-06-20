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

    cout << bst->contain("a") << endl;
    cout << bst->contain("z") << endl;

    return 0;
}