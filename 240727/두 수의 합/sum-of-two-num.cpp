#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
unordered_map<int,int> uMap;

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        int key;
        cin >> key;
        uMap[key]++;
    }
    
    // solution
    int answer=0;
    for(auto it=uMap.begin(); it!=uMap.end(); ++it){
        int num=it->first;
        int findNum= k-num;

        // 같은 수를 2번 선택하는 경우 3 2\n 1 1 1의 경우 3이 되어야 함
        if(num==findNum){
            // 3개에서 2개 뽑는 경우 (3*2)/2
            answer+= (it->second * (it->second-1));
            cout << "same\n";
        }
        else{
            // 찾는 수가 있는 경우
            if(uMap.find(findNum)!=uMap.end()){
                // k=5일 때 num=3, findNum=2인 경우와 num=2, findNum=3인 경우 2번 계산됨
                answer+= (uMap[num] * uMap[findNum]);

            }
        }
    }

    // output
    cout << answer/2 <<'\n';
    return 0;
}