#include <iostream>
#include <algorithm>

using namespace std;

int num[15];
int main() {
    for(int i=0; i<15; i++){
        cin >> num[i];
    }
    sort(num, num+15);
    int a=num[0], b=num[1], c=num[2], d=num[14]-(a+b+c);
    cout << a << " " << b << " " << c << " " << d <<'\n';
    return 0;
}