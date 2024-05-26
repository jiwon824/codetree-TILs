#include <iostream>
#include <vector>

using namespace std;

int n, m, c, value;
int WeightOfObjects[11][11];
vector<int> selected;

// (x, y)~(x, y+m)구간에서 무게c이하의 조합
void SelectObj(int x, int y, int numOfItem){
    //종료조건
    if(numOfItem==m){
        //cout << "select end\n";
        int sum =0, newValue =0;
        for(auto e : selected){
            int weight = WeightOfObjects[x][y+e];
            sum+= weight;
            newValue += weight * weight;
            //cout <<e << " "<< newValue <<'\n';
            if(sum>c) return;
        }
        if (value<newValue) value = newValue;
        return;
    }
    
    selected.push_back(numOfItem);
    SelectObj(x, y, numOfItem+1); //numOfItem을 넣은 경우

    selected.pop_back();
    SelectObj(x, y, numOfItem+1); //numOfItem을 뺀 경우
}

int ChooseRegions(){
    int answer =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=n-m; j++){
            //도둑1: (i, j)~(i, j+m)까지 구간
            for(int k=i; k<n; k++){
                for(int l=j; l<=n-m; l++){
                    // 도둑2: (k, l)~(k, l+m)까지 구간 잡기
                    if(i==k && (j<=l && l<j+m)) continue; // 같은 행인데, 열이 겹치는 경우

                    value=0; // value 초기화
                    int tmp_val =0;
                    SelectObj(i, j, 0); // 도둑1: (i, j)구간에서 최대 가치
                    tmp_val+=value;

                    value=0; // value 초기화
                    SelectObj(k, l, 0); // 도둑2: (k, l)구간에서 최대 가치
                    tmp_val+=value;

                    //cout << i << " " << j << " " << k << " " << l << " " << tmp_val <<'\n';
                    if(answer<tmp_val) answer = tmp_val;
                }
            }
        }
    }
    return answer;
}

int main() {
    cin >> n >> m >> c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> WeightOfObjects[i][j];
        }
    }
    
    cout << ChooseRegions() <<'\n';
    return 0;
}