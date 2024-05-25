#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
int n, m;
int board[16][12];
vector<pair<int, int>> lines;
int answer = INT_MAX;
vector<int> originResult;
// 두 결과를 비교하는 함수
bool isPossible(const vector<int>& result) {
    return result == originResult;
}
// 보드를 만드는 함수
void makeBoard(const vector<pair<int, int>>& currentLines) {
    memset(board, 0, sizeof(board));
    for (const auto& line : currentLines) {
        board[line.second - 1][line.first - 1] = 1;
        board[line.second - 1][line.first] = 1;
    }
}
// 사다리 타기를 시뮬레이션하는 함수
vector<int> play(const vector<pair<int, int>>& currentLines) {
    makeBoard(currentLines);
    vector<int> result(n);
    for (int player = 0; player < n; player++) {
        int posX = 0, posY = player;
        while (posX < 15) {
            if (board[posX][posY] == 1) {
                if (posY + 1 < n && board[posX][posY + 1] == 1) {
                    posY++;
                } else if (posY - 1 >= 0 && board[posX][posY - 1] == 1) {
                    posY--;
                }
            }
            posX++;
        }
        result[posY] = player;
    }
    return result;
}
// 최소 가로줄을 찾는 함수
void findMinLineSegments(int idx, vector<pair<int, int>>& currentLines) {
    if (idx == lines.size()) {
        vector<int> currentResult = play(currentLines);
        if (isPossible(currentResult)) {
            answer = min(answer, static_cast<int>(currentLines.size()));
        }
        return;
    }
    // 현재 가로줄을 추가하지 않는 경우
    findMinLineSegments(idx + 1, currentLines);
    // 현재 가로줄을 추가하는 경우
    currentLines.push_back(lines[idx]);
    findMinLineSegments(idx + 1, currentLines);
    currentLines.pop_back();
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        lines.emplace_back(a, b);
    }
    vector<pair<int, int>> emptyLines;
    originResult = play(lines);
    findMinLineSegments(0, emptyLines);
    cout << answer << endl;
    return 0;
}