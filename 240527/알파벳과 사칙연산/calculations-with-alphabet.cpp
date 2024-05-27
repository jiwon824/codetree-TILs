#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

string expression;
vector<int> vecNum;
vector<char> vecAlpha;
int answer=INT_MIN;

// expression[i] i%2==0이면 알파벳, 1이면 연산자가 들어있음
void Calculate(){
    // expression의 알파벳을 숫자로 대치
    string newExpression = expression;
    for(int i=0; i<newExpression.length(); i+=2){
        for(int j=0; j<vecAlpha.size(); j++){
            if(newExpression[i]==vecAlpha[j]){
                newExpression[i]=(char)(vecNum[j]+'0');
                break;
            }
        }
    }
    //cout << newExpression <<'\n';
    
    int result =newExpression[0]-'0';
    for(int i=1; i<newExpression.length(); i+=2){
        int rhs = newExpression[i+1]-'0'; // right-hand side
        if(newExpression[i]=='+'){
            result += rhs;
        }
        else if(expression[i]=='-'){
            result-=rhs;
        }
        else{
            result*=rhs;
        }
    }
    if(answer<result) answer = result;
}

// 소문자 알파벳=1이상 4이하의 적절한 숫자
void ChangeAlphabetToNumber(int idx, int numOfAlpabets){
    // 종료 조건
    if(idx==numOfAlpabets){
        Calculate();
        return;
    }

    // 재귀호출
    for(int i=1; i<=4; i++){
        vecNum.push_back(i);
        ChangeAlphabetToNumber(idx+1, numOfAlpabets);
        vecNum.pop_back();
    }
}

int main() {
    cin >> expression;

    // expression에 몇 종류 알파벳 있는지 체크
    int numOfAlpabets=0;
    for(int i=0; i<expression.length(); i+=2){
        // 처음 보는 알파벳 (==vecAlpha에 expression[i]가 없음)이면
        if(find(vecAlpha.begin(), vecAlpha.end(), expression[i])==vecAlpha.end()){
            vecAlpha.push_back(expression[i]);
            numOfAlpabets++;
        }
    }

    ChangeAlphabetToNumber(0, numOfAlpabets);
    cout << answer << '\n';

    return 0;
}