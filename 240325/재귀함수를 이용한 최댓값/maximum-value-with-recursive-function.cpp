#include <iostream>
#include <algorithm>
using namespace std;

int FindMax(int *arr, int size){
    if(size==1) return max(arr[0], arr[1]);
    return max(arr[size], FindMax(arr, size-1));
}
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }
    cout << FindMax(arr, n-1);
    return 0;
}