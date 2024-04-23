#include <iostream>
#include <climits>
using namespace std;

int arr[5];
int total_sum;

int GetDiff(int a, int b, int c, int d){
    int team1= arr[a]+arr[b], team2=arr[c]+arr[d], team3 = total_sum-(team1+team2);
    int max_team = max(team1, max(team2, team3)), min_team = min(team1, min(team2, team3));
    return max_team-min_team;
}
int main() {
    for(int i=0; i<5; i++){
        cin >> arr[i];
        total_sum+= arr[i];
    }

    int min_diff = INT_MAX;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            for(int k=0; k<5; k++){
                for(int l=k+1; l<5; l++){
                    if(i==k || j==k || i==l || j==l) continue;
                    // 모든 팀의 능력치가 달라야 함
                    if(arr[i]+arr[j]==arr[k]+arr[l] || arr[i]+arr[j]==total_sum-(arr[i]+arr[j]) || arr[k]+arr[l]==total_sum-(arr[k]+arr[l])) continue;
                    //cout << i << " " << j << " " << k << " " << l << " " << GetDiff(i, j, k, l) << '\n';
                    min_diff = min(min_diff, GetDiff(i, j, k, l));
                }
            }
        }
    }
    if(min_diff==INT_MAX) cout << "-1";
    else cout << min_diff;
    return 0;
}