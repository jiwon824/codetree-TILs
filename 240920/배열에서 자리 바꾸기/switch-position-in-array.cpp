#include <iostream>
using namespace std;

const int MAX_N = 250000;
// 한 노드를 나타내는 구조체
struct Node {
    int id;
    Node *prev, *next;

    Node(int id) : id(id), prev(nullptr), next(nullptr) {}
};

Node *nodes[MAX_N] = {};

void Connect(Node *s, Node *e) {
    // s와 e를 이어줌
    if (nullptr != s) s->next = e;
    if (nullptr != e) e->prev = s;
}

void SwapRange(Node *a, Node *b, Node *c, Node *d){
    Node *after_ap=c->prev;
    Node *after_bn=d->next;

    Node *after_cp=a->prev;
    Node *after_dn=b->next;

    //b와 c가 붙어있는 경우
    if(b->next==c){
        after_ap=d;
        after_dn=a;
    }
    if(d->next==a){
        after_bn=c;
        after_cp=b;
    }

    Connect(after_ap, a);
    Connect(b, after_bn);
    Connect(after_cp, c);
    Connect(d, after_dn);
}

int main() {
    int n;
    cin >> n;
    // 노드 생성
    for(int i=1; i<=n; ++i){
        // 구조체 생성자로 Node 생성
        nodes[i]= new Node(i);
    }
    // 노드 연결
    for(int i=1; i<n; ++i){
        Connect(nodes[i], nodes[i+1]);
    }

    int q;
    cin >> q;
    // q번의 연산
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        // a, b, c, d 순서대로 배열에 들어가있다.
        SwapRange(nodes[a], nodes[b], nodes[c], nodes[d]);
    }


    // 1부터 거슬러올라가면서 head 찾기
    Node *cur = nodes[1];
    while(nullptr != cur->prev){
        cur=cur->prev;
    }
    // 최종 결과 출력
    while(nullptr != cur){
        cout << cur->id << " ";
        cur=cur->next;
    }
    return 0;
}