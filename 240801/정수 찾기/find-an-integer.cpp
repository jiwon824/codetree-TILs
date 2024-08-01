#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // 수열 a의 원소
    int n;
    cin >> n;
    unordered_set<int> us;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        us.insert(num);
    }

    // 수열 b
    int m;
    cin >> m;
    int arr[100001]={0, };
    for(int i=0; i<m; ++i){
        cin >> arr[i];
    }

    // m개의 줄에 걸쳐 수열 b의 원소가 a에 포함되는지
    for(int i=0; i<m; ++i){
        if(us.find(arr[i])!=us.end()) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}