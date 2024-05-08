#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    int a1, b1, a2, b2;
    //input
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    // 겹치지 않는 경우1(상하1)
    bool isOverlap =true;
    if(y1>b2 || b1>y2) isOverlap=false;
    if(x2<a1 || a2 <x1) isOverlap=false;

    // output
    if(isOverlap) cout << "overlapping";
    else cout << "nonoverlapping";
    return 0;
}