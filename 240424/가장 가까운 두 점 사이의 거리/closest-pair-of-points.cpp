#include <iostream>
#include <climits>
using namespace std;

int coordinates[100][2];
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> coordinates[i][0] >> coordinates[i][1];
    }

    int answer = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            if(i==j) continue; // i랑 j가 같은 점이면 continue
            int x1 = coordinates[i][0], y1= coordinates[i][1], x2 = coordinates[j][0], y2 = coordinates[j][1];
            int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            if(dist<answer) answer=dist;
        }
    }
    cout << answer;
    return 0;
}