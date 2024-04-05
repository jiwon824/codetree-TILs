#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> binary;
    int n;
    cin >> n;
    while(n){
        int disit = n%2;
        binary.push_back(disit);
        n/=2;
    }
    reverse(binary.begin(), binary.end());
    if (n==0) binary.push_back(0);
    for(auto e : binary){
        cout << e;
    }
    return 0;
}