#include <string>
#include <iostream>

using namespace std;

class Shape {
public:
    virtual ~Shape() {
        cout << "Delete Shape!" << endl;
    }

    virtual double caclArea() {
        cout << "Shape area" << endl;
        return 0;
    }
private:
    int edge_;
};

class Circle: public Shape {
public:
    virtual ~Circle() {
        cout << "Delete Circle!" << endl;
    }
    
    virtual double caclArea() {
        cout << "Circle area" << endl;
        return 0;
    }
private:
    int raduis_;
};

int main() {
    auto s = new Shape();
    s->caclArea();
    delete s;
    cout << endl;

    auto c = new Circle();
    c->caclArea();
    delete c;
    cout << endl;

    Shape* p = new Circle();
    p->caclArea();
    delete p;

    return 0;
}
