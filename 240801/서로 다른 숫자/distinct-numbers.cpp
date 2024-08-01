#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> us;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        us.insert(num);
    }
    
    cout << us.size() <<'\n';
    return 0;
}