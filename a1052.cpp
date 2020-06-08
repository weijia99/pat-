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
//小心0这个，要特殊处理

using namespace std;
const long int maxn=100100;
const int inf=0x7fffffff;
int count1[maxn]={0};
struct node{
    int add,val,next;
}stu[maxn];
bool cmp(node a,node b){
    if (a.val!=b.val){
        return a.val<b.val;
    }
}
int main() {
    int n,head;
    cin>>n>>head;
    for (int i = 0; i < n; ++i) {
        int add,val,next;
        cin>>add>>val>>next;
        stu[add].add=add;
        stu[add].val=val;
        stu[add].next=next;
    }
    vector<node> vector;
  	int cnt=0;
    while (head!=-1){
        node cur=stu[head];
        vector.push_back(cur);
        head=cur.next;
      cnt++;
    }
  if(cnt==0){
    printf("0 -1");
    return 0;
  }
    sort(vector.begin(),vector.end(),cmp);
    head=vector[0].add;
    cout<<vector.size()<<" ";
    printf("%05d\n",head);
    for (int j = 1; j < vector.size(); ++j) {
        printf("%05d %d ",vector[j-1].add,vector[j-1].val);

            printf("%05d\n",vector[j].add);

    }
    printf("%05d %d -1\n",vector[vector.size()-1].add,vector[vector.size()-1].val);


    return 0;
}
