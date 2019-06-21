#include "bst.hpp"
#include "util.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {
    string inputFile = "../1984.txt";
    vector<string> words;

    if (FileUtils::readFile(inputFile, words))
        cout << "There are totally " << words.size() << " words in '"
             << inputFile << "'" << endl;

    time_t startTime = clock();
    auto bst = make_shared<BSTree<string, int>>();
    for (const auto &word : words) {
        if (auto res = bst->search(word))
            (*res)++;
        else
            bst->insert(word, 1);
    }
    if (bst->contain("voice"))
        cout << "['voice' : " << *bst->search("voice") << "]" << endl;
    else
        cout << "No word 'voice' in '" + inputFile + "'" << endl;

    time_t endTime = clock();
    cout << "BST time: " << double(endTime - startTime) / CLOCKS_PER_SEC
         << " s." << endl;

    // bst->remove("young");
    // bst->remove("yes");
    // bst->remove("written");
    // bst->print_tree();

    startTime = clock();
    sort(words.begin(), words.end());
    auto bst2 = make_shared<BSTree<string, int>>();
    for (const auto &word : words) {
        if (auto res = bst2->search(word))
            (*res)++;
        else
            bst2->insert(word, 1);
    }
    if (bst2->contain("voice"))
        cout << "['voice' : " << *bst2->search("voice") << "]" << endl;
    else
        cout << "No word 'voice' in '" + inputFile + "'" << endl;

    endTime = clock();
    cout << "BST with sorted time: " << double(endTime - startTime) / CLOCKS_PER_SEC
         << " s." << endl;

    return 0;
}