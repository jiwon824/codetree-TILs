#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[200]={0, };
    for (int i=0; i<n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        for(int j =x1+100; j<=x2+100; j++){
            arr[j]++;
        }
    }

    int answer=0;
    for(int i=0;i<200;i++){
        if(arr[i]>answer) answer=arr[i];
    }
    cout << answer-1;
    return 0;
}