#include <iostream>
#include <boost/type_index.hpp>
#include <vector>

using namespace std;
using boost::typeindex::type_id;
using boost::typeindex::type_id_with_cvr;

int main() {
    vector<int> v;
    auto it = v.cbegin();

    cout << "*** Using typeid\n";
    cout << typeid(const int).name() << endl;
    cout << typeid(v).name() << endl;
    cout << typeid(it).name() << endl;

    cout << "*** Using type_id\n";
    cout << type_id<const int>() << endl;
    cout << type_id<decltype(v)>() << endl;
    cout << type_id<decltype(it)>() << endl;

    cout << "*** Using type_id\n";
    cout << type_id_with_cvr<const int>() << endl;
    cout << type_id_with_cvr<decltype((v))>() << endl;
    cout << type_id_with_cvr<decltype(move((v)))>() << endl;
    cout << type_id_with_cvr<decltype((it))>() << endl;

    return 0;
}