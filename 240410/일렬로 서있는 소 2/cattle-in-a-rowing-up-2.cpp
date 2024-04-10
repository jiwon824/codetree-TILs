#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i =0; i<n ;i++){
        cin >> arr[i];
    }

    int answer =0;
    for (int i=0; i<n;i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]<=arr[j]){
                for (int k=j+1;k<n;k++){
                    if(arr[j]<=arr[k]) answer++;
                }
            }
        }
    }
    cout << answer;
    return 0;
}