#include <iostream>
#include <algorithm>

using namespace std;
class Student{
    public:
        int num, h, w;
    Student(){};
    Student(int num, int h, int w){
        this->num = num;
        this->h = h;
        this->w = w;
    }

};

bool cmp(Student a, Student b){
    if(a.h==b.h) return a.w > b.w;
    return a.h < b.h;
}
int main() {
    int n;
    cin >> n;
    Student students[n];
    for(int i=0; i<n;i++){
        int h, w;
        cin >> h >> w;
        students[i]=Student(i+1, h, w);
    }

    sort(students, students+n, cmp);
    //각 학생의 키, 몸무게, 번호
    for(int i=0; i<n;i++){
        cout << students[i].h << " " << students[i].w << " "<< students[i].num << '\n';
    }
    return 0;
}