#include <iostream>

using namespace std;

int n, t;
int arr1[201];
int arr2[201];

int main() {
    // 입력
    cin>> n >> t;
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }
    for(int i=0; i<n; i++){
        cin >> arr2[i];
    }

    // t초 동안 움직이기
    while(t--){
        int moveToArr1_Idx0 = arr2[n-1];
        int moveToArr2_Idx0 = arr1[n-1];
        for(int i=n-1; i>=0; i--){
            arr1[i]=arr1[i-1];
            arr2[i]=arr2[i-1];
        }
        arr1[0] = moveToArr1_Idx0;
        arr2[0 ]= moveToArr2_Idx0;
    }

    // 출력
    for(int i=0; i<n; i++){
        cout << arr1[i] << " ";
    }
    cout <<'\n';
    for(int i=0; i<n; i++){
        cout << arr2[i] << " ";
    }
    cout <<'\n';
    
    return 0;
}