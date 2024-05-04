#include <iostream>
#include <vector>

using namespace std;

/*
      A    B    ans     
0s    0    0            3 L
1s   -1    1
2s   -2    2
3s   -3    3
4s   -2    4            5 R
5s   -1    3
6s    0    2
7s    1    1    V
8s    2    0
9s    1    1    V       1 L
10s   2    2            2 R
11s   3    3
12s   3    4            
13s   3    3    V
14s   3    2
*/

vector<int> a;
vector<int> b;

void Move(int move, char dir, vector<int> &v){
    int dir_num;
    if(dir=='L') dir_num = -1;
    else dir_num = 1; 

    for(int i=0; i<move; i++){
        if(v.empty()){
            v.push_back(dir_num);
        }
        else{
            v.push_back(v[v.size()-1]+dir_num);
        }
    }
}

// 마지막에 있던 원소를 채워 둘의 크기를 같게 만든다.
void Fill(vector<int> &v1, vector<int> &v2){
    if(v1.size()>v2.size()){
        while(v1.size()!=v2.size()){
            v2.push_back(v2[v2.size()-1]);
        }
    }
    else{
        while(v1.size()!=v2.size()){
            v1.push_back(v1[v1.size()-1]);
        }
    }
}

int Check(vector<int> v1, vector<int> v2){
    int cnt=0;
    for(int i=1; i<v1.size(); i++){
        if((v1[i-1]!=v2[i-1]) && (v1[i]==v2[i])) cnt++;
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int move;
        char dir;
        cin >> move >> dir;
        Move(move, dir, a);
    }

    for(int i=0; i<m; i++){
        int move;
        char dir;
        cin >> move >> dir;
        Move(move, dir, b);
    }

    Fill(a, b);

    cout << Check(a, b) <<'\n';
    /*
    cout << "A\n";
    for (int i=0; i<a.size(); i++){
        cout << i << "s " << a[i] << '\n';
    }
    cout << "B\n";
    for (int i=0; i<b.size(); i++){
        cout << i << "s " << b[i] << '\n';
    }
    */

    return 0;
}