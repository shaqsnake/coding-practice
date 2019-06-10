#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class ABBA {
public:
    string canObtain(string initial, string target);
};

string ABBA::canObtain(string initial, string target) {
    while (target.size() > initial.size()) {
        auto len = target.size();
        if (target[len - 1] == 'B') {
            target = target.substr(0, len - 1);
            reverse(target.begin(), target.end());
        } else {
            target = target.substr(0, len - 1);
        }
    }

    return initial == target ? "Possible" : "Impossible";
}

int main() {
    ABBA abba;
    cout << abba.canObtain("B", "ABBA") << endl;
    cout << abba.canObtain("AB", "ABB") << endl;
    cout << abba.canObtain("BBAB", "ABABABABB") << endl;
    cout << abba.canObtain("BBBBABABBBBBBA",
                           "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA")
         << endl;
    cout << abba.canObtain("A", "BB") << endl;
    return 0;
}