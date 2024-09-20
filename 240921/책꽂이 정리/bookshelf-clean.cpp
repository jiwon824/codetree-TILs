#include <iostream>
#include <tuple>
using namespace std;

const int MAX_N = 250000;
const int MAX_K = 101;

struct Node {
    int id;
    Node *prev, *next;

    Node(int id) : id(id), prev(nullptr), next(nullptr) {}
};

Node *nodes[MAX_N];
tuple<int, Node*, Node*> bookshelves[MAX_K];// {size, head, tail}

void Connect(Node *s, Node *e) {
    // s와 e를 이어줌
    if (nullptr != s) s->next = e;
    if (nullptr != e) e->prev = s;
}

/**
 * 1 i j : i번 책꽂이의 맨 앞 책을 j번 책꽂이의 맨 뒤에 꽂습니다.
 * i번 책꽂이에 책이 아무것도 없다면, 무시합니다.
 */
void Func1(int a, int b){

    int aSize, bSize;
    Node *aHead, *aTail, *bHead, *bTail;
    tie(aSize, aHead, aTail) = bookshelves[a];
    tie(bSize, bHead, bTail) = bookshelves[b];

    if (aSize==0) return;

    if(a==b){
        Connect(aTail, aHead);
        bookshelves[a] = {aSize, aHead->next, aHead};
    }
    else{
        // a의 첫 번째 책을 b의 마지막 다음에 연결
        Connect(bTail, aHead);

        // 바뀐 정보 갱신
        bookshelves[a] = {aSize-1, aHead->next, aTail};
        if(bSize==0) bookshelves[b] = {bSize+1, aHead, aHead};
        else bookshelves[b] = {bSize+1, bHead, aHead};
    }

    // 연결 끊기
    if (nullptr!=aHead->next) {
        aHead->next->prev = nullptr;
        aHead->next = nullptr;
    }
}
/**
 * 2 i j : i번 책꽂이의 맨 뒷 책을 j번 책꽂이의 맨 앞에 꽂습니다.
 * i번 책꽂이에 책이 아무것도 없다면, 무시합니다.
 */
void Func2(int a, int b){
    int aSize, bSize;
    Node *aHead, *aTail, *bHead, *bTail;
    tie(aSize, aHead, aTail) = bookshelves[a];
    tie(bSize, bHead, bTail) = bookshelves[b];

    if (aSize==0) return;
    if(a==b){
        Connect(aTail, aHead);
        bookshelves[a] = {aSize, aTail, aTail->prev};
    }
    else{
        // a의 마지막 책을 b의 맨 앞에 연결
        Connect(aTail, bHead);

        // 바뀐 정보 갱신
        bookshelves[a]={aSize-1, aHead, aTail->prev};
        if(bSize==0) bookshelves[b] = {bSize+1, aTail, aTail};
        else bookshelves[b]={bSize+1, aTail, bTail};
    }
    
    // 연결 끊기
    if(nullptr!=aTail->prev) {
        aTail->prev->next=nullptr;
        aTail->prev=nullptr;
    }
}
/**
 * 3 i j : i번 책꽂이의 책을 모두 j번 책꽂이의 맨 앞으로 옮깁니다. 
 * 각 책꽂이에 책이 꽃혀 있던 순서는 유지되어야 합니다.
 */
void Func3(int a, int b){
    int aSize, bSize;
    Node *aHead, *aTail, *bHead, *bTail;
    tie(aSize, aHead, aTail) = bookshelves[a];
    tie(bSize, bHead, bTail) = bookshelves[b];

    if (aSize==0 || a==b) return;

    Connect(aTail, bHead);

    // 바뀐 정보 갱신
    bookshelves[a]={0, nullptr, nullptr};
    if(bSize==0) bookshelves[b] = {aSize, aHead, aTail};
    else bookshelves[b]={bSize+aSize, aHead, bTail};
}
/**
 * 4 i j : i번 책꽂이의 책을 모두 j번 책꽂이의 맨 뒤로 옮깁니다. 
 * 각 책꽂이에 책이 꽃혀 있던 순서는 유지되어야 합니다.
 */
void Func4(int a, int b){
    int aSize, bSize;
    Node *aHead, *aTail, *bHead, *bTail;
    tie(aSize, aHead, aTail) = bookshelves[a];
    tie(bSize, bHead, bTail) = bookshelves[b];

    if (aSize==0 || a==b) return;

    Connect(bTail, aHead);

    // 바뀐 정보 갱신
    bookshelves[a]={0, nullptr, nullptr};
    if(bSize==0) bookshelves[b] = {aSize, aHead, aTail};
    else bookshelves[b]={bSize+aSize, bHead, aTail};
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
    // 처음에 N 개의 책은 번호 순서대로 모두 1번 책꽂이에 꽂혀 있습니다.
    // 1번 책꽂이 정보={n개의 책, 맨 앞의 책, 맨 뒤의 책}
    bookshelves[1]={n, nodes[1], nodes[n]};

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
        int size;
        Node *cur;
        tie(size, cur, ignore) = bookshelves[i];

        cout << size << " ";
        while(size--){
            cout << cur->id << " ";
            cur = cur->next;
        }
        cout <<'\n';
    }
    return 0;
}