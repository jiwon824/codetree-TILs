#include <iostream>
#include <algorithm>

using namespace std;

int arr[7];

bool IsAnswer(int i, int j, int k){
    int a=arr[i], b=arr[j], c=arr[k];
    int compare_arr[7]={a, b, c, a+b, b+c, a+c, a+b+c};
    sort(compare_arr, compare_arr+7);
    for(int idx=0; idx<7; idx++){
        if(arr[idx]!=compare_arr[idx]) return false;
    }
    return true;
}

int main() {
    for(int i=0; i<7; i++){
        cin >> arr[i];
    }
    sort(arr, arr+7);
    
    for(int i=0; i<7;i++){
        for(int j=i+1; j<7; j++){
            for(int k=j+1; k<7; k++){
                if(IsAnswer(i, j, k)){
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}