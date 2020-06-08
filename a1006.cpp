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

//cin�ö��˳���

using namespace std;
const int maxn=100100;


struct node{
    string  name;
    int start;
    int end;
}stu[maxn];
bool cmp11(node a,node b){
    return a.start<b.start;
}
bool cmp12(node a,node b){
    return a.end>b.end;
}
int main() {
    int n;
    cin>>n ;
    for (int i = 0; i < n; ++i) {
        string name;
        int h1,h2,m1,m2,s1,s2;
        cin>>name;
        scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int start=h1*3600+m1*60+s1;
        int end=h2*3600+m2*60+s2;
        stu[i].name=name;
        stu[i].start=start;
        stu[i].end=end;
    }
    sort(stu,stu+n,cmp11);
    cout<<stu[0].name;
    sort(stu,stu+n,cmp12);
    cout<<" "<<stu[0].name;
    return 0;
}
