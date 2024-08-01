#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // 수열1
    int n;
    cin >> n;
    unordered_set<int> us1;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        us1.insert(num);
    }

    // 수열2
    int m;
    cin >> m;
    int arr[100001]={0, };
    for(int i=0; i<m; ++i){
        cin >> arr[i];
    }
    
    // 수열 2의 원소의 순서대로 그 원소가 수열 1에 존재하는 원소인지
    for(int i=0; i<m; ++i){
        if(us1.find(arr[i])!=us1.end()) cout << "1 ";
        else cout << "0 ";
    }
    return 0;
}