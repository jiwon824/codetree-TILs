#include <iostream>
#include <climits>

using namespace std;

int arr[100];
int main() {
    int n, h, t;
    cin >> n >> h >> t;
    
    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }

    // 연속 t개 이상의 밭이 h 높이가 되도록 만들기
    int min_cost = INT_MAX;
    for(int i=0; i<=n-t; i++){

        int cost=0;
        for(int j=i; j<i+t; j++){
            //cout << i <<" " << j <<'\n';
            if(arr[j]==h) continue;
            else if(arr[j]<h){
                cost += h-arr[j];
            }
            else{
                cost += arr[j]-h;
            }
        }

        if(cost<min_cost) min_cost = cost;
    }

    cout << min_cost;
    return 0;
}