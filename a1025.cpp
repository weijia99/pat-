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
const int maxn=10010;

struct node{
    string  name;
    int grade;
    int inRank;
    int outRank;
    int group;
}stu[maxn];

bool cmp(node a,node b){
    if (a.grade!=b.grade){
        return a.grade>b.grade;
    } else{
        return a.name<b.name;
    }
}
int index1[maxn];
int main() {
    int n;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        int d;
        cin>>d;
        if (i==0){
            index1[i]=d;

        } else{
            index1[i]=d+index1[i-1];
//划分区段
        }
        for (int j = 0; j < d; ++j) {
            string name;
            int grade;
            cin>>name>>grade;
            if (i==0){
                stu[j].name=name;
                stu[j].grade=grade;
                stu[j].group=i+1;
            } else{
                stu[j+index1[i-1]].name=name;
                stu[j+index1[i-1]].grade=grade;
                stu[j+index1[i-1]].group=i+1;
            }

        }


    }
//    分段排序
    for (int k = 0; k < n; ++k) {
        int p,q;
        if (k==0){
            sort(stu,stu+index1[k],cmp);
            p=0,q=index1[k];
        } else{
            sort(stu+index1[k-1],stu+index1[k],cmp);
            p=index1[k-1],q=index1[k];
        }
        stu[p].inRank=1;
        for (int i = p+1; i < q; ++i) {
            if (stu[i].grade==stu[i-1].grade){
                stu[i].inRank=stu[i-1].inRank;
            } else{
                stu[i].inRank=i-p+1;
            }
        }
    }
    sort(stu,stu+index1[n-1],cmp);
    stu[0].outRank=1;
    for (int i = 1; i < index1[n-1]; ++i) {
        if (stu[i].grade==stu[i-1].grade){
            stu[i].outRank=stu[i-1].outRank;
        } else{
            stu[i].outRank=i+1;
        }
    }
    cout<<index1[n-1]<<endl;
    for (int l = 0; l < index1[n-1]; ++l) {
        cout<<stu[l].name<<" "<<stu[l].outRank<<" "<<stu[l].group<<" "<<stu[l].inRank<<endl;
    }

    return 0;
}
