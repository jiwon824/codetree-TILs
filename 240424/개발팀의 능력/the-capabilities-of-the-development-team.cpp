#include <iostream>
#include <climits>
using namespace std;

int arr[5];
int total_sum;

int GetDiff(int a, int b, int c){
    int max_team = max(a, max(b, c)), min_team = min(a, min(b, c));
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
                    int team1= arr[i]+arr[j], team2=arr[k]+arr[l], team3 = total_sum-(team1+team2);
                    if(team1==team2 || team1==team3 || team2==team3) continue;
                    min_diff = min(min_diff, GetDiff(team1, team2, team3));
                }
            }
        }
    }
    if(min_diff==INT_MAX) cout << "-1";
    else cout << min_diff;
    return 0;
}