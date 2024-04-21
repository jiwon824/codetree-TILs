#include <iostream>
#include <climits>

using namespace std;

int arr[6];
int sum;
int GetDiff(int i, int j, int k){
    int team1 = arr[i]+arr[j]+arr[k];
    int team2 = sum-team1;
    return abs(team1-team2);
}
int main() {
    for(int i=0; i<6; i++){
        cin >> arr[i];
        sum+=arr[i];
    }

    int min_diff =INT_MAX;
    for(int i=0; i<6;i++){
        for(int j= i+1; j<6;j++){
            for(int k =j+1; k<6; k++){
                min_diff = min(min_diff, GetDiff(i, j, k));
            }
        }
    }
    
    cout << min_diff;
    return 0;
}