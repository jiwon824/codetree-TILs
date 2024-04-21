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
    for(int i=0; i<n; i++){
        int cost=0, num_of_h =0;
        for(int j=i;j<n;j++){
            if(arr[j]==h){
                num_of_h++;
            }
            else if(arr[j]<h){
                cost += h-arr[j];
                num_of_h++;
            }
            else{
                cost += arr[j]-h;
                num_of_h++;
            }
            if(num_of_h>=t) break;
        }
        if(cost<min_cost) min_cost = cost;
    }
    cout << min_cost;
    return 0;
}