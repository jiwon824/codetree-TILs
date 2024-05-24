#include <iostream>
#include <vector>

using namespace std;

int line[16][2];
vector<int> comb;
int visited[16];
int n;
int answer;

// 겹치는 선분이 있다면 -1 저장 +갱신x, 겹치는 선분이 없다면 선분의 갯수를 갱신
void Check_lines(){
    int line_check[1001]={0, };
    bool possible = true;
    int size = (int)comb.size();

    for(int i=0; i<size; i++){
        for(int j=line[comb[i]][0]; j<=line[comb[i]][1]; j++){
            line_check[j]++;
            // 2이상=겹친다는 뜻
            if(line_check[j]>=2) {
                possible=false;
                break;
            }
        }
        if(possible==false) break;
    }

    if(possible && answer<size) answer=size;
    return;
}

// n=3일 경우 0, 1, 2, (0,1)(0,2)(1,2), (0,1,2) 7가지 경우를 모두 살펴봐야 한다
void Choose_line(int curr_line){
    //cout <<"Choose_line()\n";
    //종료 조건
    if(curr_line==n){
        Check_lines();
        return;
    }
    
    //재귀 호출
    for(int i=0; i<n; i++){
        if(visited[i]!=0) continue;

        comb.push_back(i);
        visited[i]=1;
        Choose_line(curr_line+1);

        comb.pop_back();
        visited[i]=0;
        Choose_line(curr_line+1);
    }
    
    
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> line[i][0] >> line[i][1];
    }

    Choose_line(0);
    cout << answer;
    return 0;
}