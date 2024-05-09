#include <iostream>
#include <climits>

using namespace std;

int n;
int arr[1001];

int Calculate_Costs(int min_val){
    int max_val = min_val+17;
    int sum_of_cost =0;
    for(int i=0; i<n; i++){
        if(min_val<=arr[i] && arr[i]<=max_val) continue;
        else if(arr[i]<min_val) {
            int cost = (min_val-arr[i])*(min_val-arr[i]);
            sum_of_cost += cost;
        }
        else if(max_val<arr[i]){
            int cost = (arr[i]-max_val)*(arr[i]-max_val);
            sum_of_cost += cost;
        }
    }
    return sum_of_cost;
}
int main() {
    cin >> n;
    int min_h =101, max_h=0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]<min_h) min_h = arr[i];
        if(max_h<arr[i]) max_h = arr[i];
    }

    int min_cost = INT_MAX;
    for(int i=min_h; i<=max_h; i++){
        int cost = Calculate_Costs(i);
        if(cost<min_cost) min_cost=cost;
    }
    cout << min_cost;
    return 0;
}