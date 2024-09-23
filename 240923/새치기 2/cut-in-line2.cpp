#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 11;

struct Node {
    string name;
    Node *prev, *next;

    Node(string name) : name(name), prev(nullptr), next(nullptr) {}
};

// name으로 id를 찾고 um[name]=id가 나옴
// nodes[id].first=line_num, second=node 
// heads[line_num]==node로 head인지 아닌지 알 수 있음(tails도 마찬가지)
pair<int, Node*> nodes[MAX_N]; // nodes[id]={line_num, node}
unordered_map<string, int> name_id; // {name, id} i번째 사람
Node *heads[MAX_M], *tails[MAX_M]; //line_num번째의 head와 tail

int n, m, q;

void Connect(Node *s, Node *e){
    if(s) s->next=e;
    if(e) e->prev=s;
}

void MakeNodeNConnect(){
    int line_capacity = n/m;
    // i번째 줄
    int id=1;
    for(int i=1; i<=m; ++i){
        Node *prev = nullptr;
        // i개의 줄에 line_capacity(n/m)만큼의 사람이 줄 서게 된다.
        for(int j=1; j<=line_capacity; ++j){
            string name;
            cin >> name;

            // 각 줄에 노드를 생성하고 연결
            Node *newNode= new Node(name);
            nodes[id]={i, newNode}; // arr[id]=(line_num, node)
            name_id[name]=id; // unordered_map[name]=id
            
            // head, tail 설정
            if(j==1) heads[i]=newNode;
            if(j==line_capacity) tails[i]=newNode;

            Connect(prev, newNode);
            prev=newNode;
            id++;
        }
    }
}

/**
* 1 a b : 이름이 a 인 사람이 이름이 b 인 사람 앞으로 새치기
*/
void Func1(string a, string b){
    int line_a=nodes[name_id[a]].first, line_b=nodes[name_id[b]].first;
    Node *node_a=nodes[name_id[a]].second, *node_b=nodes[name_id[b]].second;
    
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
    nodes[name_id[a]].first=line_b;
}

/**
* 2 a : 이름 a 인 사람 삭제
*/
void Func2(string a){
    int line_num=nodes[name_id[a]].first;
    Node *node=nodes[name_id[a]].second;

    Connect(node->prev, node->next);
    node->prev = node->next = nullptr;
    nodes[name_id[a]].first=0; // 집에 갔으므로 a의 line=0

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
* 3 a b c : 이름 a 부터 이름 b 인 사람이 통째로 이름 c 인 사람 앞으로 새치기
*/
void Func3(string a, string b, string c){
    int line_a=nodes[name_id[a]].first, line_b=nodes[name_id[b]].first, line_c = nodes[name_id[c]].first;
    Node *node_a=nodes[name_id[a]].second, *node_b=nodes[name_id[b]].second, *node_c=nodes[name_id[c]].second;
    
    //line_a={a, ..., b}인 경우
    if (heads[line_a]==node_a && tails[line_a]==node_b) {
        heads[line_a] = tails[line_a] = nullptr;
    }
    // node_a가 head인 경우
    if(heads[line_a]==node_a) heads[line_a]=node_b->next;
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
        // name_id[cur->name]: 현재 노드의 이름으로 id찾기
        // nodes[id].first: id번째 노드= {line_num, node}
        nodes[name_id[cur->name]].first=line_c;
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

        // heads[i]: i번째 줄의 head 노드
        Node *cur=heads[i];

        // i번 줄에 있는 사람들을 맨 앞에서부터 차례대로 공백을 사이에 두고 출력
        while(nullptr!=cur){
            cout << cur->name << " ";
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
        else cout << node->name << " ";
    }
    cout << "\n\n";

    cout << "===== [tails] =====\n";
    for(int i=1; i<=m; ++i){
        Node *node=tails[i];
        if(!node) cout << -1 << " ";
        else cout << node->name << " ";
    }
    cout << "\n\n";

    cout << "===== [Node State] =====\n";
    for(int i=1; i<=n; ++i){
        int line_num = nodes[i].first;
        Node *node=nodes[i].second;
        if(!node) node = new Node("-1");
        Node *prev = node->prev, *next=node->next;

        // 로그를 찍기 위해 null이라면 -1 id를 가진 Node 저장
        if(!prev) prev = new Node("-1");
        if(!next) next = new Node("-1");

        cout << "[line]: " << line_num << '\n';
        cout <<"[Node]: " << prev->name << " <- " << node->name << " -> " << next->name << '\n';
        cout << '\n';
    }
}
int main() {
    // input
    cin >> n >> m >> q;
    MakeNodeNConnect();
    
    // q개의 연산
    while(q--){
        int option;
        cin >> option;
        if(option==1){
            string a, b;
            cin >> a >> b;
            Func1(a, b);
        }
        else if(option==2){
            string a;
            cin >> a;
            Func2(a);
        }
        else if(option==3){
            string a, b, c;
            cin >> a >> b >> c;
            Func3(a, b, c);
        }
    }

    
    // 최종 줄의 상태 출력
    //PrintLog();
    PrintAnswer();

    return 0;
}