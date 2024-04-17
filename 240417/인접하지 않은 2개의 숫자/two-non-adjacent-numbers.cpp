#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int answer = 0;
    for(int i=0; i<n; i++){
        for (int j=i+2; j<n;j++){
            if(answer < arr[i]+arr[j]) answer=arr[i]+arr[j];
        }
    }
    cout << answer;
    return 0;
}