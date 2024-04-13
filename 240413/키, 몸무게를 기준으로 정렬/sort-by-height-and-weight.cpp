#include <iostream>
#include <algorithm>

using namespace std;
class Student{
    public:
        string name;
        int h, w;
    Student(){};
    Student(string name, int h, int w){
        this->name = name;
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
    for(int i=0; i<n; i++){
        string name;
        int h, w;
        cin >> name >> h >> w;
        students[i]= Student(name, h, w);
    }
    sort(students, students+n, cmp);
    for(int i=0; i<n; i++){
        cout << students[i].name << " " << students[i].h << " " << students[i].w << '\n';
    }
    return 0;
}