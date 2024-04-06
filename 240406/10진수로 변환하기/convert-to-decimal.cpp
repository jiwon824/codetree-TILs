#include <iostream>
#include <cmath> // pow()
using namespace std;

int main() {
    string binary;
    cin >>binary;

    int answer=0;
    for (int i=binary.length()-1 ;i>=0; i--){
        int num = binary[i]-'0';
        answer += num*pow(2, binary.length()-1-i);
    }
    cout << answer;
    return 0;
}