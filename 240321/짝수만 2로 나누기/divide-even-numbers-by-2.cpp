#include <iostream>

using namespace std;
void DivideEvenNumbers(int arr[], int size){
    for(int i=0;i<size;i++){
        if(arr[i]%2==0) arr[i]/=2;
    }
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    DivideEvenNumbers(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}