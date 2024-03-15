#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >>k;
    int* numbers =new int[n];
    for (int i=0;i<n;i++){
        numbers[i]=i+1;
    }
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    for (int i=0; i<k;i++){
        reverse(numbers+a1-1, numbers+a2);
        reverse(numbers+b1-1, numbers+b2);
    }

    // answer
    for(int i=0;i<n;i++){
        cout<< numbers[i] <<'\n';
    }
    return 0;
}