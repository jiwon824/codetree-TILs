#include <iostream>
using namespace std;

const int MAX_N=100001;

struct Node {
    string name;
    Node *prev, *next;

    Node(string name) : name(name), prev(nullptr), next(nullptr) {}
};


Node *nodes[MAX_N];

void Connect(Node *s, Node *e){
    if(s) s->next=e;
    if(e) e->prev=s;
}

void Insert_right(Node *cur, Node *target){
    Node *AfterNextTarget=cur->next;
    Connect(cur, target);
    Connect(target, AfterNextTarget);
}

void Pop_right(Node *e){
    Connect(e->prev, e->next);
}

void printNode(Node *target) {
    // 왼쪽과 오른쪽에 있는 도시가 존재하지 않는 경우
    if(nullptr==target->prev || nullptr==target->next) {
        cout << "-1\n";
        return;
    }
    // 만약 왼쪽과 오른쪽에 있는 스티커가 붙어 있는 도시의 이름이 같은 경우
    if(target->prev->name==target->next->name){
        cout << "-1\n";
        return;
    }

    cout << target->prev->name << " " << target->next->name << '\n';
}

int main() {
    int n, q;
    cin >> n >> q;
    // 노드 생성
    for(int i=1; i<=n; ++i){
        string name;
        cin >> name;
        nodes[i] = new Node(name);
    }
    // 노드 연결
    for(int i=1; i<n; ++i){
        Connect(nodes[i], nodes[i+1]);
    }
    Connect(nodes[n], nodes[1]);

    // 맨 처음 주어진 도시가 핀셋이 꽂혀있는 도시
    Node *cur=nodes[1];
    while(q--){
        int option;
        cin >> option;
        if(option==1){
            if(cur->next) cur=cur->next;
        }
        else if(option==2){
            if(cur->prev) cur=cur->prev;
        }
        else if(option==3){
            if(cur->next) Pop_right(cur->next);
        }
        else if(option==4){
            string a;
            cin >> a;
            Insert_right(cur, new Node(a));
        }
        printNode(cur);
    }

    return 0;
}