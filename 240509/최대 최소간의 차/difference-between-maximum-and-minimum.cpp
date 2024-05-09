#include <iostream>
#include <climits>

using namespace std;

int n, k;
int arr[101];

// return: 최소값이 min_val인 경우 드는 최소 비용
int Calculate_Costs(int min_val){
    // 최소값이 min_val인 경우 min_val~min_val+k 범위를 찾아보며 최소 비용 검사
    int min_cost = INT_MAX;
    for(int max_val = min_val; max_val<=min_val+k; max_val++){
        //cout <<"최소/최대값: "<< min_val << " " << max_val <<'\n';
        // min_val과 max_val을 정해두고 배열을 돌면서 비용을 계산
        int cost=0;
        for(int i=0;i<n;i++){
            // arr[i]가 최대값과 최소값 범위의 수라면 비용이 들지 않는다.
            if(min_val<=arr[i] && arr[i]<=max_val) continue;
            else if(arr[i]<min_val) cost += (min_val-arr[i]);
            else if(max_val<arr[i]) cost += (arr[i]-max_val);
        }
        //cout << "비용: " << cost << '\n';
        if(cost<min_cost) min_cost= cost;
    }
    return min_cost;
}

int main() {
    cin >> n >> k;
    int min_input=10001, max_input=0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]<min_input) min_input = arr[i];
        if(arr[i]>max_input) max_input = arr[i];
    }

    // 최소값이 i인 경우 발생하는 비용
    // 최대값은 i~i+k 중 하나의 수로 결정된다.
    int answer = INT_MAX;
    for(int i=min_input; i<=max_input; i++){
        int cost = Calculate_Costs(i);
        if(cost<answer) answer = cost;
    }
    cout << answer;
    return 0;
}