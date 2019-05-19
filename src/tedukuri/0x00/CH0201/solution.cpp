#include <iostream>

using namespace std;

int n;
string input;
int a[5][5];

int main() {
    cin >> n;
    while (n--) {
        for (int i=0; i<5; ++i) {
            cin >> input;
            for (int j=0; j<5; ++j) {
                a[i][j] = input[j] - '0';
            }
        }

        for (int i=0; i<5; ++i) {
            for (int j=0; j<5; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }    
}