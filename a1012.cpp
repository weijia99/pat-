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
    int id;
    int c,m,e,sum;
    int rank[4];
    char name;
}stu[maxn];

bool cmp11(node a,node b){
    return a.sum>b.sum;
}
bool cmp12(node a,node b){
    return a.c>b.c;
}
bool cmp13(node a,node b){
    return a.m>b.m;
}
bool cmp14(node a,node b){
    return a.e>b.e;
}

int main() {
    int n,m;
    cin>>n>>m;
    int id,c,math,e,sum;
    for (int i = 0; i < n; ++i) {
        cin>>id>>c>>math>>e;
        sum=c+math+e;
        stu[i].id=id;
        stu[i].c=c;
        stu[i].m=math;
        stu[i].e=e;
        stu[i].sum=sum;
    }
//    先按中分排序
    sort(stu,stu+n,cmp11);
    stu[0].rank[0]=1;

    for (int j = 1; j < n; ++j) {
        if (stu[j].sum==stu[j-1].sum){
            stu[j].rank[0]=stu[j-1].rank[0];
        } else{
            stu[j].rank[0]=j+1;
        }

    }
//    按c开始
    sort(stu,stu+n,cmp12);

    stu[0].rank[1]=1;
    for (int j = 1; j < n; ++j) {
        if (stu[j].c==stu[j-1].c){

            stu[j].rank[1]=stu[j-1].rank[1];
        } else{
            stu[j].rank[1]=j+1;
        }

    }
//    m开始
    sort(stu,stu+n,cmp13);

    stu[0].rank[2]=1;
    for (int j = 1; j < n; ++j) {
        if (stu[j].m==stu[j-1].m){

            stu[j].rank[2]=stu[j-1].rank[2];
        } else{
            stu[j].rank[2]=j+1;
        }

    }
//    e开始
    sort(stu,stu+n,cmp14);

    stu[0].rank[3]=1;
    for (int j = 1; j < n; ++j) {
        if (stu[j].e==stu[j-1].e){

            stu[j].rank[3]=stu[j-1].rank[3];
        } else{
            stu[j].rank[3]=j+1;
        }

    }
    map<int  ,node > map1;
    for (int k = 0; k < n; ++k) {
        int id=stu[k].id;
        map1[id]=stu[k];
    }
    char ch[4]={'A','C','M','E'};
    for (int l = 0; l < m; ++l) {
        cin>>id;
        map<int, node>::iterator iterator = map1.find(id);
        if (iterator!=map1.end()){
            node a=iterator->second;
            int min=maxn;
            int flag=0;
            for (int i = 0; i < 4; ++i) {
                if (a.rank[i]<min){
                    min=a.rank[i];
                    flag=i;
                }
            }
            cout<<min<<" "<<ch[flag]<<endl;

        } else{
            cout<<"N/A"<<endl;
        }

    }

    return 0;
}
