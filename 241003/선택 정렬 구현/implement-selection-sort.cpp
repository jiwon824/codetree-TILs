#include <iostream>
using namespace std;

const int MAX_N=101;

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    
    for(int i=0; i<n; ++i){
        int min_idx=i;
        for(int j=i; j<n; ++j){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        int tmp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=tmp;

    }

    for(int i=0; i<n; ++i){
        cout << arr[i] << " ";
    }
    cout << '\n';
    return 0;
}