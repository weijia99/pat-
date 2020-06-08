#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <set>
#include <stack>
#include <queue>

//cin用多了超市



using namespace std;
const long int maxn=10010;
const int inf=0x7fffffff;

struct node{
    string  name;
    string  id;
    int grade;
}stu[maxn];
bool cmp(node a,node b){
    if (a.grade!=b.grade){
        return a.grade>b.grade;
    }
}
int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string name,id;
        int grade;
        cin>>name>>id>>grade;
        stu[i].name=name;
        stu[i].id=id;
        stu[i].grade=grade;
    }
    sort(stu,stu+n,cmp);
    int count[11];
//    for (int j = 0; j < n; ++j) {
//        int shiwei=stu[j].grade/10;
//        count[shiwei]++;
//    }
    int amin,amax;
    cin>>amin>>amax;
//    int start=amin/10;
//    int end=amax/10;
    int flag=0;
    for (int j = 0; j < n; ++j) {
        if (stu[j].grade>=amin&&stu[j].grade<=amax){
            flag=1;
            cout<<stu[j].name<<" "<<stu[j].id<<endl;
        }
        if (stu[j].grade<amin){
            break;
        }
    }
    if (flag==0){
        cout<<"NONE";
    }
    return 0;
}
