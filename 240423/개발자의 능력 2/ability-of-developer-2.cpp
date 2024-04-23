#include <iostream>
#include <climits>

using namespace std;

int arr[6];
int total_sum =0;
int GetDiff(int a, int b, int c, int d){
    int team1 = arr[a]+arr[b], team2 = arr[c]+arr[d], team3 = total_sum-(arr[a]+arr[b]+arr[c]+arr[d]);
    
    if(team1==team2 || team2==team3 || team1==team3) return 0;

    int max_team, min_team;
    if(team1>team2 && team1>team3) {
        max_team = team1;
        if(team2<team3) min_team = team2;
        else min_team = team3;
    }
    else if(team2>team1 && team2>team3) {
        max_team = team2;
        if(team1<team3) min_team = team1;
        else min_team = team3;
    } 
    else if(team3>team1 && team3>team2) {
        max_team = team3;
        if(team1<team2) min_team = team1;
        else min_team = team2;
    }
    return max_team - min_team;
}

// 팀원들의 능력 총합이 가장 큰 팀과 가장 작은 팀의 차이를 최소화 할 수 있게 균형있게 구성해줄 때의 차를 출력
int main() {
    for (int i =0; i<6; i++){
        cin >> arr[i];
        total_sum += arr[i];
    }

    int min_diff = INT_MAX;
    for(int i=0; i<6; i++){
        for(int j=i+1; j<6; j++){
            for(int k=0; k<6; k++){
                for(int l=k+1; k<6; k++){
                    if(k == i || k == j || l == i || l == j) continue;
                    min_diff = min(min_diff, GetDiff(i, j, k, l));
                }
            }
        }
    }
    cout << min_diff;
    return 0;
}