#include <iostream>

using namespace std;
class Product{
    public:
        string name;
        int code;
    Product(string name="codetree", int code=50){
        this->name = name;
        this->code = code;
    }
};
int main() {
    string name;
    int code;
    cin >> name >> code;
    Product p1 = Product();
    Product p2 = Product(name, code);
    cout << "product "<< p1.code << " is " << p1.name << '\n';
    cout << "product "<< p2.code << " is " << p2.name << '\n';
    return 0;
}