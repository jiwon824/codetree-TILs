#include <iostream>
using namespace std;

struct Node{
    string data;
    Node *prev, *next;

    Node(string data){
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

// 문자열 S_value를 값으로 가지는 새로운 단일 노드를 생성
// 이 단일 노드를 노드 cur의 앞에 삽입
void Func1(Node *curr, Node *node){
    node->prev = curr->prev;
    node->next = curr;
    
    if (nullptr != node->prev) (node->prev)->next = node;
    if (nullptr != node->next) (node->next)->prev = node;
}
// 문자열 S_value를 값으로 가지는 새로운 단일 노드를 생성
// 이 단일 노드를 노드 cur의 뒤에 삽입
void Func2(Node *curr, Node *node){
    // node뒤에 curr노드 연결
    node->prev = curr;
    node->next = curr->next;
    if (nullptr != node->prev) (node->prev)->next = node;
    if (nullptr != node->next) (node->next)->prev = node;
}
// 노드 cur의 이전 노드가 존재한다면, cur를 그 이전 노드로 변경
void Func3(Node *&curr){
    if(nullptr!=curr->prev) curr=curr->prev;
}
// 노드 cur의 다음 노드가 존재한다면, cur를 그 다음 노드로 변경
void Func4(Node *&curr){
    if(nullptr!=curr->next) curr=curr->next;
}

void PrintLinkedList(Node *s){
    if(nullptr==s->prev) cout << "(Null) ";
    else cout << (s->prev)->data << " ";

    cout << s->data << " ";

    if(nullptr==s->next) cout << "(Null) ";
    else cout << (s->next)->data << " ";
    cout << '\n';
}

int main() {
    string s_init; // 초기에 문자열 S_init를 값으로 가지는 단일 노드 cur
    cin >> s_init;
    Node *s = new Node(s_init);

    int n; // 총 연산 횟수 N 
    cin >> n;

    while(n--){
        int num;
        cin >> num;

        if(num==1){
            string s_value;
            cin >> s_value;
            Node *prevNode = new Node(s_value);
            Func1(s, prevNode);
        }
        else if(num==2){
            string s_value;
            cin >> s_value;
            Node *nextNode = new Node(s_value);
            Func2(s, nextNode);
        }
        else if(num==3){
            Func3(s);
        }
        else if(num==4){
            Func4(s);
        }   

        // 각 연산을 수행할 때마다 직후에,
        // 노드 cur의 이전 노드의 값, 노드 cur의 값, 노드 cur의 다음 노드의 값
        // 차례대로 한 줄에 출력
        PrintLinkedList(s);
    }
    return 0;
}