#include <iostream>
#include <vector>

using namespace std;

int a[101]; // 수열a
int b[101]; // 수열b

int visited[101];
vector<int> v; // b수열을 이용한 조합
vector<vector<int>> duplicate_Check;

int n, m, answer;

/*
5 3
4 5 4 4 5
4 5 4
의 경우 [4, 5, 4] [5, 4, 4] [4, 4, 5] 3개가 있다.
*/

int Check_Beauty(){
    // a수열에 v 조합이 몇 개 들어있는지
    int num_of_v_in_a =0;
    // a의 원소가 5개, b의 원소가 3개라면
    // a-b+1 = 5-3+1 =3 3개씩 검사해야 하니까
    for(int i=0; i<n-m+1;i++){
        bool beauty = true;
        for(int j=i; j<i+m; j++){
            if (a[j]!=v[j-i]) beauty = false;
        }
        if(beauty) num_of_v_in_a++;
    }
    return num_of_v_in_a;
}

// 수열 b에 들어간 숫자를 이용하여 
void Make_comb(int curr_num){
    // 종료 조건
    if(curr_num==m){
        // 중복체크
        for (int i=0; i<duplicate_Check.size(); i++){
            bool isSame = true;
            for(int j=0; j<duplicate_Check[0].size(); j++){
                if(v[j]!=duplicate_Check[i][j]) isSame = false;
            }
            // 같은 걸 찾았다
            if(isSame) return;
        }
        // 위에서 return되지 않았다는 것은 v가 duplicate_Check에 없었다는 뜻

        //for(auto e : v){
        //    cout << e << " ";
        //}
        //cout <<'\n';
        duplicate_Check.push_back(v);
        int num_of_beauty = Check_Beauty();
        answer += num_of_beauty;
        return;
    }

    // 재귀 호출
    for(int i=0; i<m; i++){
        if(visited[i])continue; //방문했던 idx는 다시 방문하지 않음

        // v에 원소를 넣고 방문 체크
        v.push_back(b[i]);
        visited[i]++;
        Make_comb(curr_num+1);
        // v에서 원소 제거->방문 체크 해제
        v.pop_back();
        visited[i]--;
    }
    
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    for(int i=0; i<m; i++){
        cin>> b[i];
    }

    // n<m이라면 a에서 길이가 m인 연속 부분 수열이 있을 수 없음
    if(n<m) cout << "0";
    else{    
        Make_comb(0);
        cout << answer;
    }
    return 0;
}