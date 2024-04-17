#include <iostream>

using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int answer =0;
    for(int i=0; i<n; i++){
        if(s[i]=='C'){
            
            for(int j=i+1; j<n; j++){
                if(s[j]=='O'){

                    for(int k=j+1;k<n;k++){
                        if(s[k]=='W') answer++;
                    }

                }
            }

        }
    }
    cout << answer;
    return 0;
}