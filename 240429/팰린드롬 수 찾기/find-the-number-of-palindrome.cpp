#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    int x, y;
    cin >> x >> y;

    int answer = 0;
    for(int i=x; i<=y; i++){
        string num = to_string(i);
        string reverse_num = num;
        reverse(reverse_num.begin(), reverse_num.end());
        
        bool isAnswer = true;
        for(int j=0; j<num.length(); j++){
            if(num[j]!=reverse_num[j]) {
                isAnswer=false;
                break;    
            }
        }
        if(isAnswer) answer++;
    }
    cout << answer;
    return 0;
}