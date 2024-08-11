#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

void connect(Node *a, Node *b) {
    // nullptr은 false이기 때문에 a라고 적어도 됨
    if (a) a->next = b;
    if (b) b->prev = a;
}

void swapSegments(Node *&head, Node *aStart, Node *bEnd, Node *cStart, Node *dEnd) {
    Node *aPrev = aStart->prev;
    Node *bNext = bEnd->next;
    Node *cPrev = cStart->prev;
    Node *dNext = dEnd->next;

    // 헤드 노드 처리
    if (aStart == head) head = cStart;
    else if (cStart == head) head = aStart;

    // 스왑 실행
    connect(aPrev, cStart);
    connect(dEnd, bNext);
    connect(cPrev, aStart);
    connect(bEnd, dNext);

    // 특수 케이스: 두 세그먼트가 인접한 경우
    if (bNext == cStart) {
        connect(dEnd, aStart);
    } else if (dNext == aStart) {
        connect(bEnd, cStart);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Node*> nodes(n + 1);
    unordered_map<int, Node*> nodeMap;
    Node* head = nullptr;
    Node* tail = nullptr;

    // 노드 생성 및 연결
    for (int i=1; i<=n; ++i) {
        nodes[i] = new Node(i);
        nodeMap[i] = nodes[i];
        if (i==1){
            head = nodes[i];
        }
        else{
            connect(nodes[i-1], nodes[i]);
        }
        tail = nodes[i];
    }

    // 연산 처리
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        Node *aStart = nodeMap[a];
        Node *bEnd = nodeMap[b];
        Node *cStart = nodeMap[c];
        Node *dEnd = nodeMap[d];

        swapSegments(head, aStart, bEnd, cStart, dEnd);
    }

    // 결과 출력
    Node *current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // 메모리 해제
    for (int i = 1; i <= n; ++i) {
        delete nodes[i];
    }

    return 0;
}