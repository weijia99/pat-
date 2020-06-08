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
const int maxn=1010;

int G[maxn][maxn];
bool visited[maxn];
int n;
//一共多少个,从1到n开始
void dfs(int v){
    visited[v]= true;
    for (int i = 1; i <=n; ++i) {
        if (G[v][i]==1&&!visited[i]){
            dfs(i);
        }
    }
}

int main() {
    int m,k;

//    fill(G[0],G[0]+maxn*maxn,0);
    cin>>n>>m>>k;
    for (int i = 0; i < m; ++i) {
        int p,q;
        cin>>p>>q;
        G[p][q]=G[q][p]=1;
    }
    for (int j = 0; j < k; ++j) {
        int p;
        cin>>p;
        fill(visited,visited+n+1,false);
//        重新设置
        visited[p]= true;
        int cnt=0;
//        设置已经访问过,相当于销毁了这座桥
        for (int i = 1; i <=n; ++i) {
            if (!visited[i]){
//                找出几个断层
                dfs(i);
                cnt++;
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
