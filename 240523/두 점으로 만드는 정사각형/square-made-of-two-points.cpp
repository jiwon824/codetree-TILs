#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int max_x, max_y, min_x, min_y;
    max_x = max(x2, a2);
    max_y = max(y2, b2);
    min_x = min(x1, a1);
    min_y = min(y1, b1);

    int side = max((max_x-min_x), (max_y-min_y));

    cout << side*side <<'\n';
    return 0;
}