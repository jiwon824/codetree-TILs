#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 11;

struct Node {
    int id;
    Node *prev, *next;

    Node(int id) : id(id), prev(nullptr), next(nullptr) {}
};

pair<int, Node*> nodes[MAX_N]; // node[id]={line_num, node}
Node *heads[MAX_M], *tails[MAX_M]; //line_num번째의 head와 tail

int n, m, q;

void Connect(Node *s, Node *e){
    if(s) s->next=e;
    if(e) e->prev=s;
}

void MakeNodeNConnect(int line_num, int size){
    Node* prev = nullptr;
    // 노드 생성
    for(int i=0; i<size; ++i) {
        int num;
        cin >> num;

        // 노드 생성 및 저장
        Node *node = new Node(num);
        nodes[num] = {line_num, node};
        
        // head, tail 설정
        if(i==0) heads[line_num]=node;
        if(i==size-1) tails[line_num]=node;

        // 노드 연결
        Connect(prev, node);
        prev=node;
    }
}

/**
* 1 a b : 번호 a 인 사람이 번호 b 인 사람 앞으로 새치기
*/
void Func1(int a, int b){
    int line_a=nodes[a].first, line_b=nodes[b].first;
    Node *node_a=nodes[a].second, *node_b=nodes[b].second;
    
    //line_a에 노드 a밖에 없는 경우
    if (heads[line_a]==tails[line_a]) {
        heads[line_a] = tails[line_a] = nullptr;
    }
    else{
        // node_a가 head인 경우
        if (heads[line_a]==node_a && node_a->next) heads[line_a] = node_a->next;
        // node_a가 tail인 경우
        if(tails[line_a]==node_a && node_a->prev) tails[line_a]=node_a->prev;
    }

    // node_b가 head인 경우
    if(heads[line_b]==node_b) heads[line_b]=node_a;

    // node_a pop
    Connect(node_a->prev, node_a->next);

    // a랑 b 연결
    Connect(node_b->prev, node_a);
    Connect(node_a, node_b);

    // a를 b라인으로 이동함
    nodes[a].first=nodes[b].first;
}

/**
* 2 a : 번호 a 인 사람이 집으로 갔습니다.
*/
void Func2(int a){
    int line_num=nodes[a].first;
    Node *node=nodes[a].second;

    Connect(node->prev, node->next);
    node->prev = node->next = nullptr;
    nodes[a].first=0; // 집에 갔으므로 a의 line=0

    // a가 head인 경우
    if(heads[line_num]==node){
        heads[line_num]=node->next;
    }
    // a가 tail인 경우
    if(tails[line_num]==node){
        tails[line_num]=node->prev;
    }
}

/**
* 3 a b c : 번호 a 부터 번호 b 인 사람이 통째로 번호 c 인 사람 앞으로 새치기
* 번호 a 인 사람부터 번호 b 까지인 사람의 순서는 유지됩니다.
*/
void Func3(int a, int b, int c){
    int line_a = nodes[a].first,line_b = nodes[b].first, line_c = nodes[c].first;
    Node *node_a=nodes[a].second, *node_b=nodes[b].second, *node_c=nodes[c].second;
    
    //line_a={a, ..., b}인 경우
    if (heads[line_a]==node_a && tails[line_a]==node_b) {
        heads[line_a] = tails[line_a] = nullptr;
    }
    // node_a가 head인 경우
    if(heads[line_a]==node_a) heads[line_a]=node_a->next;
    // node_b가 tail인 경우
    if(tails[line_b]==node_b) tails[line_b]=node_a->prev;
    // node_c가 head인 경우
    if(heads[line_c]==node_c) heads[line_c]=node_a;

    Connect(node_a->prev, node_b->next);
    Connect(node_c->prev, node_a);
    Connect(node_b, node_c);

    // a부터 b까지 line을 c로 변경
    Node *cur=node_a;
    while(cur!=node_b->next){
        nodes[cur->id].first=line_c;
        cur=cur->next;
    }
}

void PrintAnswer(){
    for(int i=1; i<=m; ++i){
        // 해당 줄에 사람이 없다면, -1을 출력
        if(heads[i]==nullptr){
            cout << -1 << '\n';
            continue;
        }

        // heads[i]: i번째 줄의 head 노드의 id
        // node[id]={line_num, node}
        Node *cur=nodes[heads[i]->id].second;

        // i번 줄에 있는 사람들을 맨 앞에서부터 차례대로 공백을 사이에 두고 출력
        while(nullptr!=cur){
            cout << cur->id << " ";
            cur=cur->next;
        }
        cout <<'\n';
    }
}

// 로그 찍기용 함수
void PrintLog(){
    cout << "===== [heads] =====\n";
    for(int i=1; i<=m; ++i){
        Node *node=heads[i];
        if(!node) cout << -1 << " ";
        else cout << node->id << " ";
    }
    cout << "\n\n";

    cout << "===== [tails] =====\n";
    for(int i=1; i<=m; ++i){
        Node *node=tails[i];
        if(!node) cout << -1 << " ";
        else cout << node->id << " ";
    }
    cout << "\n\n";

    cout << "===== [Node State] =====\n";
    for(int i=1; i<=n; ++i){
        int line_num = nodes[i].first;
        Node *node=nodes[i].second;
        Node *prev = node->prev, *next=node->next;

        // 로그를 찍기 위해 null이라면 -1 id를 가진 Node 저장
        if(!prev) prev = new Node(-1);
        if(!next) next = new Node(-1);

        cout << "[line]: " << line_num << '\n';
        cout <<"[Node]: " << prev->id << " <- " << node->id << " -> " << next->id << '\n';
        cout << '\n';
    }
}

int main() {
    // input
    cin >> n >> m >> q;
    for(int i=1; i<=m; ++i){
        int size;
        cin >> size;
        // 각 줄에 노드를 생성하고 연결
        MakeNodeNConnect(i, size);
    }

    // q개의 연산
    while(q--){
        int option;
        cin >> option;
        if(option==1){
            int a, b;
            cin >> a >> b;
            Func1(a, b);
        }
        else if(option==2){
            int a;
            cin >> a;
            Func2(a);
        }
        else if(option==3){
            int a, b, c;
            cin >> a >> b >> c;
            Func3(a, b, c);
        }
    }

    
    // 최종 줄의 상태 출력
    //PrintLog();
    PrintAnswer();
    return 0;
}