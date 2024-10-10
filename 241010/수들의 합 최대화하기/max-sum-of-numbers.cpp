#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 11;

int n, answer;
int arr[MAX_N][MAX_N];
bool visited[MAX_N]={false, };
vector<int> picked;


void FindMax(int row) {
    if(row==n){
        int sum=0;
        for(int i=0; i<n; ++i){
            int col = picked[i];
            sum += arr[i][col];
        }
        answer = max(answer, sum);
    }
    
    //선택할 열
    for(int i=0; i<n; ++i){
        if(visited[i]) continue;
        visited[i]=true;
        picked.push_back(i);

        FindMax(row+1);

        visited[i] = false;
        picked.pop_back();
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }

    FindMax(0);

    cout << answer << '\n';
    return 0;
}