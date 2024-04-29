#include <iostream>

using namespace std;

int arr[101];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // (ai, k, aj)가 등차수열을 이룬다는 말은 aj-k와 k-ai가 동일하다는 것
    int answer=0;
    for (int i =-100; i<200; i++){
        // 1<=j<k<=n 
        for(int j =0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[j]-i == i-arr[k]) {
                    //cout << arr[j] << " " << i << " "<< arr[k]<<'\n';
                    answer++;
                }
            }
        }
    }
    cout << answer;
    return 0;
}