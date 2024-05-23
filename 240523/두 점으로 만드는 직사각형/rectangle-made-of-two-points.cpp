#include <iostream>

using namespace std;

int main() {
    // 1은 왼쪽 하단의 점, 2는 오른쪽 상단의 점
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    
    int max_x, max_y, min_x, min_y;
    max_x = max(x2, a2);
    max_y = max(y2, b2);
    min_x = min(x1, a1);
    min_y = min(y1, b1);
    
    cout << (max_x-min_x) * (max_y-min_y);

    return 0;
}