#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> winner;
void Move(vector<int> &v, int velocity, int time){
    if(v.empty()) v.push_back(0);
    for(int i=0; i<time; i++){
        v.push_back(v[v.size()-1]+velocity);
    }
}

void Lead_Check(vector<int> v1, vector<int> v2){
    for(int i=1; i<v1.size(); i++){
        if(v1[i]>v2[i]) winner.push_back(1);
        else if(v2[i]>v1[i]) winner.push_back(2);
        else winner.push_back(0);
        if(winner[winner.size()-2]==winner[winner.size()-1]) winner.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int v, t;
        cin >> v >> t;
        Move(a, v, t);
    }
    for(int i=0; i<m; i++){
        int v, t;
        cin >> v >> t;
        Move(b, v, t);
    }
    Lead_Check(a, b);
    /*
    cout << "t\ta\tb\n======================\n";
    for(int i=0; i<a.size(); i++){
        cout << i << "\t" << a[i] << "\t" << b[i] <<'\n';
    }
    for(int i=0; i<winner.size(); i++){
        cout << winner[i] <<'\n';
    }
    */
    
    cout << winner.size();

    return 0;
}