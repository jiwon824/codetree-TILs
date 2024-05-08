#include <iostream>

using namespace std;

int line[101][2];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin>> line[i][0] >> line[i][1];
    }
    
    bool isOverlap = true;
    for(int i=1; i<n; i++){
        if(line[i-1][1]<line[i][0] || line[i-1][0]>line[i][1]) isOverlap = false;
    }
    if(isOverlap) cout << "Yes";
    else cout << "No";
    return 0;
}