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
        string first, second;
        // num에 포함된 숫자가 홀수개인 경우
        // 34543 같은 경우 5개의 숫자로 이루어짐 5/2=2
        if(num.length()%2 != 0){
            for(int j=0; j<num.length()/2; j++){
                first = first+num[j];
            }
            for(int j=num.length()/2+1; j<num.length(); j++){
                second = second+num[j];
            }
            reverse(second.begin(), second.end());
        }
        else{
            for(int j=0; j<num.length()/2; j++){
                first = first+num[j];
            }
            for(int j=num.length()/2; j<num.length(); j++){
                second = second+num[j];
            }
            reverse(second.begin(), second.end());
        }
        bool isAnswer = true;
        for(int j=0; j<first.length(); j++){
            if(first[j]!=second[j]) {
                isAnswer=false;
                break;    
            }
        }
        if(isAnswer) answer++;
    }
    cout << answer;
    return 0;
}