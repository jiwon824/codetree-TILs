#include <iostream>

using namespace std;
class Bomb{
    public:
        string code, color;
        int sec;
    Bomb(string code, string color, int sec){
        this->code=code;
        this->color=color;
        this->sec=sec;
    }

};
int main() {
    string input_code, input_color;
    int input_sec;
    cin >> input_code >> input_color >> input_sec;
    Bomb b = Bomb(input_code, input_color, input_sec);
    cout << "code : "<< b.code << "\ncolor : " << b.color << "\nsecond : "<<b.sec;
    return 0;
}