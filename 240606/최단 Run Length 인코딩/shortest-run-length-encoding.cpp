#include <iostream>
#include <climits>

using namespace std;


int RunLengthEncoding(string str){
    string result;
    char c= str[0];
    int cnt=1, size = str.length();

    for(int i=1; i<size; i++){
        if(str[i]!=c){
            result=result+c+to_string(cnt);
            c=str[i];
            cnt=1;
        }
        else cnt++;
    }
    if(cnt>1 || str[size-1]!=str[size-2]) result=result+c+to_string(cnt);

    return result.length();
}
int ShiftStr(string str){
    int answer=INT_MAX, size=str.length();

    for(int i=0; i<size; i++){
        //right shift
        int lastElement = str[size-1];
        for(int j=size; j>0; j--){
            str[j]= str[j-1];
        }
        str[0]= lastElement;

        //compare
        answer = min(answer, RunLengthEncoding(str));
    }
    return answer;
}

int main() {
    string inputStr;
    cin >> inputStr;

    cout << ShiftStr(inputStr);
    return 0;
}