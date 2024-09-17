#include <iostream>
using namespace std;

const int MAX_N = 101;

int n;
int graph[MAX_N][MAX_N];

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> graph[i][j];
        }
    }

    // solution
    // i->i로는 반드시 갈 수 있음
    for(int i=0; i<n; ++i){
        graph[i][i] = 1;
    }
    
    // k를 거쳐서 가는 방법 체크
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                // i->k->j로 갈 수 있으면 1 
                if(graph[i][k]==1 && graph[k][j]==1) graph[i][j]=1;
            }
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}