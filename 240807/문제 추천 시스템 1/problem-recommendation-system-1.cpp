#include <iostream>
#include <set>

using namespace std;

struct Compare{
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const{
        if(lhs.second==rhs.second) return lhs.first<rhs.first;
        return lhs.second<rhs.second;
    }
};

// 문제리스트에서 문제를 출력
void PrintQuestion(set<pair<int,int>, Compare> &s){
    int x;
    cin >> x;

    if(x==1){
        // 문제 리스트에서 난이도가 가장 높은 문제의 번호를 출력
        // 난이도가 가장 높은 문제가 여러 개라면 문제 번호가 큰 것으로 출력
        pair<int,int> num = *s.rbegin();
        cout << num.first <<'\n';
    }
    else if(x==-1){
        // 문제 리스트에서 난이도가 가장 낮은 문제의 번호를 출력
        // 난이도가 가장 낮은 문제가 여러 개라면 문제 번호가 작은 것으로 출력
        pair<int,int> num = *s.begin();
        cout << num.first <<'\n';
    }
}
// 문제 리스트에 난이도가 L인 문제 번호 P를 추가
void AddQuestion(set<pair<int,int>, Compare> &s){
    int p, l; 
    cin >> p >> l;
    s.insert({p,l});
}

// 추천 문제 리스트에서 난이도가 L인 문제 번호 P를 제거
void DeleteQuestion(set<pair<int,int>, Compare> &s){
    int p, l; 
    cin >> p >> l;
    s.erase({p,l});
}

int main() {
    int n; // 추천 문제 리스트에 있는 문제의 개수 n
    cin >> n;

    set<pair<int,int>, Compare> question;
    for(int i=0; i<n; ++i){
        int p, l; // 문제 번호 P와 난이도 L
        cin >> p >> l;
        question.insert({p, l});
    }

    int m; //입력될 명령문의 개수 m
    cin >> m;
    while(m--){
        string command;
        cin >> command;
        if(command=="rc") PrintQuestion(question);
        if(command=="ad") AddQuestion(question);
        if(command=="sv") DeleteQuestion(question);
    }

    return 0;
}