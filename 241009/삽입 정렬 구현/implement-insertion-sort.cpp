#include <iostream>
using namespace std;

const int MAX_N =101;

int n;
int arr[MAX_N];

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }    
    
    // solution
    for(int i=1; i<n; ++i){
        int key = arr[i];
        for(int j=i-1; j>=0; --j){
            if(arr[j]>key){
                arr[j+1]=arr[j];
                arr[j]=key;
            }
        }
    }

    // output
    for(int i=0; i<n; ++i){
        cout << arr[i] << " ";
    }
    return 0;
}