#include <iostream>

using namespace std;

int arr[101];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // (aj, i, ak)가 등차수열을 이룬다는 말은 ak-i와 i-aj가 동일하다는 것
    int answer=0;
    for (int i =0; i<100; i++){
        int num_of_ap =0;
        // 1<=j<k<=n 
        for(int j =0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[k]-i == i-arr[j]) {
                    //cout << arr[j] << " " << i << " "<< arr[k]<<'\n';
                    num_of_ap++;
                }
            }
        }
        if(answer<num_of_ap)answer=num_of_ap;
    }
    cout << answer;
    return 0;
}