#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
    int id;

    Node *prev, *next;
    Node(int id){
        this->id = id;
        prev = nullptr;
        next = nullptr;
    }
};

// i번 노드를 그 노드가 속해 있던 연결 리스트에서 뽑아서 단일 노드가 되게 함.
void PopNode(Node *node){
    // 1 2 3 이라고 하면 1과 3을 연결
    if (nullptr!=node->prev) node->prev->next = node->next;
    if (nullptr!=node->next) node->next->prev = node->prev;

    // 2 노드 연결 끊기
    node->prev = nullptr;
    node->next = nullptr;
}

// 단일 노드인 j번 노드를 i번 노드 앞에 삽입.
void InsertPrev(Node *i, Node *j){
    // 1 3에서 3 전에 2를 넣으려면 2->prev=1, 2->next=3 
    j->prev=i->prev;
    j->next=i;

    // 1 2랑 2 3도 연결해줘야 함
    if(nullptr!=j->prev) j->prev->next = j;
    if(nullptr!=j->next) j->next->prev = j;
}

// 단일 노드인 j번 노드를 i번 노드 뒤에 삽입.
void InsertNext(Node *i, Node *j){
    //1 2 4에서 2 뒤에 3을 넣으려면 3->next=2->next, 3->prev=2
    j->next=i->next;
    j->prev=i;

    if(nullptr!=j->prev) j->prev->next=j;
    if(nullptr!=j->next) j->next->prev=j;
    
}

// 이전 노드와 다음 노드의 번호를 출력(존재하지 않는다면, 0을 출력)
void PrintNeighboringNode(Node* node){
    if(nullptr!=node->prev) cout << node->prev->id << " ";
    else cout << 0 << " ";
    if(nullptr!=node->next) cout << node->next->id << " ";
    else cout << 0 << " ";
    cout <<'\n';
}

int main() {
    int n, q;
    cin >> n >> q;
    unordered_map<int, Node*> Nodes;

    // 1부터 n까지 차례로 번호가 붙어있는 n개의 단일노드 생성
    for(int i=1; i<=n; ++i){
        Nodes[i]= new Node(i);
    }

    while(q--){
        int command;
        cin >> command;
        if(command==1){
            int id;
            cin >> id;
            PopNode(Nodes[id]);
        }
        if(command==2){
            int prevId, currID;
            cin >> currID >> prevId;
            InsertPrev(Nodes[currID], Nodes[prevId]);
        }
        if(command==3){
            int nextId, currID;
            cin >>currID >> nextId;
            InsertNext(Nodes[currID], Nodes[nextId]);
        }
        if(command==4){
            int id;
            cin >> id;
            PrintNeighboringNode(Nodes[id]);
        }
    }
    // Q 개의 연산을 마친 후,
    // 1번부터 N번까지 각 노드의 다음 노드의 번호를 차례대로 한 줄에 출력
    for(int i=1; i<=n; ++i){
        if(nullptr!=Nodes[i]->next) cout << Nodes[i]->next->id << " ";
        else cout << 0 << " ";
    }
    return 0;
}