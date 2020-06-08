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

bool visited1[maxn]={false};
int G[maxn][maxn]={0};
int n;
void dfs1(int v){
    visited1[v]= true;
    for (int i = 1; i <=n; ++i) {
        if (G[v][i]==1&&!visited1[i]){
            dfs1(i);
        }
    }
}
bool visited2[maxn]={false};
int max_height=0;
vector<int> ve;
//int height=0;
void dfs2(int v,int height){
//    首先标记访问,回溯
    visited2[v]= true;

    if (height>max_height){
        ve.clear();
//        清空这个队列
        ve.push_back(v);
        max_height=height;
    } else if (height==max_height){
        ve.push_back(v);
    }

    for (int i = 1; i <=n; ++i) {
        if (G[v][i]==1&&!visited2[i]){
            dfs2(i,height+1);
        }
    }
//    跳出
//    height--;
//    visited2[v];
}
int main() {

    cin>>n;

    int a,b;

    set<int> set;
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b;
        G[a][b]=G[b][a]=1;
    }
//    找出联通分量
    int flag=0;
    int s1=0;
    for (int j = 1; j <=n; ++j) {
        if (!visited1[j]){
            flag++;
            dfs1(j);
            dfs2(j,1);
            s1=ve[0];
            for (int i = 0; i < ve.size(); ++i) {
                set.insert(ve[i]);
            }
        }
    }
    if (flag>1){
        printf("Error: %d components",flag);
    } else{
        fill(visited2,visited2+maxn,false);
        ve.clear();
        dfs2(s1,1);
        for (int i = 0; i < ve.size(); ++i) {
//            printf("%d ",ve[i]);
            set.insert(ve[i]);
        }
        for(auto item=set.begin();item!= set.end();item++){
            printf("%d\n",*item);
        }
    }
    return 0;
}
