#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cost;
//int cost[1000][2];// [n][P(i), S(i)]

// 선물가격+배송비가 작은 순으로 정렬
bool cmp(vector<int> &v1, vector<int> &v2){
  return v1[0]+v1[1]<v2[0]+v2[1];
}

int main() {
    int n, b;
    cin >> n >> b;
    for(int i=0; i<n; i++){
        int p, s;
        cin >> p >> s;
        cost.push_back({p, s});
    }
    sort(cost.begin(), cost.end(), cmp);
    //for(int i=0; i<n; i++){
    //    cout << cost[i][0] << " " << cost[i][1] <<'\n';
    //}
    
    int answer =0;
    for(int i=0; i<n; i++){
        int num_of_student_receiving_gifts=0;
        int tmp_cost = b;
        for(int j=0; j<n; j++){
            //i는 반값으로 만들 선물
            if(i==j){
                // 반값으로 했는데, 못 사면 넘어가
                int cost_i =cost[i][0]/2+cost[i][1];
                if(tmp_cost-cost_i <0) continue;
                // 구매 가능하다면 예산에서 빼고, 선물 수++
                tmp_cost-=cost_i;
                num_of_student_receiving_gifts++;
            }
            else{
                int cost_j =cost[j][0]+cost[j][1];
                if(tmp_cost-cost_j <0) continue;
                // 구매 가능하다면 예산에서 빼고, 선물 수++
                tmp_cost-=cost_j;
                num_of_student_receiving_gifts++;
            }
        }
        if(answer<num_of_student_receiving_gifts) answer=num_of_student_receiving_gifts;
    }

    cout << answer;
    return 0;
}