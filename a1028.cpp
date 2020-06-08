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

//段错误,有可能是id用的string太长
using namespace std;
const int maxn=10010;
struct node{
    string  id,name;
    int grade;
}stu[maxn];
bool cmp11(node a,node b){
    if (a.id!=b.id){
        return a.id< b.id;
    }
}
bool cmp12(node a,node b){
    if (a.name!= b.name){
        return a.name< b.name;
    }else{
        return a.id<b.id;
    }
}
bool cmp13(node a,node b){
    if (a.grade!=b.grade){
        return a.grade<b.grade;
    } else{
        return a.id<b.id;
    }
}
int main() {
    int n,d;
    cin>>n>>d;
    for (int i = 0; i < n; ++i) {
        string name,id;
        int grade;
        cin>>id>>name>>grade;
        stu[i].name=name;
        stu[i].id=id;
        stu[i].grade=grade;
    }
    if (d==1){
        sort(stu,stu+n,cmp11);
    } else if (d==2){
        sort(stu,stu+n,cmp12);
    } else{
        sort(stu,stu+n,cmp13);
    }
    for (int j = 0; j < n; ++j) {
        cout<<stu[j].id<<" "<<stu[j].name<<" "<<stu[j].grade<<endl;
    }
    return 0;
}
