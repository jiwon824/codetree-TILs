#include <iostream>
using namespace std;

const int MAX_N = 250001;
const int MAX_K = 101;

struct Node {
    int id;
    Node *prev, *next;

    Node(int id) : id(id), prev(nullptr), next(nullptr) {}
};

Node *nodes[MAX_N];
int heads[MAX_K];
int tails[MAX_K];

bool empty(int shelves_num){
    return heads[shelves_num]==0;
}

void Connect(Node *s, Node *e) {
    // s와 e를 이어줌
    if (nullptr != s) s->next = e;
    if (nullptr != e) e->prev = s;
}

/**
* 가장 앞에 있는 책을 삭제하고 반환하는 함수
* @param {shelves_num} 책꽂이 변호
* @returns 맨 앞에 있던 노드를 반환
*/
Node* pop_front(int shelves_num){
    Node *fNode=nodes[heads[shelves_num]];
    if(nullptr==fNode) return nullptr;
    
    // head노드의 다음 노드가 없으면 0 있으면 다음노드의 id를 새 head로
    if(nullptr==fNode->next) heads[shelves_num]=0;
    else heads[shelves_num]=fNode->next->id;

    fNode->next=nullptr;

    // head가 없다=empty라는 의미->꼬리도 비워준다.
    // 있다면 새로 바꾼 head의 prev를 null로
    if(heads[shelves_num]==0) tails[shelves_num]=0;
    else nodes[heads[shelves_num]]->prev = nullptr;

    return fNode;
}
/**
* 가장 뒤에 있는 책을 삭제하고 반환하는 함수
* @param {shelves_num} 책꽂이 변호
* @returns 맨 뒤에 있던 노드를 반환
*/
Node* pop_back(int shelves_num){
    Node *bNode=nodes[tails[shelves_num]];
    if(nullptr==bNode) return nullptr;

    if(nullptr==bNode->prev) tails[shelves_num]=0;
    else tails[shelves_num]=bNode->prev->id;

    bNode->prev=nullptr;

    if(tails[shelves_num]==0) heads[shelves_num]=0;
    else nodes[tails[shelves_num]]->next=nullptr;
    
    return bNode;
}

/**
* 앞에 삽입
* @param {shelves_num} 책꽂이 변호
* @param {u} 삽입할 노드
*/
void push_front(int shelves_num, Node* u){
    if(heads[shelves_num]==0){
        heads[shelves_num]=u->id;
        tails[shelves_num]=u->id;
    }
    else{
        Connect(u, nodes[heads[shelves_num]]);
        heads[shelves_num]=u->id;
    }
}
/**
* 뒤에 삽입
* @param {shelves_num} 책꽂이 변호
* @param {u} 삽입할 노드
*/
void push_back(int shelves_num, Node* u){
    if(tails[shelves_num]==0){
        heads[shelves_num]=u->id;
        tails[shelves_num]=u->id;
    }
    else{
        Connect(nodes[tails[shelves_num]], u);
        tails[shelves_num]=u->id;
    }
}

/**
 * 1 i j : i번 책꽂이의 맨 앞 책을 j번 책꽂이의 맨 뒤에 꽂습니다.
 * i번 책꽂이에 책이 아무것도 없다면, 무시합니다.
 */
void Func1(int a, int b){
    if(empty(a)) return;
    Node *fNode=pop_front(a);
    push_back(b, fNode);
}
/**
 * 2 i j : i번 책꽂이의 맨 뒷 책을 j번 책꽂이의 맨 앞에 꽂습니다.
 * i번 책꽂이에 책이 아무것도 없다면, 무시합니다.
 */
void Func2(int a, int b){
    if(empty(a)) return;
    Node *bNode = pop_back(a);
    push_front(b, bNode);
}

/**
 * 3 i j : i번 책꽂이의 책을 모두 j번 책꽂이의 맨 앞으로 옮깁니다. 
 * 각 책꽂이에 책이 꽃혀 있던 순서는 유지되어야 합니다.
 */
void Func3(int a, int b){
    if(a==b || empty(a)) return;

    if(empty(b)){
        heads[b]=heads[a];
        tails[b]=tails[a];
    }
    else{
        Connect(nodes[tails[a]], nodes[heads[b]]);
        heads[b]=heads[a];
    }
    
    heads[a]=0;
    tails[a]=0;
}
/**
 * 4 i j : i번 책꽂이의 책을 모두 j번 책꽂이의 맨 뒤로 옮깁니다. 
 * 각 책꽂이에 책이 꽃혀 있던 순서는 유지되어야 합니다.
 */
void Func4(int a, int b){
    if(a==b || empty(a)) return;
    if(empty(b)){
        heads[b]=heads[a];
        tails[b]=tails[a];
    }
    else{
        Connect(nodes[tails[b]], nodes[heads[a]]);
        tails[b]=tails[a];
    }

    heads[a]=0;
    tails[a]=0;
}

int main() {
    int n, k;
    cin >> n >> k;
    // 노드 생성
    for(int i=1; i<=n; ++i){
        nodes[i] = new Node(i);
    }
    // 노드 연결
    for(int i=1; i<n; ++i){
        Connect(nodes[i], nodes[i+1]);
    }
    heads[1]=1, tails[1]=n;

    int q;
    cin >> q;
    // q개의 연산이 주어짐
    while(q--){
        int command, a, b;
        cin >> command >> a >> b;
        if(command==1) Func1(a, b);
        else if(command==2) Func2(a, b);
        else if(command==3) Func3(a, b);
        else if(command==4) Func4(a, b);
    }

    // 최종 줄의 상태
    for(int i=1; i<=k; ++i){
        int cnt=0;
        Node *cur=nodes[heads[i]];
        while(nullptr!=cur){
            cnt++;
            cur = cur->next;
        }

        cout << cnt << " ";
        cur=nodes[heads[i]];
        while(nullptr!=cur){
            cout << cur->id << " ";
            cur = cur->next;
        }
        cout <<'\n';
    }
    return 0;
}