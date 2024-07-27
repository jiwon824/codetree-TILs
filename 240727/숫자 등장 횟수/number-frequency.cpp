#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int,int> uMap; // key는 원소, value는 원소의 개수

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        
        if(uMap.find(num)==uMap.end()) uMap[num]=1; // 없으면 추가
        else uMap[num] = (uMap.find(num)->second)+1;
    }

    for(int i=0; i<m; ++i){
        int findNum;
        cin >> findNum;
        if(uMap.find(findNum)==uMap.end()) cout << "0 ";
        else cout << uMap.find(findNum)->second << " ";
    }
    return 0;
}