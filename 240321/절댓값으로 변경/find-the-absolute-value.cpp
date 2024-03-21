#include <iostream>

using namespace std;
void ToAbs(int *arr, int size){
    for (int i =0 ; i<size ; i++){
        if(arr[i]<0) arr[i] *= -1;
    }
}
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i =0;i<n;i++){
        cin >> arr[i];
    }
    ToAbs(arr, n);
    for (int i =0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}