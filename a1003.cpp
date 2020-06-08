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
const int maxn=100100;



int main() {
    int n,m,c1,c2;
    cin>>n>>m>>c1>>c2;
    int cost[n];
    int d[n];
    fill(d,d+n,maxn);
    bool visited[n];
    fill(visited,visited+n, false);
    int G[n][n];
    fill(G[0],G[0]+n*n,maxn);
    int ren[n];
    fill(ren,ren+n,0);
    for (int i = 0; i < n; ++i) {
        cin>>cost[i];
    }
    for (int j = 0; j < m; ++j) {
        int p,q,t;
        cin>>p>>q>>t;
        G[p][q]=G[q][p]=t;
    }
    d[c1]=0;
    int times[n];
    fill(times,times+n,0);
    times[c1]=1;
    ren[c1]=cost[c1];
    for (int k = 0; k < n; ++k) {
//        寻找最短的点
        int less=-1;
        int min=maxn;
//        首先找到最小编
        for (int i = 0; i < n; ++i) {
            if (d[i]<min&&!visited[i]){
                less=i;
                min=d[i];
            }
        }
//        没找到直接返回
        if (less==-1){
            return 0;
        }
        visited[less]= true;
//        通过这个最短点找与他相连的其他点，通过这个桥梁更新距离
        for (int j = 0; j < n; ++j) {
            if (!visited[j]&&G[less][j]!=maxn){
                if (d[less]+G[less][j]<d[j]){
                    d[j]=d[less]+G[less][j];
                    ren[j]=cost[j]+ren[less];
                    times[j]=times[less];
                }else if (d[less]+G[less][j]==d[j]){
                    if (cost[j]+ren[less]>ren[j]){
                        ren[j]=cost[j]+ren[less];
                    }
                    times[j]+=times[less];
//
                }
            }

        }
    }

    cout<<times[c2]<<" "<<ren[c2];
    return 0;
}
