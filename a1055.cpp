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
int count1[maxn]={0};
struct node{
    string  name;
    int age,money;
}stu[maxn];
bool cmp(node a,node b){
    if (a.money!=b.money){
        return a.money>b.money;
    } else if (a.age!=b.age){
        return a.age<b.age;
    } else if (a.name!= b.name){
        return a.name<b.name;
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        string name;
        int age,money;
        cin>>name>>age>>money;
        stu[i].name=name;
        stu[i].age=age;
        stu[i].money=money;
    }
    sort(stu,stu+n,cmp);
//   过滤年龄超过100个人数的
    int hash[201]={0};
    vector<node> vector;
    for (int j = 0; j < n; ++j) {
        if (hash[stu[j].age]<=100){
            vector.push_back(stu[j]);
            hash[stu[j].age]++;
        }
    }
    for (int k = 0; k < m; ++k) {
        int num,amin,amax;
        cin>>num>>amin>>amax;
        printf("Case #%d:\n",k+1);
        int temp=0;
        for (int i = 0; i < vector.size()&&temp<num; ++i) {
            if (vector[i].age>=amin&&vector[i].age<=amax){


                    cout<<vector[i].name<<" "<<vector[i].age<<" "<<vector[i].money<<endl;
                    temp++;

            }
        }
        if (temp==0){
            cout<<"None"<<endl;
        }
    }
    return 0;
}
