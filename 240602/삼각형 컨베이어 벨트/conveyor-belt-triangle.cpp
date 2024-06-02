#include <iostream>

using namespace std;

int n, t;
int arr1[201];
int arr2[201];
int arr3[201];

void GetInput(){
    cin >> n >> t;
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }
    for(int i=0; i<n; i++){
        cin >> arr2[i];
    }
    for(int i=0; i<n; i++){
        cin >> arr3[i];
    }
}

void PrintOut(){
    for(int i=0; i<n; i++){
        cout << arr1[i]<<" ";
    }
    cout <<'\n';
    for(int i=0; i<n; i++){
        cout << arr2[i]<<" ";
    }
    cout <<'\n';
    for(int i=0; i<n; i++){
        cout << arr3[i] <<" ";
    }
    cout <<'\n';
}

int main() {
    GetInput();

    while (t--){
        int move3to1 = arr3[n-1]; //3->1로 이동
        int move1to2 = arr1[n-1]; //1->2로 이동
        int move2to3 = arr2[n-1]; //2->3로 이동
        
        for(int i=n-1; i>=0; i--){
            arr1[i]=arr1[i-1];
        }
        for(int i=n-1; i>=0; i--){
            arr2[i]=arr2[i-1];
        }
        for(int i=n-1; i>=0; i--){
            arr3[i]=arr3[i-1];
        }

        arr1[0]=move3to1;
        arr2[0]=move1to2;
        arr3[0]=move2to3;

    }

    PrintOut();
    return 0;
}