#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, int>> msg;
bool isRead[27];

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i=0; i<m; i++){
        char c;
        int u;
        cin >> c >> u;
        msg.push_back({c, u});
    }

    for(int i=p-1; i<m; i++){
        if(msg[i].second == 0){
            for(int j=0; j<n; j++){
                isRead[j]= true;
            }
            break;
        }
        
        int sender = msg[i].first -'A';
        isRead[sender] = true;
    }
    
    for(int i=0; i<n; i++){
        char reader = (char)i+'A';
        if(isRead[i]==false) cout << reader << " ";
    }

    return 0;
}