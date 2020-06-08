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
const long int maxn=100100;
const int inf=0x7fffffff;
struct node{
    string  name;
    int de,cai;
};

bool cmp(node a,node b){
    if ((a.de+a.cai)!=(b.de+b.cai)){
        return (a.de+a.cai)>(b.de+b.cai);
    } else if (a.de!=b.de){
        return a.de>b.de;
    } else if (a.name!= b.name){
        return a.name<b.name;
    }
}
int main() {
    int n,l,h;
    cin>>n>>l>>h;
    int num=n;
    vector<node> v[4];
    node stu;
    for (int i = 0; i < n; ++i) {
        string name;
        int de,cai;

        cin>>name>>de>>cai;
        stu.name=name;
        stu.cai=cai;
        stu.de=de;
        if (de<l||cai<l){
            num--;
        } else if (de>=h&&cai>=h){
            v[0].push_back(stu);
        } else if (de>=h&&cai<h){
            v[1].push_back(stu);
        } else if (de<h&&cai<h&&de>=cai){
            v[2].push_back(stu);
        } else{
            v[3].push_back(stu);
        }
    }
    cout<<num<<endl;
    for (int j = 0; j < 4; ++j) {
        sort(v[j].begin(),v[j].end(),cmp);
        for (int i = 0; i < v[j].size(); ++i) {
            cout<<v[j][i].name<<" "<<v[j][i].de<<" "<<v[j][i].cai<<endl;
        }
    }
    return 0;
}
