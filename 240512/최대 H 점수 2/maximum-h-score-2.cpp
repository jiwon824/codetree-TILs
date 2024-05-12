#include <iostream>
#include <vector>

using namespace std;

int arr[101];
int visited[101];
vector<int> comb;
int n, l;
int answer;

int Check_Score(){
    // arr[comb[i]]++해주기
    for(int i=0; i<comb.size(); i++){
        arr[comb[i]]++;
    }

    int num_of_score=0;
    for(int i=0; i<101; i++){
        int num_of_i=0;
        for(int j=0; j<n; j++){
            if(arr[j]>=i) num_of_i++;
        }
        //cout << num_of_i << '\n';
        // i이상인 수의 갯수가 i개 이상이면서 num_of_score<i라면 num_of_score 갱신
        if(num_of_i>=i && num_of_score<i) num_of_score=i; 
    }

    // arr[comb[i]]-- 원상복구
    for(int i=0; i<comb.size(); i++){
        arr[comb[i]]--;
    }
    return num_of_score;
}
void Make_Comb(int curr_num){
    if(curr_num==l){
        //for(auto e : comb){
        //    cout << e << " ";
        //}
        //cout << '\n';

        int score = Check_Score();
        if(answer<score) answer=score;
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;

        comb.push_back(i);
        visited[i]=1;
        Make_Comb(curr_num+1);
        comb.pop_back();
        visited[i]=0;
    }
}

int main() {
    cin >> n >> l;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    Make_Comb(0);
    cout << answer;
    return 0;
}