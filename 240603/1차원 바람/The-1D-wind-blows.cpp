#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //memset

using namespace std;

int n, m, q;
int building[101][101]; // N*M 행렬 모양의 건물
int visited[101]; // 방문한 행을 체크하는 배열
vector<pair<int, char>> wind;
vector<pair<int, char>> propagatedWind;

void GetInput(){
    cin >> n >> m >> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> building[i][j];
        }
    }
    for (int i=0; i<q; i++){
        int x;
        char dir;
        cin >> x >> dir;
        wind.push_back({--x, dir}); // 1<=x<=n이기 때문에 1을 뺀 후 벡터에 넣어줌
    }
}

void PrintArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << building[i][j] << " ";
        }
        cout <<'\n';
    }
}

void Propagation(int row, char dir){
    if (dir=='L') dir ='R';
    else dir='L';

    // 중복으로 들어가면 안 되니까
    bool upSignal =false, downSignal = false;
    for(int i=0; i<m; i++){
        if(row-1>=0 && building[row][i]==building[row-1][i])
            upSignal=true;
        if(row+1<n && building[row][i]==building[row+1][i])
            downSignal=true;
    }

    if(upSignal && visited[row-1]==0) propagatedWind.push_back({row-1, dir});
    if(downSignal && visited[row+1]==0) propagatedWind.push_back({row+1, dir});
}


void ShiftArr(int row, char dir){
    //cout << "ShiftArr" << row << " "<< dir << '\n';
    visited[row] = 1;
    if(dir=='L'){
        int lastElement = building[row][m-1];
        for(int i=m-1; i>0; i--){
            building[row][i]= building[row][i-1];
        }
        building[row][0] = lastElement;
    }
    else{
        int firstElement = building[row][0];
        for(int i=0; i<m-1; i++){
            building[row][i]= building[row][i+1];
        }
        building[row][m-1] = firstElement;
    }
    //PrintArr();
}

void WindStart(){
    for(int i=0; i<wind.size(); i++){
        memset(visited, 0, sizeof(int)*n);

        int row = wind[i].first;
        char dir = wind[i].second;
        ShiftArr(row, dir); // 첫 바람
        Propagation(row, dir); // 전파 시키기

        while(!propagatedWind.empty()){
            row = propagatedWind.back().first;
            dir = propagatedWind.back().second;
            propagatedWind.pop_back();
            ShiftArr(row, dir);
            Propagation(row, dir);
        }
    }
}


int main() {
    GetInput();
    
    WindStart();

    PrintArr();
    return 0;
}